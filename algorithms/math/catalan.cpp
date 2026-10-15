// Catalan dp

vector<ll> catalan(int n) { //O(N^2)
    vector<ll> c(n+1,0); c[0] = c[1] = 1;
    forr(i,2,n+1) forn(j,i) c[i] += c[j] * c[i-j-1];
    return c;
}

// Catalan formula
// binom(2n,n) / (n+1) --- (2n!) / [(n+1)! * n!]

ll catalan(ll n) {
	return (((fact[2*n] * ifact[n+1])%MOD)*ifact[n])%MOD;
}




