#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "${BASH_SOURCE[0]}")/.."
mode="${1:-development}"
python3 scripts/validate-source.py --mode "$mode"
python3 tests/BuildModesTests.py
for script in scripts/*.sh; do bash -n "$script"; done
if command -v swiftc >/dev/null 2>&1; then
  task_test_dir="$(mktemp -d)"
  trap 'rm -rf "$task_test_dir"' EXIT
  swiftc Feather/Utilities/TLSAssetDownloader.swift tests/TLSAssetDownloaderTests.swift -o "$task_test_dir/tls-tests"
  "$task_test_dir/tls-tests"
else
  echo 'Swift compiler unavailable: TLS tests skipped locally; the macOS build runs them.'
fi
