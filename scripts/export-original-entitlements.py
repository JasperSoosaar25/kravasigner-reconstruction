#!/usr/bin/env python3
"""Export observed signed entitlements locally; never print account-bound values.

These are signing outputs, not proof of the original authoring .entitlements file.
The build does not automatically apply them. A signing profile must permit them.
"""
import os
import plistlib
import struct
import sys
import zipfile
from pathlib import Path


def extract(data):
    if data[:4] != b'\xcf\xfa\xed\xfe':
        raise ValueError('Expected the original thin 64-bit Mach-O')
    position, signature = 32, None
    for _ in range(struct.unpack_from('<I', data, 16)[0]):
        command, size = struct.unpack_from('<II', data, position)
        if size < 8 or position + size > len(data):
            raise ValueError('Invalid Mach-O load command')
        if command == 0x1d:
            signature = struct.unpack_from('<II', data, position + 8)
        position += size
    if not signature:
        raise ValueError('No embedded code signature')
    start, size = signature
    if start + size > len(data):
        raise ValueError('Code signature exceeds executable')
    magic, length, count = struct.unpack_from('>III', data, start)
    if magic != 0xfade0cc0 or length > size or 12 + count * 8 > length:
        raise ValueError('Invalid code-signature SuperBlob')
    for index in range(count):
        _, relative = struct.unpack_from('>II', data, start + 12 + index * 8)
        if relative + 8 > length:
            raise ValueError('Invalid signature slot')
        blob_magic, blob_length = struct.unpack_from('>II', data, start + relative)
        if blob_length < 8 or relative + blob_length > length:
            raise ValueError('Invalid signature blob length')
        if blob_magic == 0xfade7171:
            result = plistlib.loads(data[start + relative + 8:start + relative + blob_length])
            if not isinstance(result, dict):
                raise ValueError('Entitlements must be a property-list dictionary')
            return result
    raise ValueError('No XML entitlement slot; this bounded exporter does not decode DER-only signatures')


def main():
    if len(sys.argv) != 2:
        raise SystemExit('Usage: python3 scripts/export-original-entitlements.py /path/to/KravaSigner.ipa')
    root = Path(__file__).resolve().parents[1]
    with zipfile.ZipFile(sys.argv[1]) as archive:
        entitlements = extract(archive.read('Payload/KravaSigner.app/KravaSigner'))
    directory = root / 'private-signing-metadata'
    directory.mkdir(mode=0o700, exist_ok=True)
    target = directory / 'OriginalSignedEntitlements.plist'
    descriptor = os.open(target, os.O_WRONLY | os.O_CREAT | os.O_TRUNC, 0o600)
    with os.fdopen(descriptor, 'wb') as stream:
        stream.write(plistlib.dumps(entitlements))
    target.chmod(0o600)
    print(f'Exported {len(entitlements)} original signed entitlement keys to gitignored private-signing-metadata/OriginalSignedEntitlements.plist. Values were not printed or applied to the build.')


if __name__ == '__main__':
    main()
