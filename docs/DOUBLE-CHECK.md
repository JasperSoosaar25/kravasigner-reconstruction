# Independent completeness audit — 11 October 2026

The original IPA and both prior build packages were restored from saved copies,
then checked again independently. The entire current private source repository
was downloaded: **all 439 file bytes and modes matched** its authenticated
Git tree `36eadc34ce40dd2d6c74da17e377483c3d867f13` at commit
`f1ba72ad771acf223ab963ac74ef897b7bbb4048` before this follow-up's edits.

## What passed again

| Check | Fresh result |
|---|---|
| Original IPA identity and CRC | Recorded SHA-256 matches; no ZIP CRC errors |
| Archive paths | Exactly 135 entries: 98 files and 37 directories; no unaccounted, invented or duplicate paths |
| Preserved source material | All 87 resource/reference files compared directly with original ZIP bytes; zero differences |
| Prior device and simulator runtime resources | All 66 original files exact in each built app; zero missing or changed resources |
| Whole built-app file paths | No added app file paths; only seven private inputs and the unsigned main signature are absent |
| Original text keys | No original localized key missing from editable xcstrings |
| Device Info.plist semantics | Only four generated toolchain keys differ: DTPlatformBuild, DTSDKBuild, DTXcode, DTXcodeBuild |
| Simulator Info.plist | The same toolchain keys plus expected simulator platform/SDK and device capability differences |
| Recovered app metadata | Both original and prior rebuild contain all 106 recovered nominal type names; two field layouts required correction |
| Negative check | Audit rejects an intentionally omitted Settings resource; compiled metadata comparator rejects the two known prior-build field differences |

The prior compiled artifacts tested here belong to code commit
`90ba4ff66f784c1bad034b2b5976a70000078c75`, run `38102345171`.
`evidence/independent-archive-audit.json` records their results. This statement
does not silently transfer their successful build status to later source edits.

## Corrections found and made

1. The inherited recommended-repository list added three SourcesAddView fields
   absent from the original. Its URLs are absent as full strings in the original
   binary. The featured list, automatic recommendation fetch and their state
   have been removed; manual URL entry and repository import/export remain.
2. The inherited GitHub star prompt added SourcesView's `__shouldStar` field,
   absent from the original, with corresponding reference constants also absent.
   The prompt and its preference were removed.
3. Original signed entitlements were previously underdocumented. All 19 key
   names and value types are now inventoried without publishing identity-bound
   values. A local exporter preserves the exact dictionary privately. The
   minimal source template now matches the original false debugger flag.

The workflow adds a check of compiled type names and field names against the
original 106-descriptor evidence. The corrected device and simulator source builds both passed in [run 38126989899](https://github.com/JasperSoosaar25/kravasigner-reconstruction/actions/runs/38126989899) at commit `edad40232beca7ce0cd81363fc14812e0a8ca3b0`. The simulator installed and launched the new app (PID 15617), surviving the 10-second startup check. Its actual screenshot was inspected. Both downloaded products preserve all 66 original runtime resources with no unexplained omitted or added app files. The independently parsed new device executable matches all 106 recovered original app type names and their stored-field names; the CI check also passed. This is a bounded agreement check, not proof of original method-body or full UI equivalence. See `BUILD-RESULTS.md`, `evidence/corrected-build-audit.json` and `evidence/corrected-build-swift-metadata.json`.

## Exact accounting and limits

| Original archive category | Count | Handling |
|---|---:|---|
| Runtime resources | 66 | Exact original bytes in source and restored in products |
| Reference metadata, including AppleDouble sidecars | 21 | Exact original bytes retained for reference |
| Main executable and OpenSSL executable | 2 | Main app rebuilt from source; OpenSSL supplied from pinned platform framework |
| Private signing inputs | 7 | Retained in owner IPA; six defaults have an optional local importer |
| Original signatures | 2 | Accounted for; unsigned main signature absent, framework signature replaced |
| Directory entries | 37 | Every entry recorded; runtime directories created with their children |
| **Total** | **135** | **No unclassified entry in the supplied IPA** |

The original signed entitlements live inside the executable signature rather
than a separate ZIP file. Their full private values remain available in the
original IPA and through the local export script. Provisioning identity and
profile capabilities must match any later signing; an unsigned reconstruction
does not inherit the original signature's permissions automatically.

Four recovered Core Data classes are generated by Xcode from the model, so the
absence of four authored Swift files is expected. A resource bundle marker is
also present in both executables. Runtime-fetched TLS files and user-added remote
repository content are external inputs, not missing entries in this IPA.

**Complete archive accounting is not complete original source recovery.** No
official native source release was found in the bounded search. Original Swift
expressions/comments, all method and SwiftUI bodies, designer vectors/layers,
private history, exact transitive dependency choices and original authoring
signing configuration remain unavailable or uncertain. The metadata parser has
293 unparsed dependency/context records across all modules. The project remains
an unofficial reconstruction with documented reference code and recovered changes.

## Repeat the checks

```bash
python3 scripts/double-check-original.py /path/to/KravaSigner.ipa \
  --device-artifact /path/to/KravaSigner-device-build.zip \
  --simulator-artifact /path/to/KravaSigner-simulator-build.zip \
  --output /tmp/independent-archive-audit.json

python3 scripts/inspect-swift-metadata.py /path/to/device/KravaSigner \
  --reference docs/evidence/swift-types.json \
  --output /tmp/swift-metadata.json

python3 scripts/export-original-entitlements.py /path/to/KravaSigner.ipa
```

These scripts export no old executable as a source build input. The entitlement
export goes only to gitignored private-signing-metadata and is not applied to the
build automatically. It is observed signing output, not recovered authoring source.

## Fresh source-release research and dependency comparison

The follow-up checked the official KravaSign home/sign pages, two public search engines, and GitHub repository/code search. No verifiable official native source release for this supplied IPA was located. The official `/sign` page was a web signing/UDID flow; it did not expose this native project's source. Repository-name results led to this reconstruction and a third-party IPA listing. That listing has JSON/web/artwork files, not a Swift app project.

GitHub code search for the exact bundle identifier returned six diagnostic files in `Kurt-228/ios27-research`, not source. An inspected 2.8.2 report identifies executable UUID `56F2F58E-8C71-3656-94CD-4D58AF046B6D`, different from this IPA's `3E12A44C-0DDB-3186-950A-B7C3004900D4`. Search for the observed TLS/install hostname returned zero code results. Search for `kravasigner` in Swift returned two CoreSign/Portal fork header files whose subtitle strings mention the name; they are not verified official KravaSigner source. Search counts are observations at the time of this check, not proof that no inaccessible/unindexed source exists. `evidence/source-search-followup.json` records the bounded search and primary documentation links.

All 11 file-backed Mach-O sections in the original OpenSSL framework match those in the corrected device product, including the native machine-code section. Whole-file signatures differ. This supports the choice of that pinned prebuilt dependency; it does not recover or compile OpenSSL's original authoring source. See `evidence/openssl-code-comparison.json`.

Apple's [Core Data code-generation documentation](https://developer.apple.com/documentation/coredata/generating-code) explains why Class Definition produces managed-object classes without visible authored files. [TN2415](https://developer.apple.com/library/archive/technotes/tn2415/_index.html) and [TN2318](https://developer.apple.com/library/archive/technotes/tn2318/_index.html) distinguish project entitlements from provisioning/signing output. Swift's [ABI type-metadata documentation](https://github.com/swiftlang/swift/blob/main/docs/ABI/TypeMetadata.rst) provides the context for the bounded executable metadata comparison. These references do not turn recovered compiler metadata into original source bodies.

## Continued structural recovery

The subsequent audit in `EXTENDED-STRUCTURE.md` recovered and compared normalized field-type expressions as well as type/field flags and recorded superclass references. All 106 selected app descriptors and 462 reflection records agree. The complete reflection-name section across modules is byte-identical to the original. Run [38128927828](https://github.com/JasperSoosaar25/kravasigner-reconstruction/actions/runs/38128927828) passed both source builds, the stronger compiled-device comparison and simulator startup; its downloaded products again preserve all 66 runtime resources in each app with zero unexplained omissions or added file paths. The app implementation is unchanged by this further audit-tooling update.
