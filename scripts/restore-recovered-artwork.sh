#!/usr/bin/env bash
set -euo pipefail
: "${SRCROOT:?Run this through Xcode}"
: "${BUILT_PRODUCTS_DIR:?Run this through Xcode}"
: "${CONTENTS_FOLDER_PATH:?Run this through Xcode}"
app_bundle="${BUILT_PRODUCTS_DIR}/${CONTENTS_FOLDER_PATH}"
mkdir -p "$app_bundle"
# Restore the original artwork, launch NIBs, Core Data model, translations,
# Settings bundle, acknowledgements, privacy manifests and other safe resources.
# Executables, framework Info.plists, signatures and private inputs are excluded.
cp -R "${SRCROOT}/RecoveredResources/Bundle/." "$app_bundle/"
if [[ -d "${SRCROOT}/private-signing-assets" ]]; then
  mkdir -p "$app_bundle/signing-assets"
  cp -R "${SRCROOT}/private-signing-assets/." "$app_bundle/signing-assets/"
fi
