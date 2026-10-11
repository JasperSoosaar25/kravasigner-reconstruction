# Further recovery audit: field types and structure

Continued on 11 October 2026, after the successful source build at `edad40232beca7ce0cd81363fc14812e0a8ca3b0` (run `38126989899`). This check compares the original supplied executable with the actual downloaded device product from that run. It does not label reference implementation code as recovered official source.

## What the additional check establishes

| Property | Independently observed result |
|---|---|
| Recovered app nominal descriptors | 106: 27 classes, 63 structs, 16 enums |
| Type kinds and complete descriptor flags | All 106 match |
| Reflection field/case records | All 462 names, order and flags match |
| Mutable-property flags | 302 records with flag 2 in both; other 160 records have flag 0 |
| Nonempty field-type references | All 380 normalized type references match |
| Empty type references | All 82 records match; included in the 462 record count, not counted as recovered concrete type strings |
| Recorded superclass types | All 13 nonempty references match; remaining absent references match |
| Unresolved references in this selected inventory | Zero in either executable |
| Other metadata records across all modules | The earlier bounded parser still reports 293 unparsed records |
| New app source mismatch | None found in this additional structural comparison |

The main executable SHA-256 values are original `b3376d32865ce970eefcfc061ad6750723fc01dd864c1da6bb7f415c1b9a45b3` and tested rebuild `59fc10f980bbc94b072ecdb70b75773adf8730aa602dcaed6ec29d0dd9dd931d`. `evidence/extended-swift-structure-comparison.json` contains both inventories and explicit comparison results. The original snapshot in `evidence/original-swift-structure.json` contains only normalized metadata, with no old executable or private signing values.

## Why this goes beyond the previous check

Matching a property name does not establish that its type or mutability matches. The earlier check compared type names and ordered field names only. The added `scripts/compare-swift-structure.py` also compares reflection kind, raw descriptor flags, field-record flags, normalized mangled type references and recorded superclass references.

The parser reads the thin little-endian device Mach-O without executing it. It checks bounds and known dyld chain locations before resolving indirect symbolic references. Both supplied files use chained-pointer format 6 and import format 1. Imported descriptor references are represented by import symbol and addend; direct references are represented by their context name and kind. Image addresses and chain link positions may change between builds and are not compared as source differences. Generic type operators remain encoded in their normalized type-expression tokens; this is not a full human-readable Swift demangler.

Three initially unsupported selected records involved a type declared in an extension and a private geometry class under an anonymous context. Extension targets are now normalized through their referenced mangled type. Anonymous contexts without a recorded name use an explicit anonymous marker. That marker does not recover an original file identity or prove that every unnamed lexical scope is equivalent. Recursive references and unsupported forms are reported rather than treated as agreement.

## Negative checks with real binary data

`tests/SwiftStructureNegativeChecks.py` reads the original owner IPA and changes bytes only in memory. Modified binaries are neither saved nor executed.

| Fixture | Actual checker result |
|---|---|
| Unchanged original compared with itself | Pass |
| Clear the mutable-property flag on Download._progress | Reject: one field-flag difference |
| Redirect Download.id's type reference from String to Bool, retaining its name | Reject: one field-type difference; the earlier names-only inventory remains identical |
| Change an indirect symbolic type reference to an unsupported form | Reject through explicit unresolved-reference status; it cannot silently count as a match |

The results are retained in `evidence/swift-structure-negative-checks.json`. Structural source validation also cross-checks the new original snapshot against the earlier independent 106-descriptor inventory, all 462 name/flag pairs, and the original executable digest. The device workflow includes the stronger compiled-product check and retains its JSON output. Its next actual run must pass before that new workflow step is described as CI-verified.

## Repeat locally

```bash
python3 scripts/compare-swift-structure.py /path/to/KravaSigner.ipa \
  /path/to/device/KravaSigner --output /tmp/swift-structure-comparison.json

python3 tests/SwiftStructureNegativeChecks.py /path/to/KravaSigner.ipa \
  --output /tmp/swift-structure-negative-checks.json
```

The first argument also accepts a thin original executable or the normalized original JSON snapshot. CI uses the snapshot and a newly compiled executable, so the original machine code never becomes a build input.

## Primary references and limits

- [Swift 6.2 reflection records](https://github.com/swiftlang/swift/blob/swift-6.2-RELEASE/include/swift/RemoteInspection/Records.h): stored-property/enum-case records, mutable and indirect-case flags, and superclass references.
- [Swift mangling ABI](https://github.com/swiftlang/swift/blob/main/docs/ABI/Mangling.rst): embedded symbolic references can contain zero bytes; direct/indirect context references and alignment padding require explicit handling.
- [Swift 6.2 context descriptors](https://github.com/swiftlang/swift/blob/swift-6.2-RELEASE/include/swift/ABI/Metadata.h): extension and anonymous contexts, including optionally recorded anonymous names.
- [Apple dyld chained-fixup definitions](https://github.com/apple-oss-distributions/dyld/blob/main/include/mach-o/fixup-chains.h): pointer-chain layouts, import tables, bind addends and image-offset rebases.

These definitions guide the parser; the counts and comparison outcomes come from the owner's files. The checker supports the formats observed here and deliberately rejects unsupported ones. It does not infer source expressions from metadata, recover implementation bodies, prove every UI screen or signing path, or reduce the existing whole-program unknowns to zero. No original official source release has been obtained through this continuation. The app implementation remains the previously documented reconstruction.
