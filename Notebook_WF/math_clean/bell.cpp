// Los numeros de Bell son utiles para calcular de cuantas maneras 
// podemos subdivir el conjunto utilizando todos los elementos -> O(n^2)
// Bell numbers = {1, 1, 2, 5, 15, 52, 203, 877, 4140, 21147, ...}
vector<int> bellNumber(int n) {
    vector<vector<int>> bell(n+1,vector<int>(n+1));
    vector<int> ans(n+1,0); // Numeros de bell desde 0 hasta n
    bell[0][0] = 1;
    forr(i, 1, n+1){
        bell[i][0] = bell[i-1][i-1];
        forr(j, 1, i+1) bell[i][j] = bell[i-1][j-1] + bell[i][j-1];
    }
    forn(i, n+1) ans[i] = bell[i][0];
    return ans;
}
