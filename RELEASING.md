# Release process

NaN uses calendar-oriented versions for maintained event snapshots. The first
documented release is planned as `v2026.1`.

## Prepare

1. Start from a clean, up-to-date `main` branch.
2. Confirm the release checklist in `ROADMAP.md` is complete.
3. Run the lightweight validation suite from `CONTRIBUTING.md`.
4. Rebuild the current notebook from `Notebook_WF26/` with `./gen.sh`.
5. Review generated source and PDF changes, then commit them through a pull
   request.
6. Move the relevant `CHANGELOG.md` section from `Unreleased` to the release
   version and date.

## Tag and publish

After the release pull request is merged:

```bash
git switch main
git pull --ff-only
git tag -a v2026.1 -m "NaN notebook v2026.1"
git push origin v2026.1
gh release create v2026.1 \
  Notebook_WF26/UNLP-NAN-Notebook.pdf \
  --title "NaN notebook v2026.1" \
  --notes-from-tag
```

Before publishing, confirm that the PDF corresponds exactly to the tagged
commit and that no release notes overstate the project's test coverage.
