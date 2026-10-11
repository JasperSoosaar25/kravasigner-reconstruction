# Contributing to KravaSigner reconstruction

You can fork this project, add features, fix bugs, improve accessibility or translations, and send a pull request here. First-time contributors and small changes are welcome. This is an unofficial community reconstruction; see [recovery coverage](docs/RECOVERY-COVERAGE.md) for the parts that remain uncertain.

## Your first contribution

If you own this repository, clone it directly and work on a feature branch. Other contributors start with a fork.

1. Fork [this repository](https://github.com/JasperSoosaar25/kravasigner-reconstruction/fork).
2. Clone your fork. The local packages are included; recursive submodule cloning is unnecessary.
3. Create a branch, for example `git switch -c feature/source-search`.
4. Follow the [development guide](docs/DEVELOPMENT.md), make your change and run `bash scripts/check.sh development`.
5. Build the app on macOS or run **Build KravaSigner** with mode **development** in your fork's Actions tab. Include what you tested and screenshots for visible UI changes.
6. Commit, push your branch and open a pull request against this repository's `main` branch. Use the PR template to describe the problem and resulting behavior.

For a larger design, database change or change to installation/signing, open a feature issue first so people can agree on the direction. A small typo or isolated bug fix can go directly to a PR. There is no requirement to contribute to Feather before contributing here.

## Development and audit builds

**Development** is the default for Xcode, the build script and normal CI. It compiles editable artwork, translations, launch screen and database models. New types/properties and features are allowed; old compiled type equality is not a feature gate.

**Baseline** is an explicit reconstruction audit. It restores the distributed original resources and compares the device executable's selected metadata with the original. Use `bash scripts/build.sh device baseline` or select baseline in Actions. Feature changes can intentionally fail that comparison. Do not edit the original snapshots to make a feature pass. Historical evidence remains historical.

Keep `RecoveredResources/` and original evidence intact. Describe newly added behavior as new behavior. Evidence changes need a clear explanation and the input digest/method that supports them.

## Review expectations

- Keep a PR focused and describe the visible behavior or failure it improves.
- Use the existing SwiftUI and service/storage patterns; keep views readable and asynchronous network work off the main thread.
- Check light/dark appearance, Dynamic Type, VoiceOver labels, loading/empty/error states and the supported iOS versions relevant to the change.
- Add meaningful regression tests for behavior changes; avoid tests that merely repeat the implementation. Documentation-only changes need no new tests.
- Treat certificate material, pairing records, tokens and user app data as private. Use invented fixtures. Do not upload private inputs in issues, PRs, logs or screenshots.
- Preserve stock-iOS compatibility. Do not contribute exploits, piracy features or retrieval of signing credentials belonging to other people or organizations.
- Preserve existing copyright/license notices. App changes and new project tooling are contributed under GPL-3.0; vendored package changes retain their package's license. You must have the right to contribute the content. See [NOTICE](NOTICE.md).

CI uses read-only repository permissions and no signing secrets. GitHub may ask a maintainer to approve a first-time fork's workflow run. Passing checks helps review; it does not automatically merge a PR.

Please follow the [Code of Conduct](CODE_OF_CONDUCT.md). Ideas and friendly questions are welcome through the issue forms. Maintainers cannot promise a response time or acceptance of every proposal.
