import os

SOURCE_SUFFIXES = {".cpp", ".py", ".sh"}
EXCLUDED_REFERENCES = {"strings_clean/trie.cpp"}


def prettify_name(section):  # Searching_and_Sorting -> "Searching and Sorting"
    return section.replace("_", " ")


def sanitize_problem_name(problem):
    return prettify_name(os.path.splitext(problem)[0])


def add_section(section, path=""):
    section_key = section[:-6] if section.endswith("_clean") else section
    section_name = prettify_name(section_key).title()
    if (path == ""):  # Only in main dirs
        print(f"\n%############### {section_name} ###############\n", file=f)
        print(f"\\section{{{section_name}}}", file=f)
        if section == "math_clean":
            with open("gen_utils/math_cheatsheet.tex", "r", encoding="utf-8") as source:
                f.write(source.read())

    os.chdir(section)

    path += ("/" if path else "") + section

    files = sorted(
        [
            entry
            for entry in os.listdir()
            if entry != "__pycache__" and not entry.startswith(".")
        ],
        key=str.lower,
    )
    # move plantilla.cpp to the beggining
    if ("plantilla.cpp" in files):
        files.remove("plantilla.cpp")
        files.insert(0, "plantilla.cpp")

    for x in files:
        if (os.path.isdir(x)):  # Go recursively
            add_section(x, path)
        else:
            reference = f"{path}/{x}"
            if os.path.splitext(x)[1] not in SOURCE_SUFFIXES:
                continue
            if reference in EXCLUDED_REFERENCES:
                continue
            print(f"\n\\subsection{{{sanitize_problem_name(x).title()}}}", file=f)
            if x[-3:] == "cpp":
                print(f'\\cppfile{{{reference}}}', file=f)
            else:
                print(f'\\pythonfile{{{reference}}}', file=f)


    # print("\n\\newpage", file=f)

    os.chdir('..')


# Copiar el header.tex como base
with open('gen_utils/header.tex', 'r', encoding='utf-8') as header_file:
    header_content = header_file.read()

with open('estufa.tex', 'w', encoding='utf-8') as f:
    # Escribir el header primero
    f.write(header_content)
    
    add_section("general")  # Importante que este primero

    for section in sorted(os.listdir(), key=str.lower):
        if (not os.path.isdir(section)):
            continue  # Ignoro archivos sueltos
        if (section in ["Old", "gen_utils", "general", "build", "general_clean"]):
            continue
        if section.endswith("_clean"):
            add_section(section)

    print("\\end{document}", file=f)
