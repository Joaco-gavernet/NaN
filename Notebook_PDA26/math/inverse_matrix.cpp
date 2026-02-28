// modular functions in gauss

pair<ll,vector<vi>> inverse_matrix(vector<vector<ll> > &x) { 
    // returns det and the inverse of the matrix,
    // if det == 0, no inverse
    int n = SZ(x); vector <vi> I(n,vi(n,0));
    ll det = 1;
    forn(i,n) I[i][i] = 1;
    forn(i,n) {
		int pos = -1;
        forr(fila,i,n) if(x[fila][i] > 0) pos = fila;
        if(pos == -1) {return {0,I};} 
        if(pos != i) {
			swap(x[i],x[pos]), swap(I[i],I[pos]);
			det = mul(det,-1);
		}
		ll pivot = x[i][i];
		det = mul(det,pivot);
        forn(j,n) {
			x[i][j] = divi(x[i][j],pivot);
			I[i][j] = divi(I[i][j],pivot);
		}
        forn(fila,n) {
            if(fila == i) continue;
            pivot = x[fila][i];
            forn(j,n) {
				x[fila][j] = sub(x[fila][j],mul(pivot,x[i][j]));
				I[fila][j] = sub(I[fila][j],mul(pivot,I[i][j]));
			}
        }
    }
    return {det,I};
}
