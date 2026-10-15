//~ Minino camino entre todos los nodos
//~ O(n^3) - Tambien detecta ciclos negativos

void floyd(vector<vector<int>>&matriz, ll n) {
    forn(k,n) forn(i,n) forn(j,n) {
        matriz[i][j]=min(matriz[i][j],matriz[i][k]+matriz[k][j]);
    }
}
