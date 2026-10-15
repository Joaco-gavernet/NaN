#!/usr/bin/env python3
"""Build a curated notebook from library files selected by an ordered manifest."""
from __future__ import annotations

import argparse
from pathlib import Path
import shutil
import subprocess
import tomllib

ROOT = Path(__file__).resolve().parents[1]
LANGUAGES = {'.cpp': 'cppfile', '.py': 'pythonfile', '.sh': 'bashfile'}


def source_path(value: str, root: Path, folders: set[str], suffixes: set[str]) -> Path:
    path = Path(value)
    if (path.is_absolute() or '..' in path.parts or not path.parts
            or path.parts[0] not in folders or path.suffix not in suffixes):
        raise ValueError(f'Invalid notebook source: {value}')
    resolved = (root / path).resolve()
    if not resolved.is_relative_to(root.resolve()) or not resolved.is_file():
        raise ValueError(f'Missing notebook source: {value}')
    return path


def load_manifest(path: Path, root: Path = ROOT) -> dict:
    with path.open('rb') as stream:
        manifest = tomllib.load(stream)
    if not isinstance(manifest.get('title'), str) or not manifest['title'].strip():
        raise ValueError('Manifest needs a nonempty title')
    if not isinstance(manifest.get('sections'), list) or not manifest['sections']:
        raise ValueError('Manifest needs ordered sections')
    seen: set[str] = set()
    for section in manifest['sections']:
        if not isinstance(section.get('title'), str) or not section['title'].strip():
            raise ValueError('Each section needs a title')
        if not isinstance(section.get('entries'), list) or not section['entries']:
            raise ValueError(f'Section {section["title"]} needs entries')
        if 'cheatsheet' in section:
            source_path(section['cheatsheet'], root, {'notebook'}, {'.tex'})
        for entry in section['entries']:
            if not isinstance(entry.get('path'), str):
                raise ValueError('Each entry needs a source path')
            path = source_path(entry['path'], root, {'algorithms', 'templates'}, set(LANGUAGES))
            if not isinstance(entry.get('title'), str) or not entry['title'].strip():
                raise ValueError(f'{path} needs a display title')
            if str(path) in seen:
                raise ValueError(f'Duplicate notebook source: {path}')
            seen.add(str(path))
    return manifest


def tex_escape(text: str) -> str:
    replacements = {'\\': r'\textbackslash{}', '&': r'\&', '%': r'\%', '$': r'\$',
                    '#': r'\#', '_': r'\_', '{': r'\{', '}': r'\}',
                    '~': r'\textasciitilde{}', '^': r'\textasciicircum{}'}
    return ''.join(replacements.get(char, char) for char in text)


def generate(manifest_path: Path, root: Path = ROOT) -> Path:
    """Copy selected sources verbatim; all generated files stay under build/."""
    manifest = load_manifest(manifest_path, root)
    header = (root / 'notebook/header.tex').read_text(encoding='utf-8')
    output = root / 'build' / manifest_path.stem
    if output.exists():
        shutil.rmtree(output)
    output.mkdir(parents=True)
    parts = [header, '\n' + r'\section*{' + tex_escape(manifest['title']) + '}\n']
    for section in manifest['sections']:
        parts.append('\n' + r'\section{' + tex_escape(section['title']) + '}\n')
        if 'cheatsheet' in section:
            parts.append((root / section['cheatsheet']).read_text(encoding='utf-8'))
        for entry in section['entries']:
            relative = Path(entry['path'])
            destination = output / 'snippets' / relative
            destination.parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(root / relative, destination)
            parts.append('\n' + r'\subsection{' + tex_escape(entry['title']) + '}\n')
            command = LANGUAGES[relative.suffix]
            parts.append('\\' + command + '{' + destination.relative_to(output).as_posix() + '}\n')
    parts.append('\n' + r'\end{document}' + '\n')
    tex = output / 'notebook.tex'
    tex.write_text(''.join(parts), encoding='utf-8')
    return tex


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--manifest', type=Path, default=ROOT / 'notebook/world_finals.toml')
    parser.add_argument('--sources-only', action='store_true', help='Generate without a TeX installation')
    args = parser.parse_args()
    tex = generate(args.manifest.resolve())
    if not args.sources_only:
        if shutil.which('tectonic'):
            command = ['tectonic', tex.name]
        elif shutil.which('latexmk'):
            command = ['latexmk', '-interaction=nonstopmode', '-halt-on-error', '-pdf', tex.name]
        else:
            parser.error('Install Tectonic or latexmk with pdflatex to build the PDF')
        subprocess.run(command, cwd=tex.parent, check=True)
    print(tex if args.sources_only else tex.with_suffix('.pdf'))


if __name__ == '__main__':
    main()
