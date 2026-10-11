#!/usr/bin/env python3
from pathlib import Path
import hashlib,json,plistlib,sys

root=Path(__file__).resolve().parents[1]
app=Path(sys.argv[1]); platform=sys.argv[2]
info=plistlib.loads((app/'Info.plist').read_bytes())
expected={'CFBundleIdentifier':'com.kravasign.KravaSigner','CFBundleExecutable':'KravaSigner','CFBundleDisplayName':'KravaSigner','CFBundleShortVersionString':'2.8.2','CFBundleVersion':'1'}
for key,value in expected.items():
    if info.get(key)!=value:raise SystemExit(f'{key}: expected {value!r}, got {info.get(key)!r}')
if not (app/'KravaSigner').is_file():raise SystemExit('Compiled executable missing')
manifest=json.loads((root/'docs/recovered-resources.json').read_text())
restored=0
for entry in manifest:
    name=entry.get('built_path')
    if name is None:continue
    if not (app/name).is_file():raise SystemExit(f'Recovered resource missing: {name}')
    if hashlib.sha256((app/name).read_bytes()).hexdigest()!=entry['sha256']:
        raise SystemExit(f'Recovered resource differs: {name}')
    restored+=1
if platform=='device' and 'iPhoneOS' not in info.get('CFBundleSupportedPlatforms',[]):raise SystemExit('Wrong device platform')
if platform=='simulator' and 'iPhoneSimulator' not in info.get('CFBundleSupportedPlatforms',[]):raise SystemExit('Wrong simulator platform')
print(f'PASS built app identity, {platform} platform and all {restored} exact recovered resources')
