# KravaSigner 2.8.2 — reconstructed source

This is an **unofficial reconstruction**, based on static analysis of the supplied KravaSigner IPA and the matching Feather release. It is not KravaSign's original official source, and it has not been certified as behaviorally identical. The source project is ready for an Xcode build attempt. See `docs/STATUS.md` for checks actually completed.

The changes go beyond artwork: direct certificate/key downloads, automatic launch refresh, the `local.kravasign.com` installation host, the `kravasigner` URL handler, Settings changes, app metadata, cache identity, the orange #f97316 accent, original translations and full resource restoration. `docs/EVIDENCE.md` identifies their evidence and confidence. Most signing, repository, archive, database and installation code remains the pinned Feather reference because its original KravaSigner implementation cannot be recovered completely from this binary.

## Build

Use macOS with **Xcode 26.0.1** (iOS 26.0 SDK), matching the uploaded app's SDK generation. The shared workspace and scheme still have the names `Feather.xcworkspace` and `Feather`; their app product and Swift module are `KravaSigner`. Those project names acknowledge the reference project's origin.

```bash
bash scripts/build.sh device
```

The result, if compilation succeeds, is `artifacts/KravaSigner-reconstructed-unsigned.ipa`. It needs an appropriate signing identity before installation on a physical device. This builds a new executable from source; the original executable is not packaged or used by the build.

```bash
bash scripts/build.sh simulator
bash scripts/simulator-smoke.sh
```

The simulator script installs and launches the app, checks that it remains alive after startup, and records a screenshot and logs. It does not establish real-device signing or installation reliability.

The GitHub Actions workflow `.github/workflows/reconstruct.yml` runs these two jobs on `macos-15`, selects Xcode 26.0.1 explicitly, uses the dependency lockfiles, and saves logs, build-result bundles and generated artifacts. It runs on pushes to `main`, pull requests and manual dispatch. Action implementations are pinned to inspected commit SHAs. No releases are automatically published.

## Local behavioral tests

```bash
python3 scripts/validate-source.py
swiftc Feather/Utilities/TLSAssetDownloader.swift tests/TLSAssetDownloaderTests.swift -o /tmp/krava-tls-tests
/tmp/krava-tls-tests
```

These offline tests exercise the same reconstructed download helper used by the app: request order/policy, successful output, second-request failure, invalid UTF-8, and write failure. They use invented fixtures, not signing credentials or the live TLS endpoints. Linux Swift can run this helper; it cannot compile UIKit or launch the iOS app.

## Original resources and optional private inputs

`RecoveredResources/Bundle/` contains the original runtime resources. The build restores all **66 files byte-for-byte**, including the compiled catalog, loose icons, launch NIBs, Core Data model, translations, Settings bundle, acknowledgements and privacy manifests. Another **21 metadata files** are retained for reference. `docs/ipa-file-coverage.json` and `.csv` account for all **135 archive entries**.

All nine catalog bitmap renditions were decoded successfully; the six unique raster images are editable in `Feather/Resources/Assets.xcassets`, with light/dark/tinted icon entries. This recovers distributed pixels, not original vector/layer designer files. The original catalog is restored after compilation for exact runtime resource preservation. The default tint is the binary-observed orange **#f97316**; saved appearance preferences and iOS system colours still apply.

The uploaded IPA included two default signing-asset folders. Their PKCS#12 keys, provisioning profiles and passwords are **excluded** from this source archive and repository. You can import your own certificates through the app. To recreate the bundled defaults locally from your own IPA:

```bash
python3 scripts/import-private-signing-assets.py /path/to/KravaSigner.ipa
```

This writes to the gitignored `private-signing-assets/` directory. The Xcode build phase includes that directory only when it exists. The CI build has no default signing credentials. The TLS files are fetched at runtime from the URLs observed in the binary; none was downloaded during this investigation.

## Provenance and limits

- Feather `v2.8.2`: `1a9b2bbcc7ebe0fbbf76fec45ec1e94ff0c4edc4`.
- Zsign local package: `6ffe703df73ef9069adacdbb19d571f11a69a801`.
- IDeviceKit local package: `837cf1e14d4875771dd5ee1b754a4c86215c5db3`.
- Uploaded IPA SHA-256: `c155ad99e97bf8d65bee28df63076cffb6050c6fc142aa08255d2a1f243010e8`.

The two submodule source trees are included directly so a ZIP checkout works. Unrelated Windows prebuilt libraries are omitted from Zsign. Swift Package Manager still downloads the pinned remote dependencies and checksum-verified OpenSSL/IDevice frameworks. Their native-library source was not recovered from the KravaSigner IPA.

The upstream GPL-3.0 license, copyright notices and bundled dependency licenses are retained. The original reference README is in `docs/FEATHER-UPSTREAM-README.md`. This project's authoring choices, scripts and tests are newly written; no claim of official affiliation or publisher signature is made.

Review `docs/EVIDENCE.md` and `docs/STATUS.md` before treating any build as equivalent to the supplied app. Binary analysis cannot recover original comments, source formatting, the full private change set, signing identity, or the original project history.
