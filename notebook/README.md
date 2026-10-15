# World Finals notebook

[world_finals.toml](world_finals.toml) is the ordered, pruned selection from the
[full algorithm library](../algorithms/README.md). It contains paths and display
titles, not copied implementations. Adding a library algorithm does not add it
to the printed notebook; adding an entry here does.

Build from any working directory:

```bash
python3 /path/to/NaN/scripts/build_notebook.py
```

From the repository root, the shorter command is:

```bash
python3 scripts/build_notebook.py
```

Requires Python 3.11+ and Tectonic, or latexmk with pdflatex. Output goes to
`build/world_finals/notebook.pdf`; sources and intermediate files are also under
that ignored directory. `--sources-only` generates TeX and selected source copies
without a TeX installation. Rebuilding replaces that notebook's build directory.

Entries are printed in manifest order. Each entry has a repository-relative
`path` and a readable `title`. A section may also include a `cheatsheet` TeX path.
The current selection preserves the previous WF26 membership and order, including
the exclusion of trie. The full library still contains trie.

Source copies are byte-for-byte identical to the library. Blank lines are hidden
by the listings presentation settings; preprocessor directives are preserved.
Python string contents and indentation are never rewritten. Titles do not depend
on filenames, so renaming an algorithm does not force a cryptic PDF heading.

For a future event, create a new manifest selecting library paths. To freeze an
event, tag its commit and publish its built PDF. Historical snapshots in
[archive](../archive/README.md) are not additional maintained implementations.
