# Evidence for the reconstructed changes

Target: supplied `KravaSigner.ipa`, version 2.8.2/build 1, bundle ID `com.kravasign.KravaSigner`. Investigation date: 11 October 2026. The archive's publisher signature was not independently authenticated.

IPA SHA-256: `c155ad99e97bf8d65bee28df63076cffb6050c6fc142aa08255d2a1f243010e8`.

Executable SHA-256: `b3376d32865ce970eefcfc061ad6750723fc01dd864c1da6bb7f415c1b9a45b3`.

UUID: `3E12A44C-0DDB-3186-950A-B7C3004900D4`. ARM64 iOS-device Mach-O, `cryptid = 0`, iOS 16 minimum, iOS 26.0 SDK. There are 82,979 function starts across the app and its linked dependencies. Its symbol table retains native dependency symbols but lacks KravaSigner-specific function names. Static analysis is possible; original Swift text is not uniquely recoverable.

## Changes and confidence

| Reconstructed area | Evidence | Confidence / limit |
|---|---|---|
| Fully Local server host | Routine `0x1000150d0` returns the literal `local.kravasign.com` when server method is not 1. Method 1 preserves the local-IP/127.0.0.1 logic and `Feather.ipFix` preference. | High: the branch and returned constant are visible in assembly. |
| TLS certificate/key endpoints | Launch routine `0x1001049f0` and Settings button routine `0x100074ef8` capture `https://www.kravasign.com/local.crt` and `https://www.kravasign.com/local.pem`. | High: both URLs and both call sites traced. |
| Automatic launch refresh | The launch routine calls directory/cache/default-certificate setup, creates the two-URL task and returns true. Its completion target is an ignored-result callback. | High for initiating refresh at launch; remote service availability untested. |
| Direct two-request downloader | Async entry `0x100075588`, continuation `0x10003cc60`, and `0x10003cdc4` construct URL requests and call `URLSession.shared.data(for:delegate:)`. The IEEE-754 timeout immediate is `0x404e000000000000` = 60.0; cache policy is 1. | High for sequential downloads, 60-second timeout and reload-ignoring-local-cache policy. Original Swift organization/signature unknown. |
| Files, decoding and completion | `0x10003cf14` decodes the two results as strings, calls the same helper at `0x100119428` with small-string filenames `server.crt` then `server.pem`, and returns false on failed decoding/write. `0x10003d1e0` switches to the Main Actor for the success haptic; `0x10003d234` calls completion(true). Error continuations call completion(false). | High for these effects. Decompiled types/signatures are approximate; assembly corroborates literals and calls. |
| Removal of JSON TLS model | `ServerView` reflection fields contain `__ipFix`, `__serverMethod`, `_serverMethods`, `_dataService`, with no `_serverPackUrl`. No app `ServerPackModel`, `ServerPackInfo` or `Domains` descriptors were recovered. The direct downloader performs no JSON decode. | High for the directly traced downloader; metadata is supporting evidence, not complete proof of every absent declaration. |
| `kravasigner` deep-link handler | Handler `0x1000fd89c` compares URL.scheme against the two-word Swift small-string representation `0x676973617661726b` + `0xeb0000000072656e` = `kravasigner`. It retains import/export hosts and `/source/`, `/install/` routes. | High for scheme and routes. Ordinary raw string searches miss this inline immediate; the absence of a printable string alone would have been misleading. |
| Reduced Settings UI | `KravaSigner.SettingsView` has only selected-certificate and fetch-request fields. App metadata for AppearanceView, AppIconView, AboutView and SettingsDonationCellView was not recovered, and upstream donation/repository constants are absent. | Medium: removing the upstream appearance/icon/about/donation/feedback section fits these observations. Original view layout/body was not fully recovered. Certificates/features/directories/reset are retained from reference. |
| Cache namespace | Executable string `com.kravasign.KravaSigner.datacache` occurs at the cache-construction region. | High for the namespace literal; cache implementation remains the reference. |
| Version, identity and document types | Original Info.plist and recovered `Feather.xcconfig`. | High for observed values. Private project organization/build flags remain unknown. |
| Default accent | Five traced functions contain Swift small-string `#f97316`; `0x1000feda4` gets `Feather.userTintColor`, uses this fallback, converts it to UIColor and sets window tint. Four icon-view initializer specializations retain the same default. | High for orange default and saved-preference override; not a recovered designer palette file. |
| Artwork and resource coverage | All 135 ZIP entries accounted for; 87 resource/reference files preserved; 66 restored into the built app. Nine catalog bitmaps decoded with zero failures. | Exact distributed resources; decoded PNGs have newly generated compression/metadata. Original vector/layer designer files are unavailable. |
| Localizations | All 13 locales preserved, including stringsdict. Three reference-missing keys and 56 differing existing locale values restored in editable xcstrings. | Exact compiled text and plural resources; original translation editor history unknown. |

The custom Entitlements screen is absent in the release metadata, but the reference already enables it only under DEBUG/NIGHTLY. It was therefore **not** treated as a proven KravaSign-specific removal. Release builds keep it disabled by the existing compilation condition.

The independently written downloader guards invalid URL input instead of reproducing the binary's apparent forced unwrap. Its production callers use fixed valid URLs. The tests exercise this new helper; they do not authenticate or test the live service. No HTTP-status, PEM-content or certificate/key-pair validation was observed in the selected binary routine, so the reconstruction does not claim those checks. Each file write is atomic through the existing `FileManager.forceWrite`; the two-file pair is not a transaction.

## Reference and build choices

Feather tag `v2.8.2` resolves to commit `1a9b2bbcc7ebe0fbbf76fec45ec1e94ff0c4edc4`. Its version, data model, surviving file names, app structure, and six recorded dependency/tool versions agree with the supplied app. This is strong ancestry evidence, but it cannot identify KravaSign's exact private commit.

The reference project had two differing lockfiles: the standalone Xcode project and outer workspace disagreed on 11 transitive packages. This reconstruction uses the **project** lockfile in both locations. The reference workspace lock is retained in `upstream-workspace-Package.resolved.json`. The IPA records only six dependency/tool versions, which agree with both; the remaining original KravaSigner versions are unknown. This is a documented build choice, not a recovered original lockfile.

The source contains the pinned local Zsign and IDeviceKit packages. The IDevice v0.1.57 XCFramework download was checked against its manifest SHA-256 `40cd5c769b60d1879a96c9caa27666037f9d5321844addec40ae99727b142d10`; its Info.plist contains arm64-device and arm64/x86_64-simulator variants. That makes a simulator build plausible, but does not establish that the complete app compiles or runs there.

Necessary new build adaptations:

- Set the app product/display name and Swift module to KravaSigner while retaining the reference project/scheme names.
- Replace the stale Apple TV 18.2 MobileCoreServices framework reference with the selected SDK's framework path.
- Retain the recovered xcconfig byte-for-byte; override deployment-location behavior only in the build command so artifact paths are predictable.
- Replace upstream JSON/TLS-fetching Makefile steps with source-build commands. No Backloop assets are downloaded or packaged.
- Change the license-output prefix to the observed KravaSigner prefix. Restore the original Settings.bundle and distributed acknowledgements byte-for-byte. The earlier claim that Settings.bundle was absent was incorrect and is superseded by the full ZIP-entry audit.
- Restore all 66 recovered app resources in the final resource phase. Compiled artwork, launch NIBs and model files are acknowledged non-source inputs; editable raster assets and matching launch/model sources are also included.
- Export the two submodule trees directly; omit unrelated Windows prebuilt libraries. Their source revisions and licenses remain identified.
- Provide offline TLS tests, structural validators, unsigned-device packaging, simulator startup checks and pinned Actions implementations.

## Coverage and limitations

The custom metadata parser recovered 106 KravaSigner nominal descriptors and logged 293 unparsed records across all modules. Indirect/authenticated/external context pointers are not fully supported. It is a partial inventory. It was not used as the only evidence for the directly traced TLS and URL-handler changes.

Ghidra 12.1.4 imported the Mach-O using its AppleSilicon Swift compiler specification. Targeted routines and their async continuations were decompiled without a full whole-program analysis. The evidence folder includes 29 initial candidate routines, 8 continuation routines, 26 SSL-related candidate routines and the URL handler; some exports overlap. The pseudocode contains known warnings, unreliable variable types and incomplete indirect-call recovery. It is review evidence, **not compile-ready original code**.

The native signing/repository/import/database components remain mostly the matching reference implementation. Their complete KravaSigner-specific change set is unknown. The retained Core Data model name is Feather, matching the app. No byte-for-byte executable equivalence is promised; changed source organization, compiler decisions, dependency uncertainties and missing private signing inputs would prevent such a claim.

The uploaded app includes Development and Distribution signing-asset folders. The source archive excludes those private keys/profiles/passwords. The optional local import script lets the owner supply them from their own IPA. Without them, CI builds contain no bundled default signing certificates. Importing credentials later changes app contents and must precede appropriate signing.

## Primary research sources

- The supplied IPA, analyzed directly; exact bytes identified above.
- [Feather reference commit](https://github.com/claration/Feather/tree/1a9b2bbcc7ebe0fbbf76fec45ec1e94ff0c4edc4).
- [Swift type-metadata ABI](https://github.com/swiftlang/swift/blob/main/docs/ABI/TypeMetadata.rst) and [metadata definitions](https://github.com/swiftlang/swift/blob/main/include/swift/ABI/MetadataValues.h).
- [Ghidra 12.1.4 release](https://github.com/NationalSecurityAgency/ghidra/releases/tag/Ghidra_12.1.4_build) and its tagged README/JDK requirements.
- [Swift official Linux downloads](https://www.swift.org/install/linux/ubuntu/24_04/), used for local Swift 6.2 behavioral tests.
- [GitHub macOS 15 runner image](https://github.com/actions/runner-images/blob/main/images/macos/macos-15-Readme.md), inspected for Xcode 26.0.1 and iOS 26.0 SDK availability. Runner software can change; the workflow fails clearly if its selected Xcode is absent.
- [Apple Xcode requirements](https://developer.apple.com/xcode/system-requirements).
- [IDevice v0.1.57 release](https://github.com/jkcoxson/idevice/releases/tag/v0.1.57), whose downloaded framework checksum and platform slices were inspected.
- GitHub action refs inspected for [checkout](https://github.com/actions/checkout/tree/11d5960a326750d5838078e36cf38b85af677262) and [upload-artifact](https://github.com/actions/upload-artifact/tree/ea165f8d65b6e75b540449e92b4886f43607fa02).

Earlier source-availability research inspected the official KravaSign homepage, signing entry, terms and privacy pages; GitHub repository and code searches; and both available web-search engines. No verifiable public official KravaSigner native source release was found in the sources successfully inspected. That does not prove no private/unindexed source exists. No further email was sent to support.

## Follow-up theme and full-file audit

The second audit covers **all 135 ZIP entries: 98 files and 37 directory entries**. `ipa-file-coverage.json` and `.csv` list the original path, size, digest where appropriate, project path, build path and disposition. Summary: 66 preserved runtime resources, 21 preserved reference files, two rebuilt executables, seven private inputs, two replaced signatures and 37 directory entries. Private signing-input digests are deliberately not published. Nothing is silently left unclassified.

The theme fallback is **#f97316**, RGB **249, 115, 22**. `theme-references.json`, `theme-functions.asm` and `decompiled-theme.c` record the independently traced constants and preferences. The window and imported-app icon defaults have been changed accordingly. Standard system colours still adapt to iOS and saved `Feather.userInterfaceStyle`; no fixed background colour was inferred from icon pixels. Unreachable appearance views inherited from the reference also use the orange fallback; retaining those source files does not establish that the original release exposed them.

`carfile-go` v0.8.0 decoded the catalog after the Linux release SHA-256 was checked against both its release manifest and GitHub asset digest: `55b04e034489555aca0f24fa7152a57f7650df5be0149593409cefb2e382d9e0`. This checks transport integrity, not an independent attestation verification. The tool was used for analysis only and is not an app dependency. The catalog contains **11 renditions: nine bitmaps and two multisize descriptors**, across AppIcon, App_Unknown, Cert and Repositories. All nine physical bitmaps decoded; the paired iPhone/iPad light, dark and tinted icon images have identical RGBA pixels. Six unique editable raster images are included in the source catalog, with correct appearance entries; all nine decoded images and full descriptor metadata are retained separately. The original `Assets.car` remains the runtime authority, preserving its exact descriptors and compression.

NIBArchive 1.1.0 decoded both launch-screen NIBs. The observed image bounds are **155 × 105 points**, centred in a **393 × 852** view, with 31:21 aspect ratio, `labelColor` tint and `systemBackgroundColor`. The reference storyboard matches these observed geometric/system-colour properties. Both original NIBs and their Info.plist are retained and restored. They refer to **Glyph**, which has no corresponding facet in the original catalog. The build does not invent a new original Glyph resource; the reference editor-only Glyph remains available for storyboard compilation, then the original catalog is restored. Launch appearance and any missing-image effect require runtime verification.

The decoded Core Data model has Imported (7 attributes), AltSource (5), CertificatePair (8) and Signed (7). Names, types and optional flags match the editable model. The two optional inverse relationships are CertificatePair.signedApps (unbounded to-many) and Signed.certificate (maxCount 1), both Nullify deletion rule. Their observed schema matches the source. Original .mom/.omo/VersionInfo.plist files are restored to preserve distributed model hashes. This establishes schema compatibility, not complete recovery of storage logic.

The editable localization catalog now includes **Change Nickname**, **Less** and **Supports importing from Feather and ESign.** The import footer was corrected to the observed key. Existing text differs from the reference in Polish (1), Turkish (35) and Simplified Chinese (20) locale values; these are restored. All 20 plural keys across eight original stringsdict files match the editable reference variation values. All original Localizable.strings and Localizable.stringsdict files are additionally copied byte-for-byte at build time. The original document icon `feather_extension.png` is restored; its reference bytes did not match.

`Settings.bundle/Root.plist` and its English strings are present in the IPA and now restored. Its Acknowledgements child points to `com.kravasign.KravaSigner`, while the distributed licence output sits outside Settings.bundle at `com.mono0926.LicensePlist.Output/`. That original arrangement is preserved and documented, rather than silently presented as a verified working system Settings pane. Additional current dependency acknowledgements may be generated by the retained plugin; original distributed acknowledgements are restored afterward.

The 21 reference files include the original app/framework/package Info.plists and 13 AppleDouble PNG sidecars. Device-specific framework/package Info.plists are not imposed on simulator products; Xcode generates their platform values. Original privacy manifests are retained as runtime resources. The ElleKit payload, loose icons, build configuration, launch/model files and licence output are all preserved. The only old machine-code files excluded as source inputs are KravaSigner and OpenSSL; the latter is supplied by the pinned source package's platform XCFramework. The seven private inputs are the app provisioning profile and six default-certificate/profile/password files. The source build needs newly generated signatures.

Follow-up source research again checked both search engines and the official KravaSign signing page. No verifiable release of this native 2.8.2 app's original official source was located. A developer portfolio mentions a multi-platform KravaSigner, but provides no source for this IPA; that mention alone does not authenticate this binary or identify its private commit. Third-party shortcuts describe other KravaSigner URL formats/versions, so their proposed routes are not substituted for the routes actually traced here. No support message was sent.

Additional primary references:

- [carfile-go v0.8.0](https://github.com/devcxm/carfile-go/releases/tag/v0.8.0) and [format model](https://github.com/devcxm/carfile-go/blob/fd018181f5efda6ef6fdd4f2d26c8085451e143c/docs/assets-car-format.md).
- [NIBArchive parser](https://github.com/MatrixEditor/nibarchive) and [API documentation](https://matrixeditor.github.io/nibarchive/).
- [KravaSign signing page](https://www.kravasign.com/sign).
- [Developer portfolio](https://wholelotta.red/), inspected only as a source-availability lead.

The resource inventory is exhaustive for this supplied ZIP. **The original source and full behavioural equivalence remain unrecovered**: the native private change set, original source expressions/comments, full SwiftUI view bodies, private build history and credentials are not recreated by a file inventory or a successful compilation.

## Independent compiled-metadata and signing follow-up

The third audit independently reparsed the original and prior rebuilt device executables. Both expose the same 106 recovered KravaSigner nominal type names, but two stored-field lists differed. `SourcesAddView` in the original contains only `_dismiss`, `_dataService`, `__isImporting`, `__sourceURL`; the prior build added `_filteredRecommendedSourcesData`, `_recommendedSourcesData`, and `recommendedSources`. `SourcesView` in the original omits the prior build's `__shouldStar`. The original binary also lacks the full reference-specific recommendation URLs, `Feather.shouldStar`, and GitHub star URL. The recommendation list and star-prompt code have therefore been removed. Confidence is high for the observed stored-field difference; the full original SwiftUI bodies remain unrecovered. `prior-build-metadata-mismatches.json` retains the before/after comparison inputs, and `inspect-swift-metadata.py` makes it repeatable on device builds.

All four apparent source-name gaps among the recovered Core Data entity types are generated classes: the editable model explicitly sets `codeGenerationType="class"` for AltSource, CertificatePair, Imported and Signed. ResourceBundleClass is a resource-accessor marker also present in the prior rebuilt executable; a generated accessor is a plausible explanation, rather than evidence of a lost authored Swift file. The bounded parser still reports 293 unparsed records across all modules. Matching the recovered names and fields does not recover every original function or prove complete source equivalence.

The original main executable's signature has 19 XML entitlement keys, including account/profile-bound identifiers and `get-task-allow = false`. The reference authoring template had only `get-task-allow = true`. That distinction was underdocumented before this audit. A redacted key/type inventory is retained in `original-signing-metadata-summary.json`; the owner can export all exact values privately with `export-original-entitlements.py`. The minimal source template's debugger flag now matches the observed false value. The other signed values are not automatically imposed on new builds because a compatible provisioning profile is required, and signature output does not identify the original authoring file. This correction does not make an unsigned IPA signing-equivalent.

Fresh research again inspected the official KravaSign homepage/signing page, both search engines and GitHub's KravaSigner repository search. No verifiable official native 2.8.2 source release was located. The other repository result, joemossjr16/ios-apps, contains repository JSON, web launch files, artwork and notices, rather than this app's native Swift project. This is a bounded search finding, not proof that private or unindexed official source cannot exist.

Primary documentation additionally checked: [Apple bundle structures](https://developer.apple.com/library/archive/documentation/CoreFoundation/Conceptual/CFBundles/BundleTypes/BundleTypes.html), [Swift nominal metadata ABI](https://github.com/swiftlang/swift/blob/main/docs/ABI/TypeMetadata.rst), and [Apple TN2415 entitlement sources and signing](https://developer.apple.com/library/archive/technotes/tn2415/_index.html). The bundle guide is archived and is used for the distinction between executable/resources/configuration, not as a current restriction on embedded frameworks. Apple describes signed entitlements as an output of project/profile/signing inputs, which is why an observed signed entitlement dictionary is not labelled an original source file.

## Continued field-type and whole reflection-string comparison

The next audit normalized symbolic mangled type references through verified chained-fixup locations and compared all recovered app descriptors' type kinds, descriptor flags, field/case flags, field types and recorded superclass references. All 106 descriptors and 462 records agree with the corrected device product from run 38126989899: 380 nonempty field-type expressions, 82 enum cases without recorded payload types, and 13 nonempty superclass references. All selected references resolved. This does not alter the earlier 293 unparsed records across modules or recover method bodies. Anonymous contexts without recorded names retain an explicit anonymous marker.

The complete original and corrected `__swift5_reflstr` sections are also byte-identical: 98,071 bytes and 7,060 nonempty strings. The prior build before the two source-state corrections had four additional names and no missing original names; the corrections restored the whole section's original digest. The record is in `reflection-string-section-comparison.json`. This establishes equality of that compiler-emitted string table, not all declarations or implementations.

The added negative checker changes actual owner-binary metadata only in memory. It detects a changed mutable flag and a String-to-Bool field type change without changing the field name, and refuses to silently accept an unsupported symbolic reference. `EXTENDED-STRUCTURE.md` explains the repeatable checks, observed outcomes and primary Swift/Apple format sources.
