# Security Policy

## Scope

The Behavior Reconstruction Engine is intended for:

* defensive security research;
* malware analysis;
* reverse engineering;
* security engineering;
* academic research;
* authorized testing.

## Reporting a Vulnerability

If you discover a security vulnerability in the project, please do not immediately publish exploit details in a public issue.

Instead, report the issue privately through the security reporting mechanism provided by the repository.

Include, when possible:

* affected component;
* affected version or commit;
* description of the vulnerability;
* reproduction steps;
* security impact;
* suggested mitigation.

## Sensitive Data

Do not include the following in public issues or pull requests:

* credentials;
* API keys;
* private tokens;
* personally identifiable information;
* confidential malware samples;
* proprietary customer data;
* private network information.

Use sanitized or synthetic data when demonstrating problems.

## Malware Samples

Malware samples should not be committed to this repository.

Use hashes, metadata, sanitized telemetry, or synthetic test fixtures whenever possible.

## Security Boundaries

The project may process security telemetry and malware-analysis output.

This does not imply that every input is trustworthy.

Input parsers and ingestion components should be designed under the assumption that external data may be:

* malformed;
* incomplete;
* inconsistent;
* unexpectedly large;
* intentionally adversarial.

Security-sensitive parsers should therefore validate input and fail safely.

## Responsible Use

Users are responsible for ensuring that their use of the project complies with applicable laws, policies, and authorization requirements.
