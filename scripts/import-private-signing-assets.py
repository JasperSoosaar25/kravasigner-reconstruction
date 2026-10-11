#!/usr/bin/env python3
"""Optional LOCAL import from your IPA; imported credentials stay gitignored."""
from pathlib import Path
import sys,zipfile

root=Path(__file__).resolve().parents[1]
if len(sys.argv)!=2:
    raise SystemExit('Usage: python3 scripts/import-private-signing-assets.py /path/to/KravaSigner.ipa')
destination=root/'private-signing-assets'
count=0
with zipfile.ZipFile(sys.argv[1]) as archive:
    for entry in archive.infolist():
        parts=Path(entry.filename).parts
        if len(parts)<5 or parts[:2]!=('Payload','KravaSigner.app') or parts[2]!='signing-assets' or entry.is_dir():continue
        relative=Path(*parts[3:])
        if relative.is_absolute() or '..' in relative.parts:raise SystemExit('Unsafe archive path')
        target=destination/relative
        target.parent.mkdir(parents=True,exist_ok=True)
        target.write_bytes(archive.read(entry))
        target.chmod(0o600)
        count+=1
if not count:raise SystemExit('No signing-assets folder found in that IPA')
print(f'Imported {count} private files locally. Their contents were not printed.')
