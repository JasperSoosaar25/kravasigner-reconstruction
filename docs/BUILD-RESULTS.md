# Verified source builds and simulator run

Verified on 11 October 2026 in the owner's private repository:
[JasperSoosaar25/kravasigner-reconstruction](https://github.com/JasperSoosaar25/kravasigner-reconstruction).

The successful [GitHub Actions run 38126989899](https://github.com/JasperSoosaar25/kravasigner-reconstruction/actions/runs/38126989899)
tested source commit `edad40232beca7ce0cd81363fc14812e0a8ca3b0`.
Both jobs succeeded; total run duration was 6 minutes 31 seconds. Documentation-only
updates after this commit do not change the tested app or workflow.

| Check | Actual result |
|---|---|
| Toolchain | macOS 15.7.9 ARM64 runner, Xcode 26.0.1 (17A400), iOS 26.0 SDK |
| iOS device build | Source compilation succeeded; job 114433300685 |
| iOS simulator build | Source compilation succeeded; job 114433300298 |
| TLS fixtures | Four tests passed in both jobs: success/request policy, second-request failure, invalid UTF-8, filesystem failure |
| Product identity | KravaSigner 2.8.2/build 1, com.kravasign.KravaSigner; platform metadata appropriate to each product |
| Original runtime resources | All 66 files independently hash-checked in the downloaded device and simulator products |
| Compiled app metadata | All 106 recovered original nominal names and stored-field names match; CI and independent downloaded-executable check passed |
| Whole app file paths | Zero unexplained omissions, zero added paths; only seven private inputs and unsigned main signature absent |
| Simulator startup | Installed and launched, PID 15617, alive after the 10-second startup check |
| Screenshot | Actual Sources screen inspected: orange controls, recovered repository artwork, system background and tab bar |
| Original executable substitution | None: newly built main executable has a different SHA-256 from the supplied binary |
| Physical-device signing/install | Not tested; device IPA is unsigned |

Selected actual terminal output from the retained artifact logs:

```text
device:    ** BUILD SUCCEEDED **
simulator: ** BUILD SUCCEEDED **
PASS successful paired download and exact request policy
PASS second download failure leaves files untouched
PASS invalid UTF-8 leaves files untouched
PASS filesystem failure propagates
PASS all recovered original app type names and stored-field names match
PASS 135 archive entries; 87 recovered source files compared directly
device: 66 original runtime files exact; 0 unexplained omissions; 0 added app paths
simulator: 66 original runtime files exact; 0 unexplained omissions; 0 added app paths
com.kravasign.KravaSigner: 15617
PASS app launched and remained alive through startup
```

## Downloaded artifacts

| Artifact | Size (bytes) | SHA-256 |
|---|---:|---|
| KravaSigner-reconstructed-unsigned.ipa | 13,612,196 | 42fc65881414b7d0e85b4fb639012664c2154d67d51c59996bd1a7df73832a1a |
| KravaSigner-device-build.zip | 28,072,386 | 677a521ec48d982c890cbb694363477fd82e874e3180e4c2ba3cc73c9e65d272 |
| KravaSigner-simulator-build.zip | 26,696,942 | 2b4543b75a48faed2e78528b68ef982831f07e22c7f20254a877d22ef1875996 |

The ZIP digests match GitHub's artifact digests. The device ZIP contains the
unsigned IPA, dependency/build/test logs, compiled metadata JSON and Xcode result bundle. The simulator
ZIP contains the compiled app, dependency/build/test logs, Xcode result bundle,
launch and system logs, and startup screenshot. GitHub retains these run
artifacts until 25 October 2026; downloaded copies were also delivered separately.

New device executable SHA-256:
`59fc10f980bbc94b072ecdb70b75773adf8730aa602dcaed6ec29d0dd9dd931d`.
Original supplied executable SHA-256:
`b3376d32865ce970eefcfc061ad6750723fc01dd864c1da6bb7f415c1b9a45b3`.
Machine-readable results are in `evidence/build-verification.json`.

## Practical limits

Startup success does not test every screen, signing with a real certificate,
remote repository operations, TLS endpoint availability, or installation on a
physical device. CI contains no private default signing credentials. Appropriate
signing is required to install the device IPA; owner-supplied certificates may
be imported through the app or the optional local preparation script.

The build emitted inherited compiler warnings, including native CPU macro
redefinitions and concurrency warnings. GitHub also reported that the pinned
Node 20 actions were run with Node 24, and an ARM64 runner capacity notice; both
jobs still passed. The simulator system log includes simulator socket-option
and Apple launch-metric messages. These observations are retained in the logs;
the check only establishes successful compilation and bounded startup.

This is still an unofficial, evidence-labelled reconstruction. No verifiable
original official source release was located, and neither compilation nor exact
resource preservation establishes full equivalence to the original executable.

## Earlier build and corrected follow-up

Run [38102345171](https://github.com/JasperSoosaar25/kravasigner-reconstruction/actions/runs/38102345171) successfully built commit `90ba4ff66f784c1bad034b2b5976a70000078c75`. The later independent audit found two source field differences despite matching all resource files. They were corrected, and the new run above tests those changes plus the compiled metadata check. Earlier downloaded-product observations remain separately recorded in `evidence/independent-archive-audit.json` and `evidence/prior-build-metadata-mismatches.json`.
