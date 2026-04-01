g++ -std=c++17 -DLOCAL -g -O2 -Wconversion -Wshadow -Wall -Wextra -D_GLIBCXX_DEBUG -c %f
g++ -std=c++17 -DLOCAL -g -O2 -Wconversion -Wshadow -Wall -Wextra -D_GLIBCXX_DEBUG -o %e %f

code ~/.bashrc # archivo para crear alias

compile() { 
    g++ "$1.cpp" -o "$1" 2>&1|grep "error:"
} # Crea ejecutable con mismo nombre que el archivo .cpp

source ~/.bashrc # resetear el terminal para aplicar cambios