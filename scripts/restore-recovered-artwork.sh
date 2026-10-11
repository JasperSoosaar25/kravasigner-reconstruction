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
case "${KRAVA_BUILD_MODE:-development}" in
  baseline)
    cp -R "${SRCROOT}/RecoveredResources/Bundle/." "$app_bundle/"
    ;;
  development)
    # Xcode compiles the editable resource tree. Do not overwrite a contributor's
    # catalog, translations, launch screen, Settings bundle or Core Data model.
    echo 'Development build: keeping resources compiled from editable source.'
    ;;
  *) echo 'KRAVA_BUILD_MODE must be baseline or development.' >&2; exit 2 ;;
esac
if [[ -d "${SRCROOT}/private-signing-assets" ]]; then
  mkdir -p "$app_bundle/signing-assets"
  cp -R "${SRCROOT}/private-signing-assets/." "$app_bundle/signing-assets/"
fi
