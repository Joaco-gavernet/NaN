
void floyd(vector<vector<int>>&matriz, ll n) {
    forn(k,n) forn(i,n) forn(j,n) {
        matriz[i][j]=min(matriz[i][j],matriz[i][k]+matriz[k][j]);
    } // O(n^3)
}
