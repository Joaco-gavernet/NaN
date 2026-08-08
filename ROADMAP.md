# Maintenance roadmap

This roadmap describes maintenance work, not contest commitments. Priorities may
move as the team prepares for events or discovers correctness issues.

## Release `v2026.1`: OSS-ready foundation

- [x] Confirm contributor agreement and publish a project-wide open-source
  license.
- [x] Document the repository structure, build process, and contribution rules.
- [x] Add lightweight CI for Python syntax, generated-notebook integrity, and
  representative C++ smoke tests.
- [x] Verify the current WF26 and PDA26 notebooks compile from canonical
  sources.
- [ ] Make the PDF build deterministic in a clean environment.
- [ ] Publish the current World Finals notebook as a tagged GitHub release.

## Expand correctness coverage

- Audit current snippets for provenance and preserve compatible upstream
  attribution.
- Add a manifest recording each canonical snippet's owner, provenance,
  complexity, assumptions, and test status.
- Grow the C++ smoke suite across graphs, geometry, number theory, strings, and
  data structures.
- Add property-based and differential tests for algorithms with practical
  brute-force oracles.
- Eliminate duplicated canonical implementations while preserving historical
  event snapshots.

## Improve the maintainer workflow

- Introduce issue forms for bug reports and algorithm proposals.
- Automate notebook-diff summaries for pull requests.
- Prototype human-approved, Codex-assisted review notes for complexity,
  assumptions, suspicious edge cases, and missing tests.
- Publish reusable CI and review tooling so other ICPC teams can adopt it.

## Non-goals

- Automatically merging generated or AI-written algorithm implementations.
- Claiming complete correctness coverage before every snippet has a dedicated
  test and provenance record.
- Rewriting historical event snapshots solely to match the current layout.
