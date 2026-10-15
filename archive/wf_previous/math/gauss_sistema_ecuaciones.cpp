//~ const int INF = 2; // it doesn't actually have to be infinity or a big number

/*
Sistema de ecuaciones lineales modulares. Resuelve Ax=B. 
En las filas estan las ecuaciones y en las columnas las variables.
En ans queda la solucion en caso de que sea unica. La matriz A es de n x m. 
Esta matriz tiene n ecuaciones y m-1 variables, la ultima columna es la matrix b.
Complejidad O(min(n, m)nm). Si n == m, es O(n^3). 
*/

ll mod(ll x) {x%=MOD; if(x<0) x+=MOD; return x;}
ll add(ll a, ll b){return mod(a+b);}
ll sub(ll a, ll b){return mod(a-b);}
ll mul(ll a, ll b){return mod(mod(a)*mod(b));}
ll be(ll a, ll p) {
	ll ans=1; for(; p; p/=2, a = mul(a,a)) if(p&1) ans=mul(ans,a);
	return ans;
}
ll divi(ll a, ll b){return mul(a,be(b,MOD-2));}

int gauss(vector<vi> &a, vi &ans) {
    int n = SZ(a), m = SZ(a[0])-1;

    vector<int> where(m, -1);
    for(int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        forr(i, row, n){ // if(abs(a[i][col]) > abs(a[sel][col]))
            if(a[i][col] > a[sel][col]) sel = int(i); 
        }
        if(a[sel][col] == 0) continue; // if(abs(a[sel][col]) < EPS)
        forr(i, col, m+1) swap(a[sel][i], a[row][i]);
        where[col] = row;

        forn(i, n){
            if(i != row) { 
                ll c = divi(a[i][col], a[row][col]); // double c = a[i][col] / a[row][col];
                forr(j, col, m+1) a[i][j] = sub(a[i][j], mul(a[row][j], c));
            }
        }
        ++row;
    }

    ans.assign(m, 0);
    forn(i, m) if(where[i] != -1) ans[i] = divi(a[where[i]][m], a[where[i]][i]);
    forn(i, n){
        ll sum = 0; // double sum = 0;
        forn(j, m) sum = add(sum, mul(ans[j], a[i][j]));
        if(sum - a[i][m] != 0) return 0; // if(abs(sum-a[i][m]) > EPS)
        // No hay soluciones
    }
    forn(i, m) if(where[i] == -1) return INF; // Infinitas soluciones
    return 1; // Exactamente una solucion
}

// Encuentra las bases que generan la solucion
vector<vi> find_bases(vector<vi> &A, vi &ans) {
	int n = SZ(A), m = SZ(ans);
	vi var_ind;
	forn(i,SZ(ans)) if(ans[i] == 0) var_ind.pb(i);
	
	vector <vi> bases(SZ(var_ind),vi(m,0));
	int r = 0;
	for(auto u : var_ind) {
		bases[r][u] = 1;
		forn(i,n) {
			forn(j,m) {
				if(A[i][j] != 0) {
					bases[r][j] = divi(-A[i][u], A[i][j]);
					break;
				}
			}
		}
		r++;
	}
	return bases;
} 
