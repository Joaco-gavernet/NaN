struct compresion {
    vector<int> todos;
    compresion(vector<int> v) {
        todos = v; sort(all(todos));
        todos.erase(unique(all(todos)),todos.end());
    }
    int obtener(int x) { return (int)(lower_bound(all(todos),x)-todos.begin()); }
};
