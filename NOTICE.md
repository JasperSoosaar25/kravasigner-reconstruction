# Attribution and licensing

This repository is an unofficial reconstruction and community development base. It is not published or endorsed by KravaSign or the Feather maintainers.

The application/reference source is derived from **Feather v2.8.2**, commit `1a9b2bbcc7ebe0fbbf76fec45ec1e94ff0c4edc4`, by its respective authors, under **GNU GPL version 3**. The complete license is retained in [LICENSE](LICENSE); original file copyright notices and the [reference README](docs/FEATHER-UPSTREAM-README.md) are retained. Newly written application changes, audit/build tooling, tests and project documentation in this reconstruction are made available under GPL-3.0, subject to existing third-party notices.

## Included packages and runtime components

| Component | License/notice retained here |
| --- | --- |
| AltSourceKit | `AltSourceKit/LICENSE` (MIT) |
| NimbleKit | `NimbleKit/LICENSE` (MIT) |
| Zsign package | `Zsign/LICENSE`, `Zsign/LICENSE_LC` and original source notices |
| IDeviceKitten | `IDeviceKitten/LICENSE` and its package/dependency notices |
| ElleKit runtime resource | `LICENSE_ELLEKIT` |
| Remote Swift packages and native frameworks | Pinned package manifests/lockfiles and their respective upstream licenses; bundled acknowledgements are retained in the resource inventory |

Check the component's actual license before reusing it separately. The repository-wide GPL statement does not replace a third-party license.

`RecoveredResources/` contains bytes distributed in the supplied original app, including artwork, translations and compiled resources. Their presence and provenance do not establish that the original publisher licensed every asset under GPL. Original third-party copyright, artwork/branding and trademark rights remain with their respective owners; this project does not claim ownership or grant rights it does not have. Forks that need independent branding should supply artwork they have permission to use in the editable resource tree. Development builds support that without replacing original audit evidence.

## Distributing a fork

Retain the GPL and copyright/license notices, identify your changes, and provide the corresponding source under the applicable license when distributing a GPL-covered modified app. Native prebuilt dependencies remain separately documented; see their pinned packages for source and license terms. Never distribute someone else's signing keys, provisioning profiles, passwords or pairing records.

Being derived from GPL software does not by itself establish the original publisher's compliance or force it to host a public GitHub repository. The GPL's source obligations depend on distribution and the covered work. This reconstruction is not the publisher's corresponding-source release.

Primary references: [GPLv3](https://www.gnu.org/licenses/gpl-3.0.html) and the [GNU license FAQ](https://www.gnu.org/licenses/gpl-faq.html#GPLRequireSourcePostedPublic).
