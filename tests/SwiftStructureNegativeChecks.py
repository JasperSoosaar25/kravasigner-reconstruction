#!/usr/bin/env python3
"""Verify the extended checker against deliberate changes in the owner binary.

Reads an original IPA/executable; mutations exist only in memory and are never
executed or saved. A type-pointer change keeps field names intact, demonstrating
that the extended check catches a difference the earlier names-only check misses.
"""
import argparse
import hashlib
import json
import runpy
import struct
import zipfile
from pathlib import Path


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('original', type=Path)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    root = Path(__file__).resolve().parents[1]
    tools = runpy.run_path(str(root / 'scripts/compare-swift-structure.py'))
    if zipfile.is_zipfile(args.original):
        with zipfile.ZipFile(args.original) as archive:
            data = archive.read('Payload/KravaSigner.app/KravaSigner')
    else:
        data = args.original.read_bytes()
    inspect, compare = tools['inspect_structure'], tools['compare']
    baseline = inspect(data)
    image = tools['MachO'](data)
    old_inspect = runpy.run_path(str(root / 'scripts/inspect-swift-metadata.py'))['inspect']
    download = next(row for row in old_inspect(data)['app_types']
                    if row['name'] == 'KravaSigner.Download')
    descriptor = image.relative(int(download['descriptor'], 16) + 16)
    record_size = image.read('<H', descriptor + 10)[0]
    records = {name: descriptor + 16 + index * record_size
               for index, name in enumerate(download['fields'])}
    results = []
    assert compare(baseline, inspect(data))['passed']
    results.append({'check': 'unchanged-original baseline', 'passed': True})

    mutable = bytearray(data)
    offset = image.offset(records['_progress'])
    struct.pack_into('<I', mutable, offset, image.read('<I', records['_progress'])[0] ^ 2)
    checked = compare(baseline, inspect(bytes(mutable)))
    assert not checked['passed'] and checked['difference_counts'] == {'field_flags': 1}
    results.append({'check': 'mutable field flag changed', 'passed': True,
                    'detected': checked['difference_counts']})

    mutable = bytearray(data)
    boolean_type = image.relative(records['onlyArchiving'] + 4)
    pointer = records['id'] + 4
    struct.pack_into('<i', mutable, image.offset(pointer), boolean_type - pointer)
    checked = compare(baseline, inspect(bytes(mutable)))
    assert not checked['passed'] and checked['difference_counts'] == {'field_type': 1}
    # The names-only checker still sees precisely the same fields.
    assert old_inspect(data)['app_types'] == old_inspect(bytes(mutable))['app_types']
    results.append({'check': 'id field type changed from String to Bool without renaming it',
                    'passed': True, 'detected': checked['difference_counts'],
                    'earlier_names_only_check_would_detect': False})

    mutable = bytearray(data)
    type_address = image.relative(records['url'] + 4)
    assert image.read('<B', type_address)[0] == 2
    mutable[image.offset(type_address)] = 9
    checked = compare(baseline, inspect(bytes(mutable)))
    assert not checked['passed'] and checked['unresolved_type_references_count'] > 0
    results.append({'check': 'unsupported symbolic type reference cannot silently pass',
                    'passed': True, 'unresolved_references_detected':
                    checked['unresolved_type_references_count']})
    result = {'original_executable_sha256': hashlib.sha256(data).hexdigest(),
              'checks': results, 'passed': all(row['passed'] for row in results),
              'limit': 'Negative checker validation, not execution or behavior tests of the app.'}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2) + '\n')
    for row in results:
        print('PASS ' + row['check'])


if __name__ == '__main__':
    main()
