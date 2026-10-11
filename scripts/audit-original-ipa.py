#!/usr/bin/env python3
"""Account for every ZIP entry and recover safe resources from the owner's IPA.

This never exports the old executables, signatures or signing credentials.
Their archive entries remain documented; this is not a source decompiler.
"""
from pathlib import Path, PurePosixPath
import argparse, collections, csv, hashlib, json, zipfile

root = Path(__file__).resolve().parents[1]
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('ipa', type=Path)
args = parser.parse_args()
prefix = 'Payload/KravaSigner.app/'
rows, resources = [], []
with zipfile.ZipFile(args.ipa) as archive:
    assert archive.testzip() is None, 'Corrupt ZIP entry'
    for item in archive.infolist():
        path = item.filename
        assert not PurePosixPath(path).is_absolute() and '..' not in PurePosixPath(path).parts
        row = {'ipa_path': path, 'size': item.file_size, 'sha256': None,
               'source_path': None, 'built_path': None, 'disposition': '', 'reason': ''}
        if item.is_dir():
            row.update(disposition='directory', reason='ZIP container; children individually accounted for')
        else:
            relative = path[len(prefix):] if path.startswith(prefix) else None
            if relative and (relative.startswith('signing-assets/') or relative == 'embedded.mobileprovision'):
                row.update(disposition='private-input', reason='Retained in owner IPA; never committed; optional local signing-assets importer covers the six defaults')
            else:
                data = archive.read(item)
                row['sha256'] = hashlib.sha256(data).hexdigest()
                if relative in ('KravaSigner', 'Frameworks/OpenSSL.framework/OpenSSL'):
                    row.update(disposition='rebuilt-executable', reason='Original machine code retained in owner IPA for analysis; new executable compiled from reconstructed/reference source or pinned platform framework')
                elif relative and '_CodeSignature' in PurePosixPath(relative).parts:
                    row.update(disposition='replaced-signature', reason='Original publisher signature cannot authenticate a new build; retained only in owner IPA')
                    stale = root/'RecoveredResources/Bundle'/relative
                    if stale.is_file(): stale.unlink()
                else:
                    if relative == 'Feather.xcconfig':
                        target = root/'Feather.xcconfig'; built = relative
                    elif relative == 'Info.plist' or (relative and (relative.startswith('Frameworks/') or '.bundle/' in relative) and relative.endswith('Info.plist')):
                        target = root/'RecoveredResources/Reference'/relative; built = None
                    elif relative:
                        target = root/'RecoveredResources/Bundle'/relative; built = relative
                    else:
                        target = root/'RecoveredResources/ArchiveMetadata'/path; built = None
                    target.parent.mkdir(parents=True, exist_ok=True)
                    target.write_bytes(data)
                    row.update(source_path=str(target.relative_to(root)), built_path=built,
                               disposition='preserved-resource' if built else 'preserved-reference',
                               reason='Exact distributed bytes restored after resource compilation' if built else 'Exact metadata retained; Xcode generates current platform Info.plists; AppleDouble sidecars do not belong in app')
                    resources.append({'path': row['source_path'], 'ipa_path': path,
                                      'sha256': row['sha256'], 'size': len(data), 'built_path': built,
                                      'kind': row['disposition']})
        rows.append(row)
summary = dict(collections.Counter(row['disposition'] for row in rows))
audit = {'ipa_sha256': hashlib.sha256(args.ipa.read_bytes()).hexdigest(),
         'zip_entries': len(rows), 'summary': summary, 'entries': rows}
(root/'docs/ipa-file-coverage.json').write_text(json.dumps(audit, indent=2)+'\n')
(root/'docs/recovered-resources.json').write_text(json.dumps(resources, indent=2)+'\n')
with (root/'docs/ipa-file-coverage.csv').open('w', newline='') as f:
    writer = csv.DictWriter(f, fieldnames=list(rows[0])); writer.writeheader(); writer.writerows(rows)
print(f'PASS all {len(rows)} archive entries accounted for: {summary}')
print(f'PASS {len(resources)} exact resource/reference files recovered; no credentials or old executable exported')
