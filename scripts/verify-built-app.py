#!/usr/bin/env python3
from pathlib import Path
import argparse,hashlib,json,plistlib,re

root=Path(__file__).resolve().parents[1]
parser=argparse.ArgumentParser(description='Verify a source-built app or exact recovery baseline.')
parser.add_argument('app',type=Path)
parser.add_argument('platform',choices=['device','simulator'])
parser.add_argument('--mode',choices=['baseline','development'],default='baseline')
args=parser.parse_args()
app=args.app; platform=args.platform
info=plistlib.loads((app/'Info.plist').read_bytes())
expected={'CFBundleIdentifier':'com.kravasign.KravaSigner','CFBundleExecutable':'KravaSigner','CFBundleDisplayName':'KravaSigner','CFBundleShortVersionString':'2.8.2','CFBundleVersion':'1'}
if args.mode=='baseline':
    for key,value in expected.items():
        if info.get(key)!=value:raise SystemExit(f'{key}: expected {value!r}, got {info.get(key)!r}')
else:
    for key in expected:
        if not isinstance(info.get(key),str) or not info[key]:raise SystemExit(f'Missing app identity: {key}')
    if not re.fullmatch(r'[A-Za-z0-9_.-]+',info['CFBundleExecutable']):raise SystemExit('Invalid executable name')
if not (app/info['CFBundleExecutable']).is_file():raise SystemExit('Compiled executable missing')
manifest=json.loads((root/'docs/recovered-resources.json').read_text())
restored=0
for entry in manifest:
    if args.mode!='baseline':break
    name=entry.get('built_path')
    if name is None:continue
    if not (app/name).is_file():raise SystemExit(f'Recovered resource missing: {name}')
    if hashlib.sha256((app/name).read_bytes()).hexdigest()!=entry['sha256']:
        raise SystemExit(f'Recovered resource differs: {name}')
    restored+=1
if platform=='device' and 'iPhoneOS' not in info.get('CFBundleSupportedPlatforms',[]):raise SystemExit('Wrong device platform')
if platform=='simulator' and 'iPhoneSimulator' not in info.get('CFBundleSupportedPlatforms',[]):raise SystemExit('Wrong simulator platform')
if args.mode=='baseline':
    print(f'PASS built app identity, {platform} platform and all {restored} exact recovered resources')
else:
    print(f'PASS development app identity, executable and {platform} platform; editable resources retained')
