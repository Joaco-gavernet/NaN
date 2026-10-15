// Compresion de coordenadas
// Complejidad: O(n log n) para construir, O(log n) para obtener
struct compresion {
    vector<int> todos;
    compresion(vector<int> v) {
        todos = v; sort(all(todos));
        todos.erase(unique(all(todos)),todos.end());
    }
    int obtener(int x) { // Esto se podria hacer tambien con un unordered_map en O(1)
        return (int)(lower_bound(all(todos),x)-todos.begin());
    }
};
