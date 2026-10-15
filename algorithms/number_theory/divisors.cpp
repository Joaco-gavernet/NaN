vi find_divisors(ll n, vi &primos) {
	vector <pair<ll,ll>> factor; 
	for(ll prime : primos) {
		int cont = 0;
		while(n % prime == 0) {
			cont++;
			n /= prime;
		}
		if(cont > 0) factor.pb({prime,cont});
	}
	
	if(n > 1) factor.pb({n,1});
	
	vi divisores = {1};
	for(auto [p,exp] : factor) {
		int tam = SZ(divisores);
		forn(i,exp) {
			forn(j,tam) {
				int pos = SZ(divisores)-tam;
				divisores.pb(divisores[pos] * p);
			}
		}
	}
		
	sort(all(divisores));
	return divisores;
}
