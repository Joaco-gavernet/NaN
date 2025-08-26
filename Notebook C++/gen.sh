#!/bin/sh

echo "- Agregando el header a estufa.tex"
cp 'gen_utils/header.tex' 'estufa.tex'

# Generador del contenido del tex
echo "- Agregando los problemas"
python 'gen_utils/add_files.py'

echo "- Compilando el tex con pdflatex"
latexmk -interaction=nonstopmode -pdf estufa.tex

latexmk -c &> /dev/null
# Limpio los archivos basura que quedan y dejo solo pdf y tex

echo "Notebook creado 🔥🔥"
