/*
 * Elevator Problem
 * 
 * Dado los pesos maximos de las personas y el peso maximo del
 * ascensor, cual es el minimo numeros de viajes necesarios para subir
 * a todas las personas: O(N * 2^N)
 * 
 */

ll elevator_problem(int n, ll x, vector <ll> &peso) {
    vector <pair<ll,ll>> best(1<<n); best[0] = {1,0};
    forr(s,1,(1<<n)) {
        best[s] = {n+1,0};
        forn(p,n) {
            if(s&(1<<p)) {
                pair<ll,ll> option = best[s^(1<<p)];
                if(option.second + peso[p] <= x) {
                    option.second += peso[p];
                }
                else{
                    option.first++; option.second = peso[p];
                }
                best[s] = min(best[s],option);
            }
        }
    }
    return best[(1<<n)-1].first;
}

