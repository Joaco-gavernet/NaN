#!/usr/bin/env python3
"""Validate generated notebook mirrors and lightweight repository invariants."""

from __future__ import annotations

import re
import sys
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
ACTIVE_NOTEBOOKS = {
    "Notebook_WF26": (
        "grafos",
        "data_structures",
        "dp",
        "general",
        "geometry",
        "math",
        "number_theory",
        "Python",
        "strings",
        "tree",
    ),
    "Notebook_PDA26": (
        "grafos",
        "data_structures",
        "dp",
        "general",
        "geometry",
        "math",
        "number_theory",
        "Python",
        "strings",
        "tree",
    ),
}
TEXT_SUFFIXES = {".cpp", ".h", ".hpp", ".md", ".py", ".sh", ".tex"}
REFERENCE_PATTERN = re.compile(r"\\(?:cpp|python)file\{([^}]+)\}")
CONFLICT_MARKER_PATTERN = re.compile(
    r"^(?:<{7} |={7}\s*$|>{7} )", re.MULTILINE
)


def compact_source(text: str) -> str:
    """Match the transformation performed by the current limpiar.py scripts."""

    return "".join(
        line
        for line in text.splitlines(keepends=True)
        if line.strip() and not line.startswith("#")
    )


def validate_clean_mirrors(errors: list[str]) -> int:
    checked = 0
    for notebook_name, sections in ACTIVE_NOTEBOOKS.items():
        notebook = ROOT / notebook_name
        for section in sections:
            source_dir = notebook / section
            clean_dir = notebook / f"{section}_clean"
            if not source_dir.is_dir() or not clean_dir.is_dir():
                errors.append(
                    f"{notebook_name}: missing {section}/ or {section}_clean/"
                )
                continue

            source_files = {path.name for path in source_dir.iterdir() if path.is_file()}
            clean_files = {path.name for path in clean_dir.iterdir() if path.is_file()}
            if source_files != clean_files:
                missing = sorted(source_files - clean_files)
                stale = sorted(clean_files - source_files)
                if missing:
                    errors.append(
                        f"{notebook_name}/{section}_clean: missing {', '.join(missing)}"
                    )
                if stale:
                    errors.append(
                        f"{notebook_name}/{section}_clean: stale {', '.join(stale)}"
                    )

            for name in sorted(source_files & clean_files):
                source = (source_dir / name).read_text(encoding="utf-8")
                clean = (clean_dir / name).read_text(encoding="utf-8")
                if compact_source(source) != clean:
                    errors.append(
                        f"{notebook_name}/{section}_clean/{name}: regenerate with limpiar.py"
                    )
                checked += 1
    return checked


def validate_tex_references(errors: list[str]) -> int:
    checked = 0
    for notebook_name in ACTIVE_NOTEBOOKS:
        notebook = ROOT / notebook_name
        tex_path = notebook / "estufa.tex"
        if not tex_path.is_file():
            errors.append(f"{notebook_name}: missing generated estufa.tex")
            continue

        tex = tex_path.read_text(encoding="utf-8")
        if "\\end{document}" not in tex:
            errors.append(f"{notebook_name}/estufa.tex: missing \\end{{document}}")

        references = REFERENCE_PATTERN.findall(tex)
        if not references:
            errors.append(f"{notebook_name}/estufa.tex: no source references found")
        for reference in references:
            if not (notebook / reference).is_file():
                errors.append(
                    f"{notebook_name}/estufa.tex: missing referenced file {reference}"
                )
            checked += 1
    return checked


def validate_conflict_markers(errors: list[str]) -> int:
    checked = 0
    for path in ROOT.rglob("*"):
        if not path.is_file() or ".git" in path.parts or path.suffix not in TEXT_SUFFIXES:
            continue
        text = path.read_text(encoding="utf-8")
        if CONFLICT_MARKER_PATTERN.search(text):
            errors.append(f"{path.relative_to(ROOT)}: unresolved merge conflict marker")
        checked += 1
    return checked


def main() -> int:
    errors: list[str] = []
    mirror_count = validate_clean_mirrors(errors)
    reference_count = validate_tex_references(errors)
    text_count = validate_conflict_markers(errors)

    if errors:
        print("Notebook validation failed:", file=sys.stderr)
        for error in errors:
            print(f"- {error}", file=sys.stderr)
        return 1

    print(
        "Notebook validation passed: "
        f"{mirror_count} generated mirrors, "
        f"{reference_count} TeX references, "
        f"{text_count} text files checked."
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
