"""Exercise the manifest/build contract independently of any TeX engine."""
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'scripts'))
from build_notebook import ROOT, generate, load_manifest
from validate_notebooks import validate


class NotebookBuildTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        (self.root / 'algorithms').mkdir()
        (self.root / 'notebook').mkdir()
        (self.root / 'notebook/header.tex').write_text('\\begin{document}\n')
        self.code = '#include <vector>\n#define LEFT(x) ((x) << 1)\n\nint x = 1;\n'
        (self.root / 'algorithms/example.cpp').write_text(self.code)
        self.manifest = self.root / 'notebook/example.toml'
        self.body = '''title = "Contest & team"
[[sections]]
title = "First_topic"
entries = [{path = "algorithms/example.cpp", title = "Example #1"}]
'''
        self.manifest.write_text(self.body)

    def test_generation_preserves_sources_and_replaces_stale_output(self):
        tex = generate(self.manifest, self.root)
        source = tex.parent / 'snippets/algorithms/example.cpp'
        self.assertEqual(source.read_text(), self.code)
        self.assertIn(r'\section{First\_topic}', tex.read_text())
        self.assertIn(r'\subsection{Example \#1}', tex.read_text())
        self.assertIn(r'Contest \& team', tex.read_text())
        stale = tex.parent / 'snippets/stale.cpp'
        stale.write_text('stale')
        generate(self.manifest, self.root)
        self.assertFalse(stale.exists())

    def test_rejects_missing_duplicate_and_escaping_sources(self):
        for path in ['algorithms/missing.cpp', '../outside.cpp', '/tmp/outside.cpp',
                     'archive/example.cpp', 'algorithms/example.txt']:
            with self.subTest(path=path):
                self.manifest.write_text(self.body.replace('algorithms/example.cpp', path))
                with self.assertRaises(ValueError):
                    load_manifest(self.manifest, self.root)
        self.manifest.write_text(self.body + '''
[[sections]]
title = "Duplicate"
entries = [{path = "algorithms/example.cpp", title = "Again"}]
''')
        with self.assertRaisesRegex(ValueError, 'Duplicate'):
            load_manifest(self.manifest, self.root)

    def test_python_blanks_and_section_order_are_preserved(self):
        python = 'value = """first\n\nlast"""\n'
        (self.root / 'algorithms/example.py').write_text(python)
        self.manifest.write_text(self.body + '''
[[sections]]
title = "Second"
entries = [{path = "algorithms/example.py", title = "Python"}]
''')
        tex = generate(self.manifest, self.root)
        self.assertEqual((tex.parent / 'snippets/algorithms/example.py').read_text(), python)
        self.assertLess(tex.read_text().index('First'), tex.read_text().index('Second'))
        self.assertIn(r'\pythonfile{snippets/algorithms/example.py}', tex.read_text())

    def test_local_documentation_links_are_checked(self):
        (self.root / 'README.md').write_text('[Broken](missing.md)\n')
        self.assertTrue(any('broken link' in error for error in validate(self.root)))

    def test_world_finals_selects_current_factorization_and_excludes_trie(self):
        manifest = load_manifest(ROOT / 'notebook/world_finals.toml')
        paths = [entry['path'] for section in manifest['sections'] for entry in section['entries']]
        self.assertIn('algorithms/number_theory/miller_rabin_pollard_rho.cpp', paths)
        self.assertNotIn('algorithms/strings/trie.cpp', paths)
        self.assertFalse(any(path.startswith('archive/') for path in paths))


if __name__ == '__main__':
    unittest.main()
