# NaN (Need a Name)

NaN is a curated competitive-programming notebook maintained by the UNLP team
of the same name. It collects contest-ready C++ and Python implementations,
short reference notes, notebook-generation scripts, and stress-testing helpers.

![NaN](https://github.com/user-attachments/assets/840fa37a-41f8-494f-88a4-5974a97dbd55)

The project exists to make hard-won algorithmic knowledge reviewable and
reusable. Correctness matters more than snippet count: every contribution
should state its assumptions and complexity and, whenever practical, include a
test or a brute-force comparison.

## Team and ecosystem

Team NaN represents the Universidad Nacional de La Plata (UNLP). The team:

- competed at the 2025 ICPC World Finals in Baku and earned an honorable
  mention;
- qualified for the 2026 ICPC World Finals in Dubai, its second consecutive
  World Finals qualification; and
- develops these materials alongside UNLP's competitive-programming community.

UNLP maintains an extracurricular competitive-programming workshop with more
than 30 students. We want this repository to become useful beyond one team: a
clear, testable reference for students and ICPC teams in Argentina and Latin
America.

Sources: [UNLP's 2026 qualification announcement][unlp-2026] and
[UNLP Radio's 2025 World Finals report][unlp-2025].

## Find an algorithm

- **[Full algorithm library](algorithms/README.md):** everything available to study
  or use, including algorithms outside the contest selection.
- **[World Finals notebook](notebook/README.md):** the pruned selection, defined by
  an ordered manifest referencing the library.
- **[Latest published release](https://github.com/Joaco-gavernet/NaN/releases/latest):**
  downloadable PDFs for tagged snapshots. A published PDF may predate changes on
  `main`; build locally for the current selection.

| Directory | What belongs here |
| --- | --- |
| [algorithms/](algorithms/README.md) | Maintained algorithm sources, organized by topic |
| [notebook/](notebook/README.md) | World Finals selection, display order, LaTeX layout, cheatsheets |
| [templates/](templates/README.md) | Contest setup and solution templates |
| [tests/](tests/README.md) | Automated correctness and build checks |
| [tools/stress/](tools/stress/README.md) | Manual stress-testing helpers |
| [study/](study/) | Notes and practice problems |
| [scripts/](scripts/) | Build and repository validation |
| [docs/](docs/) | Maintenance, releases, and consolidation decisions |
| [archive/](archive/README.md) | Historical snapshots and retired material |
| `build/` | Generated output, ignored by Git |

The full library and the World Finals notebook share sources. Adding an algorithm
makes it available in the library; selecting its path in
[world_finals.toml](notebook/world_finals.toml) includes it in the notebook.
Distinct implementations retained during consolidation have explicit `_wf26`
variants. See the [consolidation review](docs/library_consolidation.md) for recent
changes from the broader collection that still need review before promotion.

## Build the World Finals notebook

Requires Python 3.11+ and either Tectonic or latexmk with pdflatex:

```bash
python3 scripts/build_notebook.py
```

The result is `build/world_finals/notebook.pdf`. Tectonic may download its package
bundle on its first run. Source copies and intermediate output stay under `build/`;
there are no generated mirrors beside the maintained sources.

To generate the notebook sources without LaTeX:

```bash
python3 scripts/build_notebook.py --sources-only
```

## Validate changes

```bash
python3 -m compileall -q scripts algorithms tests tools
python3 scripts/validate_notebooks.py
python3 -m unittest discover -s tests -p 'test_*.py'
g++ -std=gnu++20 -Wall -Wextra -Werror tests/smoke.cpp -o /tmp/nan-smoke
/tmp/nan-smoke
g++ -std=gnu++20 -O2 -Wall -Wextra -Werror -fsanitize=undefined -fno-sanitize-recover=undefined tests/factorization.cpp -o /tmp/nan-factorization
/tmp/nan-factorization
```

Use GNU g++; on Homebrew its executable may be named `g++-16`.
See [tests](tests/README.md) for coverage and limitations. Most snippets still
need dedicated correctness tests.

## Contributing and releases

Start with [CONTRIBUTING.md](CONTRIBUTING.md). Contributions should state
assumptions, preserve attribution, and include useful tests. Keep changes small
enough to review. Pull requests require human review.

See the [roadmap](docs/roadmap.md) and [release process](docs/releasing.md).
Event snapshots use calendar-oriented versions such as `v2026.1`.

## License

NaN is available under the [MIT License](LICENSE). Third-party material must
retain its attribution and use a compatible license.

[unlp-2025]: https://www.radiouniversidad.unlp.edu.ar/estudiantes-de-la-unlp-fueron-premiados-en-mundial-de-programacion/
[unlp-2026]: https://unlp.edu.ar/institucional/estudiantes-de-la-unlp-en-la-final-de-un-certamen-internacional-de-programacion-119503/
