# What is recovered, reconstructed and still unknown

This distinction applies to the supplied KravaSigner **2.8.2/build 1** IPA only.
It is not an official source release or a claim of complete behavioural equivalence.

| Area | Included material | Evidence and limit |
|---|---|---|
| Accent and appearance | Orange `#f97316` fallback, saved tint/style preferences, original light/dark/tinted icon imagery | Traced ARM64 constants and preference calls; other iOS semantic colours remain system-adaptive |
| Asset catalog | Original Assets.car, nine decoded bitmap renditions, six unique editable raster images and all 11 rendition descriptors | Original catalog bytes preserved; original vectors/layers and authoring history unavailable |
| Loose artwork | All 15 loose PNGs, including the original document icon | Exact original bytes |
| Launch screen | Original two NIBs and Info.plist; editable storyboard with matching observed geometry and semantic colours | Original Glyph reference has no corresponding original catalog facet; no missing artwork invented |
| Database | Original .mom, .omo and version metadata; matching editable four-entity schema | 27 attribute names/types/optional flags and two inverse Nullify relationships compared; storage logic still mostly reference source |
| Text | Original 13 locale strings files and eight plural dictionaries; editable xcstrings updated | Three missing keys, 56 differing existing translations restored; all 20 original plural entries match the source variations |
| Settings and licences | Exact original Settings.bundle and 11 acknowledgement files | Original acknowledgement child/output location arrangement retained; system Settings pane not independently verified |
| Other resources | Seven privacy manifests, ElleKit payload, PkgInfo and recovered xcconfig | Restored without substituting old machine code |
| Identity and metadata | KravaSigner bundle/product/module names, URL scheme, document types and ATS values | Original app/framework/package Info.plists retained for reference; Xcode generates current platform output |
| TLS and installation changes | Reconstructed direct two-URL download, launch refresh and `local.kravasign.com` host | Selected routines and async continuations traced; offline tests cover observed request/write behaviour |
| Deep links | Reconstructed `kravasigner` scheme with traced import/export/source/install routes | Binary contains Swift small-string immediates; third-party routes for other versions not assumed |
| Main app source | 97 Swift files plus Objective-C/C++ bridging/native code and vendored local packages | Pinned Feather reference with documented recovered differences; complete KravaSigner private change set unknown |
| Dependencies | Project/workspace package locks and pinned local Zsign/IDeviceKit source | Six recorded original dependency/tool versions agree; all original transitive dependency versions not identifiable |
| Signing defaults | Owner IPA retains six default key/profile/password files; optional local import script supplied | Not committed to GitHub; default CI build has no bundled signing credentials |
| Original signing entitlements | All 19 key names/types inventoried; exact dictionary available through a private local exporter | Observed signature output, not the original authoring entitlements file; values are not applied automatically |
| Follow-up source differences | Recommendation list and star prompt removed; minimal debugger flag corrected | Original recovered fields now agree across all 106 app nominal descriptors; full method/UI bodies remain uncertain |
| Original signatures and executables | Accounted for in per-entry manifest and retained in owner IPA | Two signatures need replacement; main executable and OpenSSL are rebuilt/supplied for the correct platform |
| Archive metadata | Thirteen original AppleDouble sidecars retained as reference | No runtime app use claimed; included so metadata is not silently discarded |
| Original official Swift/project history | Unavailable | Binary analysis does not recover original source expressions, comments, private commit history or every SwiftUI body |

**Archive accounting:** 135 entries = 37 directories + 66 restored resources +
21 preserved reference files + 2 rebuilt executables + 7 private inputs +
2 replaced signatures. Every entry has a row in `ipa-file-coverage.json` and
`ipa-file-coverage.csv`; `recovered-resources.json` records all 87 preserved
resource/reference hashes. The validator checks hashes, tracked-file inclusion
and selected reconstructed behaviour. A successful build verifies compilation;
it does not certify equivalence to the original executable.

The GitHub source is authoritative for the updated reconstruction. The earlier
download archive predates the full theme/resource audit and should not be used
as the current version.
