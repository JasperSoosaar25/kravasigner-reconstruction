# KravaSigner 2.8.2 — reconstructed source

This is an **unofficial reconstruction**, based on static analysis of the supplied KravaSigner IPA and the matching Feather release. It is not KravaSign's original official source, and it has not been certified as behaviorally identical. **Device and simulator source builds passed on GitHub Actions, and the simulator app launched successfully.** See `docs/BUILD-RESULTS.md` for the tested commit, artifacts and verification limits, and `docs/RECOVERY-COVERAGE.md` for exactly what was recovered.

## Fork it and add your ideas

You can fork this repository, build your own app and send improvements back here. Start with [the development guide](docs/DEVELOPMENT.md), [contribution steps](CONTRIBUTING.md) and [possible starting ideas](docs/ROADMAP.md). This is a community reconstruction with documented limits, not an official source release.

```bash
bash scripts/check.sh development
bash scripts/build.sh simulator development  # macOS / Xcode 26.0.1
```

On Windows, Linux or a phone, edit your fork and use **Actions → Build KravaSigner → Run workflow → development**. CI needs no signing secrets. The default development build compiles editable resources and permits new types, fields, colors and translations. **Baseline** is an optional historical audit that restores the original resources and checks selected binary metadata; it is not a gate for new features. See [NOTICE](NOTICE.md) for licenses, attribution and artwork/branding limits.

The changes go beyond artwork: direct certificate/key downloads, automatic launch refresh, the `local.kravasign.com` installation host, the `kravasigner` URL handler, Settings changes, app metadata, cache identity, the orange #f97316 accent, original translations and full resource restoration. `docs/EVIDENCE.md` identifies their evidence and confidence. Most signing, repository, archive, database and installation code remains the pinned Feather reference because its original KravaSigner implementation cannot be recovered completely from this binary.

The independent follow-up audit in `docs/DOUBLE-CHECK.md` also found and removed two reference-only source features: the recommended-repository list and GitHub star prompt. The device workflow now compares compiled app type names and stored-field names with all 106 recovered original descriptors. The corrected [Actions run 38126989899](https://github.com/JasperSoosaar25/kravasigner-reconstruction/actions/runs/38126989899) passed both source builds and simulator startup; a separate check of its downloaded device executable also found all 106 recovered type names and fields match. This checks bounded metadata agreement, not every original method or view body.

The continued audit in `docs/EXTENDED-STRUCTURE.md` checks field types, mutability, descriptor flags and recorded superclass types. Against the actual corrected device product, all 106 recovered types and 462 reflection records agree; 380 have nonempty type expressions and 82 are enum cases without a payload type. The full 98,071-byte reflection-name section also matches the original exactly. The device workflow now checks the stronger structure against an original metadata snapshot, without using the old executable as a build input. The stronger check and both builds passed in [run 38128927828](https://github.com/JasperSoosaar25/kravasigner-reconstruction/actions/runs/38128927828), and the downloaded products passed independently. These are bounded structural checks; original function and UI bodies remain uncertain.

## Build

Use macOS with **Xcode 26.0.1** (iOS 26.0 SDK), matching the uploaded app's SDK generation. The shared workspace and scheme still have the names `Feather.xcworkspace` and `Feather`; their app product and Swift module are `KravaSigner`. Those project names acknowledge the reference project's origin.

```bash
bash scripts/build.sh device baseline
```

The result is `artifacts/KravaSigner-reconstructed-unsigned.ipa`. It needs an appropriate signing identity before installation on a physical device. This builds a new executable from source; the original executable is not packaged or used by the build.

```bash
bash scripts/build.sh simulator baseline
bash scripts/simulator-smoke.sh
```

The simulator script installs and launches the app, checks that it remains alive after startup, and records a screenshot and logs. It does not establish real-device signing or installation reliability.

The GitHub Actions workflow `.github/workflows/reconstruct.yml` supports development (default) and baseline modes and runs these two jobs on `macos-15`, selects Xcode 26.0.1 explicitly, uses the dependency lockfiles, and saves logs, build-result bundles and generated artifacts. It runs on pushes to `main`, pull requests and manual dispatch. Action implementations are pinned to inspected commit SHAs. No releases are automatically published. Normal pushes and PRs use development mode; manually choose baseline for the original metadata comparisons.

## Local behavioral tests

```bash
python3 scripts/validate-source.py --mode baseline
swiftc Feather/Utilities/TLSAssetDownloader.swift tests/TLSAssetDownloaderTests.swift -o /tmp/krava-tls-tests
/tmp/krava-tls-tests
```

These offline tests exercise the same reconstructed download helper used by the app: request order/policy, successful output, second-request failure, invalid UTF-8, and write failure. They use invented fixtures, not signing credentials or the live TLS endpoints. Linux Swift can run this helper; it cannot compile UIKit or launch the iOS app.

## Original resources and optional private inputs

`RecoveredResources/Bundle/` contains the original runtime resources. The build restores all **66 files byte-for-byte**, including the compiled catalog, loose icons, launch NIBs, Core Data model, translations, Settings bundle, acknowledgements and privacy manifests. Another **21 metadata files** are retained for reference. `docs/ipa-file-coverage.json` and `.csv` account for all **135 archive entries**.

The original distributed `Feather.xcconfig` is now preserved separately at `RecoveredResources/Bundle/Feather.xcconfig`; the root config is editable for development.

All nine catalog bitmap renditions were decoded successfully; the six unique raster images are editable in `Feather/Resources/Assets.xcassets`, with light/dark/tinted icon entries. This recovers distributed pixels, not original vector/layer designer files. The original catalog is restored after compilation for exact runtime resource preservation. The default tint is the binary-observed orange **#f97316**; saved appearance preferences and iOS system colours still apply.

The uploaded IPA included two default signing-asset folders. Their PKCS#12 keys, provisioning profiles and passwords are **excluded** from this source archive and repository. You can import your own certificates through the app. To recreate the bundled defaults locally from your own IPA:

```bash
python3 scripts/import-private-signing-assets.py /path/to/KravaSigner.ipa
```

This writes to the gitignored `private-signing-assets/` directory. The Xcode build phase includes that directory only when it exists. The CI build has no default signing credentials. The TLS files are fetched at runtime from the URLs observed in the binary; none was downloaded during this investigation.

The original signed executable also contains 19 entitlement keys. To retain their exact values privately:

```bash
python3 scripts/export-original-entitlements.py /path/to/KravaSigner.ipa
```

The export stays in gitignored `private-signing-metadata/` and is not automatically applied. Signing output may incorporate profile or signing-tool values and does not recover the original project entitlements file. The minimal source template now uses the observed `get-task-allow = false`; any eventual signed installation must use entitlements permitted by its profile.

## Provenance and limits

- Feather `v2.8.2`: `1a9b2bbcc7ebe0fbbf76fec45ec1e94ff0c4edc4`.
- Zsign local package: `6ffe703df73ef9069adacdbb19d571f11a69a801`.
- IDeviceKit local package: `837cf1e14d4875771dd5ee1b754a4c86215c5db3`.
- Uploaded IPA SHA-256: `c155ad99e97bf8d65bee28df63076cffb6050c6fc142aa08255d2a1f243010e8`.

The two submodule source trees are included directly so a ZIP checkout works. Unrelated Windows prebuilt libraries are omitted from Zsign. Swift Package Manager still downloads the pinned remote dependencies and checksum-verified OpenSSL/IDevice frameworks. Their native-library source was not recovered from the KravaSigner IPA.

The upstream GPL-3.0 license, copyright notices and bundled dependency licenses are retained. The original reference README is in `docs/FEATHER-UPSTREAM-README.md`. This project's authoring choices, scripts and tests are newly written; no claim of official affiliation or publisher signature is made.

Review `docs/EVIDENCE.md` and `docs/STATUS.md` before treating any build as equivalent to the supplied app. Binary analysis cannot recover original comments, source formatting, the full private change set, signing identity, or the original project history.
