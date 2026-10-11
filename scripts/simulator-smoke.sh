#!/usr/bin/env bash
set -euo pipefail
mkdir -p artifacts
device_id="$(xcrun simctl list devices available -j | python3 -c 'import json,sys; d=json.load(sys.stdin); devices=[x for runtime,items in d["devices"].items() if "iOS-26" in runtime for x in items if x["name"].startswith("iPhone") and x.get("isAvailable")]; assert devices,"No available iPhone simulator on iOS 26"; print(devices[0]["udid"])')"
xcrun simctl boot "$device_id" || test "$(xcrun simctl list devices -j | python3 -c 'import json,sys; ident=sys.argv[1]; print(next(x["state"] for items in json.load(sys.stdin)["devices"].values() for x in items if x["udid"]==ident))' "$device_id")" = Booted
xcrun simctl bootstatus "$device_id" -b
xcrun simctl install "$device_id" DerivedData-simulator/Build/Products/Release-iphonesimulator/KravaSigner.app
app_info=DerivedData-simulator/Build/Products/Release-iphonesimulator/KravaSigner.app/Info.plist
bundle_id="$(python3 -c 'import plistlib,sys; print(plistlib.load(open(sys.argv[1],"rb"))["CFBundleIdentifier"])' "$app_info")"
launch_output="$(xcrun simctl launch --terminate-running-process "$device_id" "$bundle_id")"
echo "$launch_output" | tee artifacts/simulator-launch.log
app_pid="${launch_output##*: }"
[[ "$app_pid" =~ ^[0-9]+$ ]]
# Give startup (including its asynchronous TLS task) time to reveal an immediate crash.
sleep 10
kill -0 "$app_pid"
xcrun simctl io "$device_id" screenshot artifacts/simulator-startup.png
xcrun simctl spawn "$device_id" log show --last 1m --style compact --predicate 'process == "KravaSigner"' > artifacts/simulator-system.log
echo 'PASS app launched and remained alive through startup' | tee -a artifacts/simulator-launch.log
