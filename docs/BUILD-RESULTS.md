# Verified source builds and simulator run

Verified on 11 October 2026 in the owner's private repository:
[JasperSoosaar25/kravasigner-reconstruction](https://github.com/JasperSoosaar25/kravasigner-reconstruction).

The successful [GitHub Actions run 38128927828](https://github.com/JasperSoosaar25/kravasigner-reconstruction/actions/runs/38128927828)
tested source commit `d97d268d669c33ab9826d0c74080c909d6eb85bb`.
Both jobs succeeded; total run duration was 7 minutes 18 seconds. Documentation-only
updates after this commit do not change the tested app or workflow.

| Check | Actual result |
|---|---|
| Toolchain | macOS 15.7.9 ARM64 runner, Xcode 26.0.1 (17A400), iOS 26.0 SDK |
| iOS device build | Source compilation succeeded; job 114439017691 |
| iOS simulator build | Source compilation succeeded; job 114439017556 |
| TLS fixtures | Four tests passed in both jobs: success/request policy, second-request failure, invalid UTF-8, filesystem failure |
| Product identity | KravaSigner 2.8.2/build 1, com.kravasign.KravaSigner; platform metadata appropriate to each product |
| Original runtime resources | All 66 files independently hash-checked in the downloaded device and simulator products |
| Compiled app metadata | All 106 recovered original nominal names and stored-field names match; CI and independent downloaded-executable check passed |
| Extended compiled structure | All 106 kinds/descriptor flags, 462 field/case records and recorded superclass types match; stronger CI step and independent downloaded-product check passed |
| Complete reflection-name section | 98,071 bytes, 7,060 nonempty strings, byte-identical to original |
| Whole app file paths | Zero unexplained omissions, zero added paths; only seven private inputs and unsigned main signature absent |
| Simulator startup | Installed and launched, PID 26698, alive after the 10-second startup check |
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
Compared 106 app types and 462 field-type records
0 structural differences; 0 unresolved type references
PASS type kinds, descriptor flags, field flags/types and superclass references match
PASS 135 archive entries; 87 recovered source files compared directly
device: 66 original runtime files exact; 0 unexplained omissions; 0 added app paths
simulator: 66 original runtime files exact; 0 unexplained omissions; 0 added app paths
com.kravasign.KravaSigner: 26698
PASS app launched and remained alive through startup
```

## Downloaded artifacts

| Artifact | Size (bytes) | SHA-256 |
|---|---:|---|
| KravaSigner-reconstructed-unsigned.ipa | 13,612,196 | 9adc52854b5490e069c19a4219629aaeea8744a7aa1444391be6581fd7ae78e2 |
| KravaSigner-device-build.zip | 28,091,707 | 6f9fdbd2765aa597a6925eb395cc2770398c8d8fa846d71d789614e9cd9ecd71 |
| KravaSigner-simulator-build.zip | 26,699,923 | aca16f6c9710c4fbd2ec715b8d6e81c2f44f4f523a7a225e6bd914cb336bff05 |

The ZIP digests match GitHub's artifact digests. The device ZIP contains the
unsigned IPA, dependency/build/test logs, compiled name/field and extended structure JSON and Xcode result bundle. The simulator
ZIP contains the compiled app, dependency/build/test logs, Xcode result bundle,
launch and system logs, and startup screenshot. GitHub retains these run
artifacts until 25 October 2026; downloaded copies were also delivered separately.

New device executable SHA-256:
`4c0e43a50564db6e448b6c2fc16d9ac41dfcaf8448f04ca509f3157142db701d`.
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

The earlier correction itself was verified in run [38126989899](https://github.com/JasperSoosaar25/kravasigner-reconstruction/actions/runs/38126989899) at `edad40232beca7ce0cd81363fc14812e0a8ca3b0`. This latest continuation adds deeper audit tooling and workflow checks; it makes no further app implementation changes. See `EXTENDED-STRUCTURE.md` for the additional original-data recovery and checker validation.
