# Stress-testing helpers

- [diff](diff/README.md): generators, candidate solution, brute-force solution,
  and a Bash runner comparing their output.
- [checker](checker/stress.sh): the original checker-based workflow and examples.

These are preserved contest helpers, separate from the automated checks in
[tests](../../tests/README.md). Run each workflow from its own directory. The
checker workflow expects a local `compile` shell function in `~/.bashrc`; review
and adapt it before running. Neither workflow runs in CI.
