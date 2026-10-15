# Automated checks

From the repository root:

```bash
python3 -m compileall -q scripts algorithms tests tools
python3 scripts/validate_notebooks.py
python3 -m unittest discover -s tests -p 'test_*.py'
python3 scripts/build_notebook.py --sources-only
g++ -std=gnu++20 -Wall -Wextra -Werror tests/smoke.cpp -o /tmp/nan-smoke
/tmp/nan-smoke
g++ -std=gnu++20 -O2 -Wall -Wextra -Werror -fsanitize=undefined -fno-sanitize-recover=undefined tests/factorization.cpp -o /tmp/nan-factorization
/tmp/nan-factorization
```

Use GNU g++ (for example `g++-16` on Homebrew), including support for `__int128`.
The smoke checks include editable sources directly. Factorization tests cover
issue #9, small inputs against a sieve, pseudoprimes, and large factorizations.
Python tests exercise selection validation, source preservation, ordering, stale
build cleanup, and documentation-link checks. They do not require LaTeX.

Most snippets still need individual correctness tests. Being in the library or
the World Finals selection is not a claim of exhaustive validation.
