import os


def prettify_name(section):  # Searching_and_Sorting -> "Searching and Sorting"
    return section.replace("_", " ")


def sanitize_problem_name(problem):
    if (problem[-4:] == ".cpp"):
        problem = problem[:-4]
    if (problem[-3:] == ".sh"):
        problem = problem[:-3]
    return prettify_name(problem)


def add_section(section, path=""):
    section_name = prettify_name(section).title()
    if (path == ""):  # Only in main dirs
        print(f"\n%############### {section_name} ###############\n", file=f)
        print(f"\section{{{section_name[:-6]}}}", file=f)

    os.chdir(section)

    path += ("/" if path else "") + section

    files = os.listdir()
    # move plantilla.cpp to the beggining
    if ("plantilla.cpp" in files):
        files.remove("plantilla.cpp")
        files.insert(0, "plantilla.cpp")

    for x in files:
        if (os.path.isdir(x)):  # Go recursively
            add_section(x, path)
        else:
            print(f"\n\subsection{{{sanitize_problem_name(x).title()}}}", file=f)
            if x[-3:] == "cpp":
                print(f'\cppfile{{{path}/{x}}}', file=f)
            else:
                print(f'\pythonfile{{{path}/{x}}}', file=f)


    # print("\n\\newpage", file=f)

    os.chdir('..')


# Copiar el header.tex como base
with open('gen_utils/header.tex', 'r', encoding='utf-8') as header_file:
    header_content = header_file.read()

with open('estufa.tex', 'w', encoding='utf-8') as f:
    # Escribir el header primero
    f.write(header_content)
    
    add_section("general")  # Importante que este primero

    for section in os.listdir():
        if (not os.path.isdir(section)):
            continue  # Ignoro archivos sueltos
        if (section in ["Old", "gen_utils", "general", "build", "general_clean"]):
            continue
        if section.endswith("_clean"):
            add_section(section)

    print("\\end{document}", file=f)
