# Build a fork and add features

You can change this project and build your own app. The current code builds from source; the original executable is not a build input. This remains an unofficial reconstruction, and the recovery audit does not prove every original method or UI body.

## Start with a fork

Use GitHub's **Fork** button, then clone your own repository and create a feature branch:

```bash
git clone https://github.com/YOUR-USERNAME/kravasigner-reconstruction.git
cd kravasigner-reconstruction
git switch -c feature/my-idea
bash scripts/check.sh development
```

Replace `YOUR-USERNAME` with your GitHub name. All four local package trees are included, so no recursive submodule command is needed. Remote dependencies still download at the pinned versions. Keep both `Package.resolved` files synchronized when intentionally updating them.

## Build on a Mac

Use **Xcode 26.0.1**, its iOS 26.0 SDK and Python 3. The deployment target is iOS 16. The shared workspace/scheme remain `Feather.xcworkspace` / `Feather`; the product and Swift module are `KravaSigner`.

```bash
bash scripts/build.sh simulator development
bash scripts/simulator-smoke.sh
bash scripts/build.sh device development
```

The simulator app is at `DerivedData-simulator/Build/Products/Release-iphonesimulator/KravaSigner.app`. The device output is `artifacts/KravaSigner-development-unsigned.ipa`. Logs and Xcode result bundles go to `artifacts/`. Repeated builds clean old products/results so switching modes cannot retain the original compiled catalog.

For interactive Xcode work, open `Feather.xcworkspace`, select **Feather** and an iPhone simulator, then Run. `KRAVA_BUILD_MODE = development` in `Feather.xcconfig` prevents the recovery phase from overwriting editable resources. For a personal device, configure your own permitted bundle identifier and signing team. Command-line/CI builds disable signing; installation requires your own suitable signing method and profile. Renaming the product/module/workspace requires coordinated project and script changes; changing the bundle identifier alone does not require that rename.

## Build from Windows, Linux or your phone

You can edit and commit source on those platforms, but the iOS app requires Apple's macOS toolchain. A Windows/Linux shell or WSL cannot compile the full UIKit app.

1. Open **your fork's Actions tab** and enable workflows if GitHub asks.
2. Choose **Build KravaSigner → Run workflow**.
3. Select your branch and **development** mode, then start the run.
4. Open the finished run and download the device/simulator artifacts. The device ZIP contains the unsigned development IPA. Both ZIPs include logs; the simulator job also records actual startup and a screenshot.

Pushing to `main` or opening a PR runs development builds. Lightweight **Contributor checks** run on every pushed branch. Fork PRs use ordinary `pull_request`, read-only permissions and no signing secrets; GitHub may require a maintainer's approval for a new contributor. No workflow publishes releases or deploys anything.

## Where to make changes

| Idea | Main files/directories |
| --- | --- |
| New screen or tab | `Feather/Views/`, `Feather/Views/TabView/`, `Feather/FeatherApp.swift` |
| Repository browsing, filtering or source UI | `Feather/Views/Sources/`, `Feather/Backend/Storage/Storage+Sources.swift`, `AltSourceKit/` |
| Download queue, progress and errors | `Feather/Backend/Observable/DownloadManager.swift`, `Feather/Views/Download/` |
| Library and app management | `Feather/Views/Library/`, `Feather/Backend/Storage/` |
| Preferences and appearance | `Feather/Views/Settings/`, `Feather/Utilities/`, `Feather/FeatherApp.swift` |
| Icons, launch screen and translations | `Feather/Resources/Assets.xcassets`, `Icons/`, `Launch Screen.storyboard`, `Localizable.xcstrings`, `Settings.bundle/` |
| Persistence and migrations | `Feather/Backend/Storage/Feather.xcdatamodeld/`, storage helpers |
| Signing and installation | `Feather/Views/Signing/`, `Feather/Backend/Server/`, `Zsign/`, `IDeviceKitten/` |

The Xcode project uses a synchronized `Feather/` folder. New Swift files placed there normally join the target automatically; check target membership/exclusions and build after adding a file. Do not add a fake metadata snapshot for a new feature. Data-model changes need a migration plan so existing user data survives. Local package changes should respect each package's API and license.

## Resources and the original audit

Development mode compiles editable resources and accepts new fields, types, colors, translations and versions. It does not copy `RecoveredResources/Bundle` over your edits. Recovered pixels are editable, but new branding should use assets you may distribute; see [NOTICE](../NOTICE.md).

Baseline mode preserves the earlier reconstruction audit:

```bash
bash scripts/check.sh baseline
bash scripts/build.sh device baseline
python3 scripts/inspect-swift-metadata.py \
  DerivedData-device/Build/Products/Release-iphoneos/KravaSigner.app/KravaSigner \
  --reference docs/evidence/swift-types.json --output artifacts/swift-metadata-device.json
python3 scripts/compare-swift-structure.py \
  docs/evidence/original-swift-structure.json \
  DerivedData-device/Build/Products/Release-iphoneos/KravaSigner.app/KravaSigner \
  --output artifacts/swift-structure-device.json
```

That mode restores all 66 runtime resource bytes and uses strict original-identity checks. Its IPA is `artifacts/KravaSigner-reconstructed-unsigned.ipa`. In Actions, select **baseline** to enable both compiled-device comparisons. A new feature may fail these intentionally. Keep original evidence intact and use the earlier tested commits when reproducing the historical comparison. Default development CI checks buildability and startup rather than original binary equality.

## Test and send your change

Run `bash scripts/check.sh development`, build the affected platforms, and try the changed flow in the simulator. Use a real device with your own credentials to validate signing/installation changes; simulator startup alone cannot establish those paths. Check light/dark mode, large text, accessibility and empty/error/loading states for UI work.

Use invented fixtures and redact screenshots/logs before uploading. Keep personal inputs in gitignored `private-signing-assets/` or `private-signing-metadata/` directories; no workflow needs them. Do not add secrets to the workflow.

Commit and push your feature branch, then open a PR here. Describe the trigger, resulting behavior, test results and remaining limits. See [CONTRIBUTING](../CONTRIBUTING.md) and [possible starting ideas](ROADMAP.md).
