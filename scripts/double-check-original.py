#!/usr/bin/env python3
"""Independently compare the owner IPA, recovered files and downloaded build ZIPs.

Reports exact path/byte coverage without exporting signing inputs or executables.
Passing archive coverage is not proof of full original-source recovery.
"""
import argparse
import collections
import hashlib
import io
import json
import plistlib
import zipfile
from pathlib import Path


def sha256(data):
    return hashlib.sha256(data).hexdigest()


def check(ipa_path, repository, builds):
    manifest = json.loads((repository / 'docs/ipa-file-coverage.json').read_text())
    errors, result = [], {}
    with zipfile.ZipFile(ipa_path) as original:
        infos = original.infolist()
        names = [entry.filename for entry in infos]
        rows = manifest['entries']
        recorded = [row['ipa_path'] for row in rows]
        if len(names) != len(set(names)) or len(recorded) != len(set(recorded)):
            errors.append('Duplicate original ZIP names or coverage rows')
        if set(names) != set(recorded):
            errors.append({'unaccounted': sorted(set(names) - set(recorded)),
                           'invented': sorted(set(recorded) - set(names))})
        if original.testzip() is not None:
            errors.append('Original ZIP CRC failure')
        if sha256(ipa_path.read_bytes()) != manifest['ipa_sha256']:
            errors.append('Original IPA identity differs from the recorded input')
        file_sizes = {entry.filename: entry.file_size for entry in infos}
        preserved = 0
        for row in rows:
            name = row['ipa_path']
            if name not in file_sizes:
                continue
            if file_sizes[name] != row['size']:
                errors.append({'size_mismatch': name})
            if row['disposition'] == 'private-input':
                if row.get('source_path') or row.get('sha256'):
                    errors.append({'private_input_exposed_in_manifest': name})
                continue
            if row.get('sha256') and sha256(original.read(name)) != row['sha256']:
                errors.append({'original_digest_mismatch': name})
            if row.get('source_path'):
                destination = repository / row['source_path']
                if not destination.is_file() or destination.read_bytes() != original.read(name):
                    errors.append({'recovered_source_mismatch': name})
                else:
                    preserved += 1
        result['original_archive'] = {
            'sha256': sha256(ipa_path.read_bytes()), 'entries': len(names),
            'files': sum(not entry.is_dir() for entry in infos),
            'directories': sum(entry.is_dir() for entry in infos),
            'unaccounted_entries': sorted(set(names) - set(recorded)),
            'dispositions': dict(collections.Counter(row['disposition'] for row in rows)),
            'preserved_source_files_verified': preserved}
        prefix = 'Payload/KravaSigner.app/'
        original_paths = {name[len(prefix):] for name in names
                          if name.startswith(prefix) and not name.endswith('/')}
        original_info = plistlib.loads(original.read(prefix + 'Info.plist'))
        allowed_omissions = {row['ipa_path'][len(prefix):] for row in rows
                             if row['ipa_path'].startswith(prefix) and
                             row['disposition'] in ('private-input', 'replaced-signature')}
        result['builds'] = {}
        for platform, build_path in builds.items():
            with zipfile.ZipFile(build_path) as bundle:
                nested = None
                if platform == 'device':
                    candidates = [name for name in bundle.namelist() if name.endswith('.ipa')]
                    if len(candidates) != 1:
                        raise ValueError('Expected exactly one device IPA in artifact ZIP')
                    ipa_bytes = bundle.read(candidates[0])
                    nested = zipfile.ZipFile(io.BytesIO(ipa_bytes))
                    product, product_prefix = nested, prefix
                else:
                    product, product_prefix = bundle, 'DerivedData-simulator/Build/Products/Release-iphonesimulator/KravaSigner.app/'
                try:
                    product_names = product.namelist()
                    paths = {name[len(product_prefix):] for name in product_names
                             if name.startswith(product_prefix) and not name.endswith('/')}
                    exact_resources, missing_resources, changed_resources = 0, [], []
                    for row in rows:
                        if row['disposition'] != 'preserved-resource':
                            continue
                        path = row['built_path']
                        if product_prefix + path not in product_names:
                            missing_resources.append(path)
                        elif product.read(product_prefix + path) != original.read(row['ipa_path']):
                            changed_resources.append(path)
                        else:
                            exact_resources += 1
                    omitted, added = sorted(original_paths - paths), sorted(paths - original_paths)
                    unexplained = sorted(set(omitted) - allowed_omissions)
                    if missing_resources or changed_resources or unexplained or added:
                        errors.append({'platform': platform, 'missing_resources': missing_resources,
                                       'changed_resources': changed_resources,
                                       'unexplained_omissions': unexplained, 'added_paths': added})
                    info = plistlib.loads(product.read(product_prefix + 'Info.plist'))
                    changed_info = sorted(key for key in original_info.keys() | info.keys()
                                          if original_info.get(key) != info.get(key))
                    item = {'artifact_sha256': sha256(build_path.read_bytes()),
                            'exact_original_runtime_resources': exact_resources,
                            'missing_resources': missing_resources, 'changed_resources': changed_resources,
                            'added_app_file_paths': added, 'omitted_original_app_paths': omitted,
                            'unexplained_omissions': unexplained, 'changed_info_plist_keys': changed_info,
                            'main_executable_sha256': sha256(product.read(product_prefix + 'KravaSigner')),
                            'main_executable_differs_from_original': product.read(product_prefix + 'KravaSigner') != original.read(prefix + 'KravaSigner')}
                    if platform == 'device':
                        item['ipa_sha256'] = sha256(ipa_bytes)
                    result['builds'][platform] = item
                finally:
                    if nested:
                        nested.close()
    result.update(errors=errors, passed=not errors,
                  limit='Exact distributed-file coverage only; original private source, all behaviours and signing equivalence remain unproven.')
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('ipa', type=Path)
    parser.add_argument('--device-artifact', type=Path)
    parser.add_argument('--simulator-artifact', type=Path)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    root = Path(__file__).resolve().parents[1]
    builds = {key: value for key, value in {'device': args.device_artifact,
              'simulator': args.simulator_artifact}.items() if value}
    result = check(args.ipa, root, builds)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2) + '\n')
    print(f"{'PASS' if result['passed'] else 'FAIL'} {result['original_archive']['entries']} archive entries; {result['original_archive']['preserved_source_files_verified']} recovered source files compared directly")
    for platform, item in result['builds'].items():
        print(f"{platform}: {item['exact_original_runtime_resources']} original runtime files exact; {len(item['unexplained_omissions'])} unexplained omissions; {len(item['added_app_file_paths'])} added app paths")
    if result['errors']:
        print(json.dumps(result['errors'], indent=2))
        raise SystemExit(1)


if __name__ == '__main__':
    main()
