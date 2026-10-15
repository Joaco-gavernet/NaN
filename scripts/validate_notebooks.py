#!/usr/bin/env python3
"""Validate current notebook selections, source names, and local Markdown links."""
from pathlib import Path
import re
import sys
from urllib.parse import unquote

from build_notebook import ROOT, load_manifest


def validate(root: Path = ROOT) -> list[str]:
    errors = []
    manifests = sorted((root / 'notebook').glob('*.toml'))
    if not manifests:
        errors.append('No notebook manifests found')
    for manifest in manifests:
        try:
            load_manifest(manifest, root)
        except (ValueError, OSError, KeyError, TypeError) as error:
            errors.append(f'{manifest.relative_to(root)}: {error}')
    for path in (root / 'algorithms').rglob('*'):
        if path.is_file() and path.suffix in {'.cpp', '.py'}:
            if not re.fullmatch(r'[a-z0-9_]+\.(cpp|py)', path.name):
                errors.append(f'Use snake_case: {path.relative_to(root)}')
    # Archives are frozen historical documents and can refer to their old layout.
    for folder in [root, root / 'docs', root / 'algorithms', root / 'notebook',
                   root / 'templates', root / 'tools', root / 'tests', root / 'study']:
        paths = folder.glob('*.md') if folder == root else folder.rglob('*.md')
        for path in paths:
            text = path.read_text(encoding='utf-8')
            if re.search(r'^(?:<{7} |={7}\s*$|>{7} )', text, re.MULTILINE):
                errors.append(f'Unresolved conflict: {path.relative_to(root)}')
            links = re.findall(r'\]\(([^)]+)\)', text)
            links += re.findall(r'^\[[^\]]+\]:\s*(\S+)', text, re.MULTILINE)
            for link in links:
                target = link.split('#', 1)[0]
                if not target or re.match(r'[a-z]+:', target):
                    continue
                if not (path.parent / unquote(target)).exists():
                    errors.append(f'{path.relative_to(root)}: broken link {link}')
    return errors


def main() -> int:
    errors = validate()
    if errors:
        print('\n'.join(errors), file=sys.stderr)
        return 1
    print('Notebook selections, source names, and local documentation links are valid.')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
