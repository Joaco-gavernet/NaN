# Release process

Use calendar-oriented versions for event snapshots, such as `v2026.1`.

1. Start from an up-to-date, clean `main` branch.
2. Review `notebook/world_finals.toml` and the event's page-limit requirements.
3. Run the [validation commands](../tests/README.md).
4. Build with `python3 scripts/build_notebook.py` from the repository root.
5. Inspect `build/world_finals/notebook.pdf`, then update the changelog and commit
   the sources, manifest, tests, and documentation through a reviewed pull request.
6. After merging, tag the exact commit and rebuild from that checkout. Publish
   the PDF as a release asset; do not commit it as a mutable source-tree artifact.

Example commands after selecting an unused release version:

```bash
version=v2026.2
git tag -a "$version" -m "NaN notebook $version"
git push origin "$version"
python3 scripts/build_notebook.py
gh release create "$version" \
  'build/world_finals/notebook.pdf#World Finals notebook' \
  --title "NaN notebook $version" \
  --notes-from-tag
```

Tags preserve the library and selection together. A later fix updates every
manifest referencing that source when rebuilt, but does not rewrite a published
release. For another event, create a separate manifest referencing the shared
library; do not duplicate the source tree. The build accepts `--manifest PATH`.
