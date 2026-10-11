# Community preparation and verified builds

Prepared on 11 October 2026. The app is ready as a documented community development base, with explicit reconstruction limits. This is not a claim of official source recovery or complete runtime equivalence.

## What changed

- Replaced Feather-directed contribution instructions and issue forms with instructions for this repository, four issue forms and a PR template.
- Added a code map, fork/local/Actions build instructions, owner branch instructions, license/attribution notice, security reporting guide, contributor guidance for coding agents and possible starting ideas.
- Made **development** the default in Xcode, the CLI and normal CI. It compiles editable resources and permits new types/fields, theme and translation changes. Original binary equality is not a feature gate.
- Kept **baseline** as an explicit Actions/CLI mode, with original-resource restoration and both device metadata checks. The `reconstruction-baseline` branch retains the tested code snapshot.
- Preserved the original distributed config separately under `RecoveredResources/Bundle/Feather.xcconfig`, leaving the root config editable. All 87 resource/reference files and 135 original archive entries still compare directly with the owner IPA.
- Added regression tests for editable catalog retention, strict baseline restoration, new versions/identity, invalid platforms/missing executables, contributor theme/translation changes and continued private-input rejection.
- Cleaned generated products/results before rebuilding so switching modes cannot retain a previous original catalog; refreshed the provenance inventory and verified the common-reference Git patch.

## Fresh verification

Tested code/tooling commit: `7ccc41112517bed65e293a71c4dee0f586d1e51d`, tree `b443be9e1be38a79fa70a83af98d385b638c9b95`. The final follow-up commit changes documentation/evidence only.

| Check | Result |
| --- | --- |
| [Contributor checks, run 38132628642](https://github.com/JasperSoosaar25/kravasigner-reconstruction/actions/runs/38132628642) | Success on Ubuntu |
| [Development builds, run 38132628569](https://github.com/JasperSoosaar25/kravasigner-reconstruction/actions/runs/38132628569) | Device and simulator success; actual simulator startup passed |
| [Baseline builds, run 38132707703](https://github.com/JasperSoosaar25/kravasigner-reconstruction/actions/runs/38132707703) | Device and simulator success; both compiled-device metadata checks and actual simulator startup passed |
| Downloaded development device product | GitHub digest verified; root editable config retained; freshly compiled catalog differs from the original compiled catalog |
| Downloaded development simulator product | Digest verified; launch log records PID 20722 and startup success; actual screenshot inspected |
| Downloaded baseline products | Both digests verified; each preserves all 66 runtime resource files, with zero unexplained omissions or added app paths |
| Independent baseline executable comparison | 106 app types / 462 reflection records, zero structural differences and zero unresolved references in the selected inventory |
| Local checks | Development and baseline source validation, three build-mode regression tests, shell syntax, workflow/issue-form YAML and document links passed |

The development IPA digest is `99d0ca7fbd192df7889cdda3726a01b1bbba8d4f51155b04474016586bd219e0`. Its retained newly compiled catalog digest is `439a4083fbd24c81446a2c8da618d0eac7d617126df40ffc6fd4ffbf1d6abdb5`. The original executable was not an input to either source build. Complete build/test logs and Xcode result bundles are retained in each run's artifacts. Artifacts expire according to GitHub retention; the workflows can build fresh ones.

Machine-readable observations: [community-readiness.json](evidence/community-readiness.json). Earlier recovery comparisons remain in [BUILD-RESULTS.md](BUILD-RESULTS.md), [DOUBLE-CHECK.md](DOUBLE-CHECK.md) and [EXTENDED-STRUCTURE.md](EXTENDED-STRUCTURE.md).

## Publication review

Reviewed the complete eight-commit history that existed before community preparation: 465 unique blob contents, current source paths and historical paths. A bounded scan found no GitHub-token, AWS-key or encoded private-key patterns. Five full historical device/failed-job logs and all 15 retained simulator artifact log files were scanned; simulator app bundles contained no private signing inputs. Three full simulator job-log wrappers could not be retrieved because the connector returned `Transport closed`; their artifact logs and bundles were inspected instead. Current tracked source contains no private signing/pairing paths or credential-pattern findings.

These are bounded checks, not a guarantee against every possible form of confidential data. The owner's original IPA and seven private signing/profile inputs remain outside the repository. The CI workflows use read-only permissions, pinned actions, no signing secrets and ordinary `pull_request`; they do not publish releases. Repository visibility is changed after the final preparation commit. Issues and pull requests are available to contributors; GitHub's first-time fork workflow approval can still apply.

The source GPL and third-party notices are retained. Recovered asset/branding rights are explicitly distinguished in [NOTICE](../NOTICE.md); the project does not claim official affiliation or ownership of every recovered asset.

## Practical limits

Full UI behavior, data migrations and real-device signing/installation still need validation for relevant feature changes. Startup success does not establish those paths. Original method and SwiftUI bodies, original authoring comments/history and whole-program equivalence remain unrecovered. Use the [development guide](DEVELOPMENT.md) to build features without erasing historical evidence.
