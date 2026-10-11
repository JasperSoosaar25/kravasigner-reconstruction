#!/usr/bin/env python3
"""Structural validation. This does not claim Xcode typechecking/build success."""
from pathlib import Path
import hashlib,json,plistlib,re,subprocess,sys,xml.etree.ElementTree as ET

root=Path(__file__).resolve().parents[1]
def require(condition,message):
    if not condition:raise SystemExit(message)
info=plistlib.loads((root/'Feather/Resources/Info.plist').read_bytes())
schemes=info['CFBundleURLTypes'][0]['CFBundleURLSchemes']
require(schemes==['kravasigner'],'Incorrect declared URL scheme')
for entry in info['UTExportedTypeDeclarations']:
    require(entry['UTTypeIdentifier'].startswith('com.kravasign.KravaSigner.'),'Incorrect document UTI')
for path in root.rglob('*.plist'):
    plistlib.loads(path.read_bytes())
for path in root.rglob('*.json'):
    json.loads(path.read_text())
for path in root.rglob('*.xcstrings'):
    json.loads(path.read_text())
ET.parse(root/'Feather.xcodeproj/xcshareddata/xcschemes/Feather.xcscheme')
ET.parse(root/'Feather.xcworkspace/contents.xcworkspacedata')
project=(root/'Feather.xcodeproj/project.pbxproj').read_text()
require(project.count('PRODUCT_NAME = KravaSigner;')==2,'Product name differs')
require(project.count('SWIFT_MODULE_NAME = KravaSigner;')==2,'Swift module name differs')
require('AppleTVOS18.2.sdk' not in project,'Stale SDK reference')
config=(root/'Feather.xcconfig').read_text()
require('FEATHER_PRODUCT_BUNDLE_IDENTIFIER=com.kravasign.KravaSigner' in config,'Bundle ID differs')
require('FEATHER_PROJECT_VERSION=2.8.2' in config,'Version differs')
app=(root/'Feather/FeatherApp.swift').read_text()
require('url.scheme == "kravasigner"' in app,'Handler scheme differs')
require('https://www.kravasign.com/local.crt' in app and 'https://www.kravasign.com/local.pem' in app,'Launch TLS URLs missing')
require('?? "#f97316"' in app,'Default window tint differs from original executable')
require('= "#f97316"' in (root/'Feather/Views/Common/FRAppIconView.swift').read_text(),'Icon tint default differs')
require('return "local.kravasign.com"' in (root/'Feather/Backend/Server/ServerInstaller+TLS.swift').read_text(),'TLS domain differs')
for path in [root/'Makefile',root/'Feather/Utilities/FR.swift',root/'Feather/Views/Settings/Installation/Server & SSL/ServerView.swift']:
    require('backloop.dev/pack.json' not in path.read_text(),f'Upstream TLS service remains in {path.name}')
for path in root.rglob('*'):
    if path.is_file() and not any(x in path.parts for x in ['private-signing-assets','.git','DerivedData-device','DerivedData-simulator','SourcePackages']):
        require(path.suffix not in ['.p12','.mobileprovision','.ipa'],f'Private/binary app input in source: {path.relative_to(root)}')
manifest=json.loads((root/'docs/recovered-resources.json').read_text())
tracked=set(subprocess.check_output(['git','ls-files'],cwd=root,text=True).splitlines()) if (root/'.git').exists() else None
for row in manifest:
    data=(root/row['path']).read_bytes()
    require(hashlib.sha256(data).hexdigest()==row['sha256'],f'Recovered bytes changed: {row["path"]}')
    if tracked is not None:require(row['path'] in tracked,f'Recovered file missing from git: {row["path"]}')
coverage=json.loads((root/'docs/ipa-file-coverage.json').read_text())
require(len(coverage['entries'])==coverage['zip_entries']==135,'Original archive coverage incomplete')
require(len({x['ipa_path'] for x in coverage['entries']})==135,'Duplicate archive entry in coverage')
require(len(manifest)==87,'Original resource/reference inventory incomplete')
require(sum(bool(x.get('built_path')) for x in manifest)==66,'Resource restoration inventory incomplete')
structure=json.loads((root/'docs/evidence/original-swift-structure.json').read_text())
earlier_types=json.loads((root/'docs/evidence/swift-types.json').read_text())['types']
original_executable=next(row for row in coverage['entries'] if row['ipa_path']=='Payload/KravaSigner.app/KravaSigner')
require(structure['executable_sha256']==original_executable['sha256'],'Original structure evidence identifies another executable')
require(not structure['unresolved_type_references'],'Original structure evidence contains unresolved field types')
require(len(structure['app_types'])==106 and sum(len(t['fields']) for t in structure['app_types'])==462,'Original structure evidence is incomplete')
prior_by_name={t['name']:t for t in earlier_types}
require({t['name'] for t in structure['app_types']}==set(prior_by_name),'Original structure type names disagree with earlier evidence')
for row in structure['app_types']:
    old=prior_by_name[row['name']]
    require(row['kind']=={'class':16,'struct':17,'enum':18}[old['kind']] and row['descriptor_flags']==int(old['flags'],16),'Original descriptor kind/flags disagree')
    require([(f['name'],f['flags']) for f in row['fields']]==[(f['name'],f['flags']) for f in old['fields']],'Original field names/flags disagree')
require(not any(p.is_file() for p in (root/'RecoveredResources/Bundle').rglob('_CodeSignature/*')),'Original code signature retained in build resources')
for row in coverage['entries']:
    if row['disposition']=='private-input':
        require(row['source_path'] is None and row['sha256'] is None,'Private input exported or fingerprinted')
localizations=json.loads((root/'docs/evidence/localization-audit.json').read_text())
catalog=json.loads((root/'Feather/Resources/Localizable.xcstrings').read_text())
for locale in localizations:
    for entry in locale['missing_keys']+locale['changed_values']:
        require(catalog['strings'][entry['key']]['localizations'][locale['locale']]['stringUnit']['value']==entry['original'],'Recovered translation differs')
pins=[root/'Feather.xcworkspace/xcshareddata/swiftpm/Package.resolved',root/'Feather.xcodeproj/project.xcworkspace/xcshareddata/swiftpm/Package.resolved']
require(pins[0].read_bytes()==pins[1].read_bytes(),'Project/workspace dependency lockfiles diverge')
require(len(json.loads(pins[0].read_text())['pins'])>20,'Dependency lock incomplete')
for path in ['Zsign/src/zsign.mm','IDeviceKitten/Package.swift','NimbleKit/Package.swift','AltSourceKit/Package.swift','scripts/build.sh','scripts/simulator-smoke.sh','.github/workflows/reconstruct.yml']:
    require((root/path).is_file(),f'Missing build input: {path}')
print('PASS metadata, URL handler, TLS wiring, lockfiles and recovered resource hashes')
print('PASS credential exclusion and self-contained local package inputs')
print('PASS orange theme, recovered translations and all 135 archive entries accounted for')
print('PASS original structure evidence: 106 descriptors and 462 reflection records')
print('Structural checks passed; Xcode compilation is a separate check.')
