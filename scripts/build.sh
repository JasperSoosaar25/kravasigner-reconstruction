#!/usr/bin/env bash
set -euo pipefail
project_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$project_root"
if ! command -v xcodebuild >/dev/null 2>&1; then
  echo "An Apple macOS host with Xcode is required; xcodebuild was not found." >&2
  exit 2
fi
platform="${1:-device}"
case "$platform" in
  device) sdk=iphoneos; destination='generic/platform=iOS' ;;
  simulator) sdk=iphonesimulator; destination='generic/platform=iOS Simulator' ;;
  *) echo 'Usage: scripts/build.sh [device|simulator]' >&2; exit 2 ;;
esac
mkdir -p artifacts
common=(
  -workspace Feather.xcworkspace -scheme Feather -configuration Release
  -sdk "$sdk" -destination "$destination"
  -derivedDataPath "DerivedData-$platform"
  -clonedSourcePackagesDirPath "$project_root/SourcePackages"
  -disableAutomaticPackageResolution -onlyUsePackageVersionsFromResolvedFile
  -skipPackagePluginValidation -skipMacroValidation
  CODE_SIGNING_ALLOWED=NO CODE_SIGNING_REQUIRED=NO CODE_SIGN_IDENTITY=
  DEVELOPMENT_TEAM= DEPLOYMENT_LOCATION=NO
)
set -o pipefail
xcodebuild "${common[@]}" -resolvePackageDependencies 2>&1 | tee "artifacts/resolve-$platform.log"
xcodebuild "${common[@]}" -resultBundlePath "artifacts/build-$platform.xcresult" build 2>&1 | tee "artifacts/build-$platform.log"
app="DerivedData-$platform/Build/Products/Release-$sdk/KravaSigner.app"
test -d "$app"
python3 scripts/verify-built-app.py "$app" "$platform"
if [[ "$platform" == device ]]; then
  mkdir -p artifacts/device/Payload
  ditto "$app" artifacts/device/Payload/KravaSigner.app
  (cd artifacts/device && /usr/bin/zip -qry ../KravaSigner-reconstructed-unsigned.ipa Payload)
  shasum -a 256 artifacts/KravaSigner-reconstructed-unsigned.ipa | tee artifacts/ipa-sha256.txt
fi
