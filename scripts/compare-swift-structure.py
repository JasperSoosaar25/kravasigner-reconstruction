#!/usr/bin/env python3
"""Compare bounded Swift reflection structure in two thin device Mach-O files.

Resolves local nominal references and imported descriptors using verified dyld
chain locations. Never executes either executable. Unsupported references are
reported explicitly and cannot count as successful type comparisons.
"""
import argparse
import collections
import hashlib
import json
import runpy
import struct
import zipfile
from pathlib import Path


class MachO:
    def __init__(self, data):
        if data[:4] != b'\xcf\xfa\xed\xfe':
            raise ValueError('Expected thin little-endian 64-bit Mach-O')
        self.data = data
        self.sections, self.segments, self.fixups = [], [], {}
        self.active_mangled = set()
        fixup_payload = None
        position = 32
        for _ in range(self.unpack('<I', 16)[0]):
            command, size = self.unpack('<II', position)
            if size < 8 or position + size > len(data):
                raise ValueError('Invalid load-command bounds')
            if command == 0x19:
                name, address, length, file_offset, file_length = self.unpack(
                    '<16sQQQQ', position + 8)
                self.segments.append((name.rstrip(b'\0').decode(), address,
                                      length, file_offset, file_length))
                count = self.unpack('<I', position + 64)[0]
                if 72 + count * 80 > size:
                    raise ValueError('Invalid segment section count')
                for index in range(count):
                    record = position + 72 + index * 80
                    name, _, address, length, file_offset = self.unpack(
                        '<16s16sQQI', record)
                    flags = self.unpack('<I', record + 64)[0]
                    if flags & 255 not in (1, 12, 18):
                        self.sections.append((name.rstrip(b'\0').decode(),
                                              address, length, file_offset))
            elif command == 0x80000034:
                fixup_payload = self.unpack('<II', position + 8)
            position += size
        self.image_base = next(address for name, address, _, offset, _
                               in self.segments if name == '__TEXT' and offset == 0)
        if fixup_payload:
            self.read_fixups(*fixup_payload)

    def unpack(self, pattern, offset):
        size = struct.calcsize(pattern)
        if offset < 0 or offset + size > len(self.data):
            raise ValueError('Read outside executable')
        return struct.unpack_from(pattern, self.data, offset)

    def offset(self, address, size=1):
        for _, base, length, file_offset in self.sections:
            if base <= address and address + size <= base + length:
                result = file_offset + address - base
                if result + size <= len(self.data):
                    return result
        raise ValueError('Address outside file-backed sections')

    def read(self, pattern, address):
        return self.unpack(pattern, self.offset(address, struct.calcsize(pattern)))

    def relative(self, address):
        value = self.read('<i', address)[0]
        return address + value if value else 0

    def string(self, address):
        result = bytearray()
        for index in range(1024):
            value = self.read('<B', address + index)[0]
            if not value:
                return result.decode()
            result.append(value)
        raise ValueError('Unterminated context name')

    def read_fixups(self, start, size):
        end = start + size
        if end > len(self.data):
            raise ValueError('Invalid fixups payload')

        def get(pattern, offset):
            if offset < start or offset + struct.calcsize(pattern) > end:
                raise ValueError('Read outside fixups payload')
            return self.unpack(pattern, offset)

        version, starts, imports, symbols, count, import_format, symbol_format = get('<7I', start)
        if version != 0 or import_format != 1 or symbol_format != 0:
            raise ValueError('Unsupported fixups/import/symbol format')
        imported = []
        for index in range(count):
            entry = get('<I', start + imports + index * 4)[0]
            name_offset = start + symbols + (entry >> 9)
            terminator = self.data.find(b'\0', name_offset, end)
            if not start <= name_offset < end or terminator < 0:
                raise ValueError('Invalid import name')
            imported.append(self.data[name_offset:terminator].decode())
        starts += start
        segment_count = get('<I', starts)[0]
        if segment_count != len(self.segments):
            raise ValueError('Fixup segment count differs')
        for segment_index in range(segment_count):
            relative = get('<I', starts + 4 + segment_index * 4)[0]
            if not relative:
                continue
            info = starts + relative
            info_size, page_size, pointer_format, segment_offset, _, page_count = get('<IHHQIH', info)
            if pointer_format != 6 or info_size < 22 + 2 * page_count:
                raise ValueError('Unsupported chain pointer format or bounds')
            if info + info_size > end or page_size not in (4096, 16384):
                raise ValueError('Invalid chain-starts bounds')
            _, segment_address, segment_length, _, _ = self.segments[segment_index]
            if segment_address != self.image_base + segment_offset:
                raise ValueError('Fixup segment address differs')
            for page in range(page_count):
                first = get('<H', info + 22 + page * 2)[0]
                if first == 0xffff:
                    continue
                if first & 0x8000:
                    raise ValueError('Unsupported multiple-chain page')
                address = segment_address + page * page_size + first
                page_end = min(segment_address + (page + 1) * page_size,
                               segment_address + segment_length)
                visited = set()
                while True:
                    if address in visited or address + 8 > page_end:
                        raise ValueError('Invalid fixup chain')
                    visited.add(address)
                    value = self.read('<Q', address)[0]
                    if value >> 63:
                        ordinal = value & 0xffffff
                        addend = (value >> 24) & 255
                        if ordinal >= count:
                            raise ValueError('Invalid bind ordinal')
                        self.fixups[address] = {'import': imported[ordinal],
                                                'addend': addend}
                    else:
                        target = self.image_base + (value & ((1 << 36) - 1))
                        high8 = (value >> 36) & 255
                        self.fixups[address] = target | (high8 << 56)
                    next_delta = (value >> 51) & 4095
                    if not next_delta:
                        break
                    address += next_delta * 4

    def context(self, address, visited=None):
        visited = set() if visited is None else visited
        if not address:
            return ''
        if address in visited or len(visited) > 32:
            raise ValueError('Invalid context chain')
        visited.add(address)
        flags = self.read('<I', address)[0]
        kind = flags & 31
        if kind not in (0, 1, 2, 3, 16, 17, 18):
            raise ValueError('Unsupported referenced context kind')
        parent_value = self.read('<i', address + 4)[0]
        parent = address + 4 + (parent_value & ~1) if parent_value else 0
        if parent_value & 1:
            parent = self.fixups.get(parent, self.read('<Q', parent)[0])
            if isinstance(parent, dict):
                raise ValueError('Imported parent context')
        if kind == 1:
            name = '<extension:' + json.dumps(self.mangled(self.relative(address + 8)),
                                               sort_keys=True, separators=(',', ':')) + '>'
        elif kind == 2:
            if flags >> 16:
                raise ValueError('Unsupported named anonymous context')
            name = '<anonymous>'
        else:
            name = self.string(self.relative(address + 8))
        return '.'.join(filter(None, (self.context(parent, visited), name)))

    def mangled(self, address):
        if not address:
            return None
        if address in self.active_mangled or len(self.active_mangled) >= 32:
            raise ValueError('Recursive symbolic type reference')
        self.active_mangled.add(address)
        try:
            return self.mangled_contents(address)
        finally:
            self.active_mangled.remove(address)

    def mangled_contents(self, address):
        pieces, text = [], bytearray()
        position = address
        for _ in range(4096):
            value = self.read('<B', position)[0]
            if value == 0:
                if text:
                    pieces.append(text.decode('ascii'))
                return pieces
            if value == 255:
                position += 1
                continue
            if 1 <= value <= 31:
                if text:
                    pieces.append(text.decode('ascii'))
                    text.clear()
                if value not in (1, 2):
                    raise ValueError('Unsupported symbolic reference kind ' + str(value))
                # Relative payload starts after the control byte, even when
                # its embedded bytes contain zeroes.
                target = position + 1 + self.read('<i', position + 1)[0]
                if value == 2:
                    if target not in self.fixups:
                        raise ValueError('Indirect reference outside known fixup chain')
                    target = self.fixups[target]
                if isinstance(target, dict):
                    pieces.append(target)
                else:
                    pieces.append({'context': self.context(target),
                                   'kind': self.read('<I', target)[0] & 31})
                position += 5
            else:
                text.append(value)
                position += 1
        raise ValueError('Unterminated mangled type')


def inspect_structure(data):
    base_inspect = runpy.run_path(str(Path(__file__).with_name('inspect-swift-metadata.py')))['inspect']
    base = base_inspect(data)
    image = MachO(data)
    rows, unresolved = [], []
    for row in base['app_types']:
        address = int(row['descriptor'], 16)
        flags = image.read('<I', address)[0]
        field_descriptor = image.relative(address + 16)
        item = {'name': row['name'], 'kind': flags & 31,
                'descriptor_flags': flags, 'field_descriptor_kind': None,
                'superclass_type': None, 'fields': []}
        if field_descriptor:
            field_kind, record_size, count = image.read('<HHI', field_descriptor + 8)
            if record_size < 12 or count != len(row['fields']):
                raise ValueError('Reflection record layout differs')
            item['field_descriptor_kind'] = field_kind
            super_address = image.relative(field_descriptor + 4)
            try:
                item['superclass_type'] = image.mangled(super_address)
            except ValueError as error:
                unresolved.append({'type': row['name'], 'field': '<superclass>', 'error': str(error)})
            for index, name in enumerate(row['fields']):
                record = field_descriptor + 16 + index * record_size
                field = {'name': name, 'flags': image.read('<I', record)[0],
                         'type': None, 'type_resolved': True}
                try:
                    field['type'] = image.mangled(image.relative(record + 4))
                except (ValueError, UnicodeDecodeError) as error:
                    field['type_resolved'] = False
                    unresolved.append({'type': row['name'], 'field': name, 'error': str(error)})
                item['fields'].append(field)
        rows.append(item)
    return {'executable_sha256': hashlib.sha256(data).hexdigest(),
            'app_types': rows, 'unresolved_type_references': unresolved,
            'unparsed_all_modules': base['unparsed_all_modules'],
            'fixup_locations_parsed': len(image.fixups)}


def compare(original, rebuilt):
    if not original['app_types'] or not rebuilt['app_types']:
        raise ValueError('Empty recovered app type inventory')
    differences = []
    original_rows = {row['name']: row for row in original['app_types']}
    rebuilt_rows = {row['name']: row for row in rebuilt['app_types']}
    compared_fields = 0
    for name in sorted(original_rows.keys() | rebuilt_rows.keys()):
        a, b = original_rows.get(name), rebuilt_rows.get(name)
        if a is None or b is None:
            differences.append({'name': name, 'area': 'type_presence'})
            continue
        for key in ('kind', 'descriptor_flags', 'field_descriptor_kind', 'superclass_type'):
            if a[key] != b[key]:
                differences.append({'name': name, 'area': key, 'original': a[key], 'rebuilt': b[key]})
        if [f['name'] for f in a['fields']] != [f['name'] for f in b['fields']]:
            differences.append({'name': name, 'area': 'field_names'})
            continue
        for x, y in zip(a['fields'], b['fields']):
            if x['flags'] != y['flags']:
                differences.append({'name': name, 'field': x['name'], 'area': 'field_flags',
                                    'original': x['flags'], 'rebuilt': y['flags']})
            if x['type_resolved'] and y['type_resolved']:
                compared_fields += 1
                if x['type'] != y['type']:
                    differences.append({'name': name, 'field': x['name'], 'area': 'field_type',
                                        'original': x['type'], 'rebuilt': y['type']})
    unresolved = len(original['unresolved_type_references']) + len(rebuilt['unresolved_type_references'])
    return {'original': original, 'rebuilt': rebuilt, 'differences': differences,
            'app_types_compared': len(original_rows.keys() & rebuilt_rows.keys()),
            'field_type_records_compared': compared_fields,
            'difference_counts': dict(collections.Counter(d['area'] for d in differences)),
            'unresolved_type_references_count': unresolved,
            'passed': not differences and not unresolved,
            'limit': 'Bounded reflection structure only. No method bodies, whole-program equivalence or original authored source recovered.'}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('original', type=Path,
                        help='Original IPA, thin executable, or prepared original-structure JSON')
    parser.add_argument('rebuilt', type=Path)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    if args.original.suffix == '.json':
        original = json.loads(args.original.read_text())
    elif zipfile.is_zipfile(args.original):
        with zipfile.ZipFile(args.original) as archive:
            original = inspect_structure(archive.read('Payload/KravaSigner.app/KravaSigner'))
    else:
        original = inspect_structure(args.original.read_bytes())
    result = compare(original, inspect_structure(args.rebuilt.read_bytes()))
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2) + '\n')
    print(f"Compared {result['app_types_compared']} app types and {result['field_type_records_compared']} field-type records")
    print(f"{len(result['differences'])} structural differences; {result['unresolved_type_references_count']} unresolved type references")
    if not result['passed']:
        print(json.dumps(result['differences'], indent=2))
        raise SystemExit(1)
    print('PASS type kinds, descriptor flags, field flags/types and superclass references match')


if __name__ == '__main__':
    main()
