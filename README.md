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

## Current notebook

The current competition snapshot is
[`Notebook_WF26/UNLP-NAN-Notebook.pdf`](Notebook_WF26/UNLP-NAN-Notebook.pdf).
Its editable sources live in [`Notebook_WF26/`](Notebook_WF26/).

The repository also preserves earlier or event-specific snapshots:

| Directory | Purpose |
| --- | --- |
| [`Notebook C++/`](Notebook%20C%2B%2B/) | Original, broader C++ notebook |
| [`Notebook_WF/`](Notebook_WF/) | Previous World Finals snapshot |
| [`Notebook_PDA26/`](Notebook_PDA26/) | Programadores de América 2026 snapshot |
| [`Notebook_WF26/`](Notebook_WF26/) | Current World Finals 2026 snapshot |
| [`Apuntes/`](Apuntes/) | Topic notes and worked examples |
| [`Guia_Problemas/`](Guia_Problemas/) | Practice-problem material |

Within the newer snapshots, editable algorithm sources live in topic folders
such as `grafos/`, `geometry/`, and `strings/`. Folders ending in `_clean` are
generated compact copies used by the PDF builder; do not edit them directly.

## Build a notebook

Requirements:

- Python 3.10 or newer;
- `latexmk` and a LaTeX distribution with `pdflatex`; and
- a POSIX-compatible shell.

To rebuild the current notebook:

```bash
cd Notebook_WF26
./gen.sh
```

The generator refreshes the `_clean` directories, assembles `estufa.tex`, and
builds `estufa.pdf`. Review all generated changes before committing them.

## Validate changes

The lightweight checks used in CI can be run locally without LaTeX:

```bash
python3 -m compileall -q scripts Notebook_WF26 Notebook_PDA26 Notebook_WF "Notebook C++"
python3 scripts/validate_notebooks.py
g++ -std=gnu++20 -Wall -Wextra -Werror tests/smoke.cpp -o /tmp/nan-smoke
/tmp/nan-smoke
```

The smoke test compiles and exercises representative snippets directly from the
current notebook. It does not yet prove every snippet correct; expanding that
coverage is part of the [maintenance roadmap](ROADMAP.md).

## Contributing

Contributions are welcome. Start with [CONTRIBUTING.md](CONTRIBUTING.md), which
explains source placement, provenance requirements, testing, and review. Pull
requests should be small enough to reason about and will be merged only after
human review.

## Releases and maintenance

See [ROADMAP.md](ROADMAP.md) for current priorities and [RELEASING.md](RELEASING.md)
for the release process. Event snapshots use calendar-oriented versions such as
`v2026.1`.

## License status

A project-wide open-source license is being finalized with contributors. Until
a `LICENSE` file is added, the repository is public for review but does not
grant general reuse rights. Third-party material must retain its attribution
and use a compatible license.

[unlp-2025]: https://www.radiouniversidad.unlp.edu.ar/estudiantes-de-la-unlp-fueron-premiados-en-mundial-de-programacion/
[unlp-2026]: https://unlp.edu.ar/institucional/estudiantes-de-la-unlp-en-la-final-de-un-certamen-internacional-de-programacion-119503/
