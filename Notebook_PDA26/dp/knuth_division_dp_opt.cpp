const ll INF = (ll)(1e18+10);
const int MAXN = 5005;
vector <ll> prefix;

// Sea Pos(i,j) la posicion del corte que optimiza la dp, intervalo [i,j]
// Se puede aplicar optimizacion de Knuth si se cumple que:
// Pos(i,j-1) <= pos(i,j) <= pos(i+1,j)
// Objetivo: llevar un array a elementos individuales mediante cortes.

ll suma(int i, int j) {
    return prefix[j+1] - prefix[i]; 
} // Suma de los elementos del inter

ll solve_Knuth(int n) {
    vector <ll> pos(n+1);
    vector <vector <ll> > dp(MAXN,vector<ll>(MAXN,INF));
    for(int i = 0; i < n; i++) dp[i][i] = 0, pos[i] = i;

    for(int len = 1; len < n; len++) {
        vector <ll> aux(n+1,0);
        for(int i = 0; i < n - len; i++) {
            for(int k = pos[i]; k <= pos[i+1]; k++) {
                ll cost = suma(i,i+len) + dp[i][k] + dp[k+1][i+len];
                if(cost < dp[i][i+len]) {
                    dp[i][i+len] = cost; aux[i] = k;
                }
            }
        }
        pos = aux;
    }
    return dp[0][n-1];
}
