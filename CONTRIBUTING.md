# Contributing

Thank you for your interest in contributing to the Behavior Reconstruction Engine.

This project is currently in an early research and engineering phase. Contributions that improve correctness, documentation, testing, architecture, interoperability, or analysis quality are welcome.

## Before Contributing

Please read:

* `README.md`
* `ROADMAP.md`
* `docs/architecture/`
* `docs/research/`
* `docs/decisions/`

For substantial architectural changes, open an issue or discussion before implementing the change.

## Development Philosophy

We prefer:

```text
Evidence
    ↓
Reasoning
    ↓
Implementation
    ↓
Tests
    ↓
Documentation
```

over implementing functionality without documenting why it exists.

## Code Contributions

When submitting code:

1. Keep changes focused.
2. Avoid unrelated refactoring.
3. Add tests for new behavior.
4. Update documentation when behavior or architecture changes.
5. Explain important design decisions.
6. Avoid unnecessary dependencies.
7. Keep the public API minimal and understandable.

## C Guidelines

The core project is written in C.

Code should prioritize:

* correctness;
* explicit ownership;
* predictable memory management;
* portability where practical;
* clear interfaces;
* defensive error handling;
* readable naming;
* small functions;
* testability.

Memory ownership should be clear from the API.

Avoid hiding important allocation or ownership behavior behind unnecessarily complicated abstractions.

## Commit Messages

Use concise, descriptive commit messages.

Preferred prefixes include:

```text
feat:
fix:
test:
docs:
refactor:
perf:
build:
chore:
```

Examples:

```text
feat: add canonical event identifier
test: validate event initialization
docs: document event ownership
fix: reject invalid event type
refactor: separate evidence from event model
```

## Documentation

Documentation is considered part of the implementation.

When a change modifies architecture, behavior, interfaces, or assumptions, update the relevant documentation in the same change whenever possible.

## Architecture Decisions

Significant decisions should be documented as an ADR under:

```text
docs/decisions/
```

An ADR should explain:

* Context
* Problem
* Alternatives
* Decision
* Consequences

## Tests

New functionality should include appropriate tests.

Tests should verify behavior rather than implementation details whenever practical.

## Pull Requests

A pull request should explain:

### What changed?

A concise summary.

### Why?

The problem being solved.

### How?

The implementation approach.

### Evidence

Tests, examples, benchmarks, research, or other evidence supporting the change.

### Documentation

Identify relevant documentation updates.

## Research Contributions

Research contributions should distinguish between:

```text
Observed evidence
```

```text
Interpretation
```

```text
Hypothesis
```

Do not present an unvalidated hypothesis as an established fact.

## Security Research

Security research must be performed in authorized environments.

Do not submit credentials, private data, proprietary malware samples, or sensitive information to the repository.

## Questions

For uncertain architectural decisions, open a discussion before implementing a large change.

The goal is not merely to add features.

The goal is to build a technically defensible system whose conclusions remain traceable to evidence.
