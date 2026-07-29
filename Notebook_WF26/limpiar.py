import os
folders = ['grafos', 'data_structures', 'dp', 'general', 'geometry', 'math', 'number_theory', 'Python', 'strings', 'tree']
# folders = ['number_theory']

#remover todo el contenido
for folder in folders:
    for filename in os.listdir(folder + '_clean'):
        file_path = os.path.join(folder + '_clean', filename)
        if os.path.isfile(file_path):
            os.remove(file_path)
for folder in folders:
    lista = os.listdir(folder)
    if not os.path.exists(folder + "_clean"):
        os.mkdir(folder + "_clean")
    for x in lista:
        # Eliminar las filas en blanco
        with open(folder + '/' + x, 'r') as f:
            lines = f.readlines()
        with open(folder + '_clean/' + x, 'w') as f:
            for line in lines:
                if line.strip() and not line.startswith("#"):
                    f.write(line)