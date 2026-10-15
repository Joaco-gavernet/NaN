# Contributing to NaN

This repository is used as contest infrastructure. Prefer small, testable changes
with clear assumptions. Search existing issues and pull requests before opening
new work. English and Spanish are both welcome.

## Source placement

- Put reusable snippets under `algorithms/<topic>/` with lowercase `snake_case`
  filenames. Preserve algorithm names, attribution, and applicable licenses.
- The [library index](algorithms/README.md) lists all available implementations.
  Update it when adding, removing, or renaming a source.
- The [World Finals manifest](notebook/world_finals.toml) selects library paths in
  print order. Add or remove an entry there to change the curated notebook.
- Edit shared sources directly. Do not create a second event copy to carry a fix.
- Keep genuinely distinct implementations explicit. Review the
  [consolidation inventory](docs/library_consolidation.md) before merging variants.
- Use `templates/` for solution setup, `study/` for educational material, and
  `tools/stress/` for manual contest helpers. Automated checks belong in `tests/`.
- `archive/` is frozen historical material; changes there do not update the current
  notebook. `build/` is disposable generated output and must not be committed.

## Algorithm changes

Document the problem, input assumptions, indexing, complexity, edge cases, and
source or derivation. Adapted material must retain compatible licensing and
attribution. By contributing you agree to the repository's MIT license.

Prefer meaningful regression tests or a brute-force comparison. An implementation
being in the library does not establish correctness. When changing one variant,
explicitly check whether the same bug affects other implementations.

## Validation

Run the [documented checks](tests/README.md), then build the PDF when selected
sources, selection, or layout change:

```bash
python3 scripts/build_notebook.py
```

Inspect `build/world_finals/notebook.pdf` for readable code, correct section
ordering, and the event's page limit. Generated code copies preserve source bytes;
formatting belongs in the notebook presentation, not a rewritten algorithm tree.

## Pull requests

Explain the problem, resulting behavior, assumptions, validation, and provenance.
Link the relevant issue. Structural changes or substantial notebook-content changes
should be discussed in an issue. Keep algorithm behavior changes separate from
layout-only changes. All pull requests require human review before merging.
