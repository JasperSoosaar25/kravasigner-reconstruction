# Working in this repository

This is an unofficial KravaSigner reconstruction and a base for community features. Preserve the distinction between recovered evidence, reference implementation and newly added behavior.

- Read `docs/DEVELOPMENT.md` and `CONTRIBUTING.md` before feature work.
- Use development mode for features: `bash scripts/check.sh development` and `bash scripts/build.sh simulator development` (macOS/Xcode 26.0.1).
- Baseline comparisons are optional historical audits. Do not change original evidence or recovered resources to make a new feature match the old executable.
- Edit resources under `Feather/Resources/`; development builds compile them normally.
- Preserve licenses and attribution. Do not commit private signing inputs, pairing files, tokens, generated app binaries or personal data.
- Add regression tests for meaningful behavior changes. Report what was tested and any runtime limits; never claim official source or full equivalence.
