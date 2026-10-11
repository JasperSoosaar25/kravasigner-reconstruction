# Actual validation status — 11 October 2026

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
| GitHub Actions source build | First run reached Xcode 26.0.1; validation caught ignored archive metadata files. Fixed; next run pending |
| iOS Simulator launch / screen inspection | Not performed; script and workflow prepared |
| Physical-device signing and installation | Not tested |
| Full equivalence to the supplied KravaSigner release | Not established |

The local build attempt returned exit 2 with: `An Apple macOS host with Xcode is required; xcodebuild was not found.` It did not generate an IPA. The prepared workflow saves the unsigned IPA only after a successful device source build and validates its identity and recovered resources. Its separate simulator job installs and launches a simulator build, checks startup survival, and retains a screenshot and logs.

The GitHub connection exposes existing repositories but no repository-creation capability. No unrelated repository was modified. The owner authorized browser fallback after the follow-up audit. The private repository was created successfully, and its first 423 uploaded file blobs matched local git hashes. The first Actions run (38102244524) selected Xcode 26.0.1 successfully, then correctly stopped resource validation: the broad Payload ignore rule had excluded 13 AppleDouble reference files. The rule is now restricted to the root build-output directory; all 13 metadata files are included, and validation also checks that recovered files are tracked. Full compilation and simulator execution remain pending.
