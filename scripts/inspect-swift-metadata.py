#!/usr/bin/env python3
"""Inspect bounded Swift nominal names/fields; optionally compare original evidence.

Supports the supplied little-endian ARM64 Mach-O and rebuilt device executable.
It does not decompile method bodies. Unparsed dependency records are reported.
"""
import argparse
import json
import struct
from pathlib import Path


def inspect(data, module='KravaSigner'):
    if data[:4] != b'\xcf\xfa\xed\xfe':
        raise ValueError('Expected a thin little-endian 64-bit Mach-O')
    sections, position = [], 32
    for _ in range(struct.unpack_from('<I', data, 16)[0]):
        command, size = struct.unpack_from('<II', data, position)
        if size < 8 or position + size > len(data):
            raise ValueError('Invalid Mach-O load command')
        if command == 0x19:
            for index in range(struct.unpack_from('<I', data, position + 64)[0]):
                offset = position + 72 + 80 * index
                name, _, address, length, file_offset = struct.unpack_from('<16s16sQQI', data, offset)
                sections.append((name.rstrip(b'\0').decode(), address, length, file_offset))
        position += size

    def offset(address):
        for _, base, length, file_offset in sections:
            if base <= address < base + length:
                return file_offset + address - base
        raise ValueError('Unmapped address')

    def uint32(address):
        return struct.unpack_from('<I', data, offset(address))[0]

    def relative(address, indirect=False):
        value = struct.unpack_from('<i', data, offset(address))[0]
        if not value:
            return 0
        destination = address + (value & ~1 if indirect else value)
        if indirect and value & 1:
            destination = struct.unpack_from('<Q', data, offset(destination))[0] & 0x0000ffffffffffff
        return destination

    def string(address):
        start = offset(address)
        end = data.find(b'\0', start, start + 1024)
        if end < 0:
            raise ValueError('No string terminator')
        return data[start:end].decode()

    def context(address, seen=None):
        if not address:
            return ''
        seen = set() if seen is None else seen
        if address in seen or len(seen) > 32:
            raise ValueError('Invalid context chain')
        seen.add(address)
        kind = uint32(address) & 31
        parent = context(relative(address + 4, True), seen)
        name = string(relative(address + 8)) if kind in (0, 3, 16, 17, 18) else f'<context:{kind}>'
        return '.'.join(filter(None, (parent, name)))

    rows, unparsed, records = {}, 0, 0
    for name, address, length, file_offset in sections:
        if name not in ('__swift5_types', '__swift5_types2'):
            continue
        for delta in range(0, length, 4):
            records += 1
            try:
                entry = address + delta
                value = struct.unpack_from('<i', data, file_offset + delta)[0]
                target = entry + (value & ~3)
                if value & 3 == 1:
                    target = struct.unpack_from('<Q', data, offset(target))[0] & 0x0000ffffffffffff
                elif value & 3 != 0:
                    raise ValueError('Other type record kind')
                full_name = context(target)
                if not full_name.startswith(module + '.'):
                    continue
                fields, field_metadata = [], relative(target + 16)
                if field_metadata:
                    record_size = struct.unpack_from('<H', data, offset(field_metadata) + 10)[0]
                    count = uint32(field_metadata + 12)
                    if count > 1000 or record_size < 12:
                        raise ValueError('Invalid field records')
                    for index in range(count):
                        fields.append(string(relative(field_metadata + 16 + index * record_size + 8)))
                rows[full_name] = {'name': full_name, 'descriptor': hex(target), 'fields': fields}
            except (ValueError, UnicodeDecodeError, struct.error, RecursionError):
                unparsed += 1
    return {'app_types': list(rows.values()), 'type_table_records': records,
            'unparsed_all_modules': unparsed,
            'limit': 'Bounded metadata names/fields only; not original expressions, method bodies or whole-program equivalence.'}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('executable', type=Path)
    parser.add_argument('--reference', type=Path)
    parser.add_argument('--output', type=Path)
    args = parser.parse_args()
    result = inspect(args.executable.read_bytes())
    mismatches = []
    if args.reference:
        reference = json.loads(args.reference.read_text())
        expected = {row['name']: [field['name'] if isinstance(field, dict) else field
                    for field in row.get('fields', [])]
                    for row in reference.get('types', reference.get('app_types', []))}
        actual = {row['name']: row['fields'] for row in result['app_types']}
        for name in sorted(expected.keys() | actual.keys()):
            if expected.get(name) != actual.get(name):
                mismatches.append({'name': name, 'original_fields': expected.get(name),
                                   'rebuilt_fields': actual.get(name)})
        result.update(reference_app_type_count=len(expected), mismatches=mismatches,
                      metadata_names_and_fields_match_original=not mismatches)
    if args.output:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(json.dumps(result, indent=2) + '\n')
    print(f"Recovered {len(result['app_types'])} app descriptors; {result['unparsed_all_modules']} records unparsed across all modules.")
    if mismatches:
        print(json.dumps(mismatches, indent=2))
        raise SystemExit(1)
    if args.reference:
        print('PASS all recovered original app type names and stored-field names match')


if __name__ == '__main__':
    main()
