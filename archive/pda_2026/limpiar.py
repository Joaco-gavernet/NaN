import os
folders = ['grafos', 'data_structures', 'dp', 'general', 'geometry', 'math', 'number_theory', 'Python', 'strings', 'tree']
# folders = ['number_theory']

#remover todo el contenido
for folder in folders:
    clean_folder = folder + '_clean'
    os.makedirs(clean_folder, exist_ok=True)
    for filename in os.listdir(clean_folder):
        file_path = os.path.join(clean_folder, filename)
        if os.path.isfile(file_path):
            os.remove(file_path)
for folder in folders:
    for x in sorted(os.listdir(folder), key=str.lower):
        source_path = os.path.join(folder, x)
        if not os.path.isfile(source_path):
            continue
        # Eliminar las filas en blanco
        with open(source_path, 'r', encoding='utf-8') as f:
            lines = f.readlines()
        with open(folder + '_clean/' + x, 'w', encoding='utf-8') as f:
            for line in lines:
                if line.strip() and not line.startswith("#"):
                    f.write(line)
