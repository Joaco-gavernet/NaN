#!/usr/bin/env sh

set -eu

echo "- Agregando el header a estufa.tex"
cp 'gen_utils/header.tex' 'estufa.tex'

# Generador del contenido del tex
echo "- Agregando los problemas"
python3 'gen_utils/add_files.py'

echo "- Limpiando archivos auxiliares"
latexmk -c

echo "- Compilando el tex con pdflatex"
latexmk -interaction=nonstopmode -pdf estufa.tex

latexmk -c >/dev/null 2>&1
# Limpio los archivos basura que quedan y dejo solo pdf y tex

echo "Notebook creado 🔥🔥"
