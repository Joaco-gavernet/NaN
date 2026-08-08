#!/usr/bin/env sh

set -eu

python3 limpiar.py

echo "- Agregando el header a estufa.tex"
cp 'gen_utils/header.tex' 'estufa.tex'

# Generador del contenido del tex
echo "- Agregando los problemas"
python3 'gen_utils/add_files.py'

if command -v latexmk >/dev/null 2>&1; then
    echo "- Limpiando archivos auxiliares"
    latexmk -c

    echo "- Compilando el tex con pdflatex"
    latexmk -interaction=nonstopmode -pdf estufa.tex
    latexmk -c >/dev/null 2>&1
elif command -v tectonic >/dev/null 2>&1; then
    echo "- Compilando el tex con Tectonic"
    tectonic estufa.tex
else
    echo "Error: instala latexmk con pdflatex, o Tectonic, para generar el PDF." >&2
    exit 1
fi

cp 'estufa.pdf' 'UNLP-NAN-Notebook.pdf'
# Limpio los archivos basura que quedan y dejo solo pdf y tex

echo "Notebook creado 🔥🔥"
