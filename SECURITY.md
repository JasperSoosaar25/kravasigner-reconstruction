# Reporting security problems

The app handles signing material, downloaded apps and local installation services. This is an unofficial reconstruction, with incomplete recovery and limited runtime testing; see `docs/STATUS.md` and `docs/BUILD-RESULTS.md`.

Do not post real signing keys, `.p12`/`.pfx` files, profiles, pairing records, tokens, private IPAs or unredacted logs in public issues. Use invented or redacted examples and describe the affected commit, path and steps to reproduce.

If GitHub's **Security → Report a vulnerability** control is available, use that private channel for details that could expose users. Otherwise open a minimal issue asking for a private reporting channel, without exploit details or secrets. Maintainers do not promise a response time or a supported security-release schedule. GitHub reporting controls can be used for accidentally exposed content.

Contributions must preserve TLS verification, credential isolation and stock-iOS compatibility. CI runs without signing secrets and does not use `pull_request_target` to execute contributor code.
