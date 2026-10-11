# Actual validation status — 11 October 2026

Community preparation now supports development builds for feature work and explicit baseline audits. Both modes and contributor checks passed at `7ccc411`; see [COMMUNITY-READINESS.md](COMMUNITY-READINESS.md). The earlier exact-resource/metadata results below describe baseline reconstruction builds.

| Check | Result |
|---|---|
| Uploaded IPA inventory/CRC, Mach-O metadata and hashes | Passed during original inspection |
| Exhaustive ZIP-entry coverage | Passed: all 135 entries; 87 resource/reference files preserved |
| Theme tracing | Passed: orange #f97316 fallback and saved preference override |
| Catalog bitmap extraction | Passed: nine physical bitmaps, six unique images, zero decoding failures |
| Original text/model/launch/Settings resources | Preserved with hash checks; editable text/artwork and matching schema included |
| Bounded ARM64 tracing and Ghidra decompilation | Completed; evidence and limits in EVIDENCE.md |
| Reconstructed TLS helper compiled with Swift 6.2 on Linux | Passed |
| Successful paired TLS download / request-order, timeout and cache policy fixture | Passed |
| Second TLS request failure leaves output unwritten | Passed |
| Invalid UTF-8 leaves output unwritten | Passed |
| Filesystem write failure propagates | Passed |
| Swift compiler syntax parse of all 97 app Swift files | Passed; this is not typechecking |
| Xcode OpenStep project parser | Passed: 58 project objects, one native app target |
| Plist/JSON/XML, app identity, URL handler, TLS wiring, recovered-byte hashes and lockfile checks | Passed |
| Shell-script syntax / workflow YAML and job structure | Passed |
| IDevice XCFramework checksum and device/simulator slices | Passed |
| Full iOS source compilation on this Linux machine | Attempted; stopped because xcodebuild is unavailable |
| GitHub repository creation | Created: JasperSoosaar25/kravasigner-reconstruction, private |
| GitHub Actions source build | Passed: device and simulator, Xcode 26.0.1; run 38128927828, commit d97d268 |
| Built resource preservation | Passed: all 66 original runtime files match their recorded hashes in both products |
| iOS Simulator launch / screen inspection | Passed: installed, launched and survived the 10-second startup check; actual screenshot inspected |
| Follow-up compiled metadata comparison | Passed: all 106 recovered app type names and fields match after two source corrections |
| Follow-up downloaded-product archive audit | Passed: all 87 preserved source files; 66 runtime files in each product; zero unexplained omissions or added app paths |
| Original signing metadata | All 19 observed entitlement keys inventoried; exact values export privately; original authoring file unknown |
| Extended compiled structure | Passed in CI and on downloaded device product: 106 type kinds/flags, 462 record types/flags and superclass references |
| Complete reflection-name section | Passed: all 98,071 original section bytes and 7,060 strings exact in latest device executable |
| Extended checker negative controls | Passed: changed mutable flag, changed String-to-Bool type with unchanged name, and unsupported symbolic reference all rejected |
| Physical-device signing and installation | Not tested |
| Full equivalence to the supplied KravaSigner release | Not established |

The local build attempt returned exit 2 with: `An Apple macOS host with Xcode is required; xcodebuild was not found.` The GitHub Actions macOS jobs subsequently compiled both products successfully. The workflow produced a new unsigned device IPA and a simulator app, validates their identity and recovered resources, and retains build logs and result bundles. The simulator job installed and launched the new app, checked startup survival, and captured its screen and system log.

The owner authorized creation of the dedicated private repository after the follow-up audit. The first Actions run (38102244524) correctly stopped resource validation because a broad Payload ignore rule had excluded 13 AppleDouble reference files. The rule was restricted to the root build-output directory; all 13 files are included, and validation checks tracked-file inclusion. The corrected run (38102345171) passed both jobs. All 436 files in that tested source tree matched the local Git blob hashes and modes. The follow-up restored all 439 files at checkpoint `f1ba72a` and checked their bytes and modes against its authenticated Git tree. It then found two inherited source field differences, removed the recommendation list and star prompt, documented original signing entitlements, corrected the minimal debugger flag, and added a compiled-metadata workflow check. Run `38126989899` successfully rebuilt both platforms at `edad402` and launched the simulator; the downloaded products independently passed the archive and metadata checks. Later report-only updates do not change that tested app source or workflow. See `BUILD-RESULTS.md` and `DOUBLE-CHECK.md`.

The continued tooling update at `d97d268` passed both jobs in run `38128927828`, including the new stronger structure check and simulator startup (PID 26698). Its downloaded products passed the independent archive audit, and its downloaded device executable passed the stronger structural comparison. The app implementation is unchanged from the prior corrected version. No original official source or whole-program equivalence is claimed.
