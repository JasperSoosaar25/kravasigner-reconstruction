#!/usr/bin/env python3
"""Regressions for contributor edits being overwritten or blocked by audit checks."""
import json
import os
from pathlib import Path
import plistlib
import shutil
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]


class BuildModesTests(unittest.TestCase):
    def test_development_keeps_edits_and_baseline_restores_original(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            original = root / 'RecoveredResources/Bundle'
            original.mkdir(parents=True)
            (original / 'Assets.car').write_bytes(b'original catalog')
            app = root / 'products/Test.app'
            app.mkdir(parents=True)
            (app / 'Assets.car').write_bytes(b'new contributor catalog')
            environment = dict(os.environ, SRCROOT=str(root), BUILT_PRODUCTS_DIR=str(app.parent),
                               CONTENTS_FOLDER_PATH=app.name, KRAVA_BUILD_MODE='development')
            command = ['bash', str(ROOT / 'scripts/restore-recovered-artwork.sh')]
            subprocess.run(command, env=environment, check=True, capture_output=True)
            self.assertEqual((app / 'Assets.car').read_bytes(), b'new contributor catalog')
            environment['KRAVA_BUILD_MODE'] = 'baseline'
            subprocess.run(command, env=environment, check=True, capture_output=True)
            self.assertEqual((app / 'Assets.car').read_bytes(), b'original catalog')
            environment['KRAVA_BUILD_MODE'] = 'typo'
            self.assertNotEqual(subprocess.run(command, env=environment, capture_output=True).returncode, 0)

    def test_development_accepts_new_version_but_checks_executable_and_platform(self):
        with tempfile.TemporaryDirectory() as directory:
            app = Path(directory) / 'Test.app'
            app.mkdir()
            info = {'CFBundleIdentifier': 'org.example.feature', 'CFBundleExecutable': 'KravaSigner',
                    'CFBundleDisplayName': 'My feature', 'CFBundleShortVersionString': '3.0',
                    'CFBundleVersion': '2', 'CFBundleSupportedPlatforms': ['iPhoneOS']}
            (app / 'Info.plist').write_bytes(plistlib.dumps(info))
            (app / 'KravaSigner').write_bytes(b'fixture executable, never run')
            command = ['python3', str(ROOT / 'scripts/verify-built-app.py'), str(app), 'device']
            self.assertEqual(subprocess.run(command + ['--mode', 'development'], capture_output=True).returncode, 0)
            self.assertNotEqual(subprocess.run(command + ['--mode', 'baseline'], capture_output=True).returncode, 0)
            self.assertNotEqual(subprocess.run(command[:-1] + ['simulator', '--mode', 'development'], capture_output=True).returncode, 0)
            (app / 'KravaSigner').unlink()
            self.assertNotEqual(subprocess.run(command + ['--mode', 'development'], capture_output=True).returncode, 0)

    def test_feature_edits_allowed_but_private_inputs_rejected(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory) / 'source'
            shutil.copytree(ROOT, root, ignore=shutil.ignore_patterns(
                '.git', 'artifacts', 'DerivedData*', 'SourcePackages', 'private-signing-*', '__pycache__', '.build'))
            app = root / 'Feather/FeatherApp.swift'
            app.write_text(app.read_text().replace('#f97316', '#00aaff'))
            catalog_path = root / 'Feather/Resources/Localizable.xcstrings'
            catalog = json.loads(catalog_path.read_text())
            audit = json.loads((root / 'docs/evidence/localization-audit.json').read_text())
            row = next(row for row in audit if row['missing_keys'] or row['changed_values'])
            entry = (row['missing_keys'] + row['changed_values'])[0]
            catalog['strings'][entry['key']]['localizations'][row['locale']]['stringUnit']['value'] = 'Contributor translation'
            catalog_path.write_text(json.dumps(catalog))
            (root / 'artifacts').mkdir(exist_ok=True)
            (root / 'artifacts/local.ipa').write_bytes(b'ignored build fixture')
            command = ['python3', str(root / 'scripts/validate-source.py')]
            result = subprocess.run(command + ['--mode', 'development'], capture_output=True, text=True)
            self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
            self.assertNotEqual(subprocess.run(command + ['--mode', 'baseline'], capture_output=True).returncode, 0)
            (root / 'do-not-commit.p12').write_bytes(b'invented credential fixture')
            result = subprocess.run(command + ['--mode', 'development'], capture_output=True, text=True)
            self.assertNotEqual(result.returncode, 0)
            self.assertIn('Private/binary app input', result.stdout + result.stderr)


if __name__ == '__main__':
    unittest.main(verbosity=2)
