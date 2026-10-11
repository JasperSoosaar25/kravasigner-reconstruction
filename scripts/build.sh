#!/usr/bin/env bash
set -euo pipefail
project_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$project_root"
if ! command -v xcodebuild >/dev/null 2>&1; then
  echo "An Apple macOS host with Xcode is required; xcodebuild was not found." >&2
  exit 2
fi
platform="${1:-device}"
mode="${2:-development}"
case "$mode" in
  baseline|development) ;;
  *) echo 'Build mode must be baseline or development.' >&2; exit 2 ;;
esac
case "$platform" in
  device) sdk=iphoneos; destination='generic/platform=iOS' ;;
  simulator) sdk=iphonesimulator; destination='generic/platform=iOS Simulator' ;;
  *) echo 'Usage: scripts/build.sh [device|simulator] [development|baseline]' >&2; exit 2 ;;
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
  "KRAVA_BUILD_MODE=$mode"
)
set -o pipefail
python3 scripts/validate-source.py --mode "$mode"
xcodebuild "${common[@]}" -resolvePackageDependencies 2>&1 | tee "artifacts/resolve-$platform.log"
# Clean products when rebuilding: a baseline catalog must not survive a development build.
xcodebuild "${common[@]}" clean 2>&1 | tee "artifacts/clean-$platform.log"
rm -rf "artifacts/build-$platform.xcresult"
xcodebuild "${common[@]}" -resultBundlePath "artifacts/build-$platform.xcresult" build 2>&1 | tee "artifacts/build-$platform.log"
app="DerivedData-$platform/Build/Products/Release-$sdk/KravaSigner.app"
test -d "$app"
python3 scripts/verify-built-app.py "$app" "$platform" --mode "$mode"
printf '%s\n' "$mode" > "artifacts/build-mode-$platform.txt"
if [[ "$platform" == device ]]; then
  rm -rf artifacts/device/Payload
  mkdir -p artifacts/device/Payload
  ditto "$app" artifacts/device/Payload/KravaSigner.app
  ipa_name=KravaSigner-development-unsigned.ipa
  [[ "$mode" != baseline ]] || ipa_name=KravaSigner-reconstructed-unsigned.ipa
  rm -f "artifacts/$ipa_name"
  (cd artifacts/device && /usr/bin/zip -qry "../$ipa_name" Payload)
  shasum -a 256 "artifacts/$ipa_name" | tee artifacts/ipa-sha256.txt
fi
