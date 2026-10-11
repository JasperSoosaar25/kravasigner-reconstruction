# Verified source builds and simulator run

Verified on 11 October 2026 in the owner's private repository:
[JasperSoosaar25/kravasigner-reconstruction](https://github.com/JasperSoosaar25/kravasigner-reconstruction).

The successful [GitHub Actions run 38102345171](https://github.com/JasperSoosaar25/kravasigner-reconstruction/actions/runs/38102345171)
tested source commit `90ba4ff66f784c1bad034b2b5976a70000078c75`.
Both jobs succeeded; total run duration was 7 minutes 2 seconds. Documentation-only
updates after this commit do not change the tested app or workflow.

| Check | Actual result |
|---|---|
| Toolchain | macOS 15.7.9 ARM64 runner, Xcode 26.0.1 (17A400), iOS 26.0 SDK |
| iOS device build | Source compilation succeeded; job 114360691302 |
| iOS simulator build | Source compilation succeeded; job 114360691195 |
| TLS fixtures | Four tests passed in both jobs: success/request policy, second-request failure, invalid UTF-8, filesystem failure |
| Product identity | KravaSigner 2.8.2/build 1, com.kravasign.KravaSigner; platform metadata appropriate to each product |
| Original runtime resources | All 66 files independently hash-checked in the downloaded device and simulator products |
| Simulator startup | Installed and launched, PID 92493, alive after the 10-second startup check |
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
```

## Downloaded artifacts

| Artifact | Size (bytes) | SHA-256 |
|---|---:|---|
| KravaSigner-reconstructed-unsigned.ipa | 13,624,279 | 53fd4010ffdcc8bd3c0db2b9f95345e63cb2c459b3b07b901b49021c23d9c86c |
| KravaSigner-device-build.zip | 28,089,129 | 735666fcd92df0dcea0873122e232a9fd68cb9f42c5d15d12f8e497e1c6acb56 |
| KravaSigner-simulator-build.zip | 26,717,035 | 293c46e514f54217847ee5618ff52050af8b2182e629caa5eae5837e0ee573e3 |

The ZIP digests match GitHub's artifact digests. The device ZIP contains the
unsigned IPA, dependency/build/test logs and Xcode result bundle. The simulator
ZIP contains the compiled app, dependency/build/test logs, Xcode result bundle,
launch and system logs, and startup screenshot. GitHub retains these run
artifacts until 25 October 2026; downloaded copies were also delivered separately.

New device executable SHA-256:
`31a3b0bb0279dcab53db9cb4c3ef2bdfc249c651762382f920d38e682de062f1`.
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
