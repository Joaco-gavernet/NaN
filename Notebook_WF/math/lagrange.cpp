ll lagrange(vii a, ll x){
	/* Recibe una muestra a de n puntos (xi,yi)
	   y evalua el polinomio de Lagrange de 
	   en el punto x desconocido */
	ll ans = 0;
	int n = SZ(a);
	forn(i, n){
		ll term = a[i].second;
		forn(j, n){
			if(j != i)
				term = term*(x-a[j].first)/(a[i].first-a[j].first);
		}
		ans += term;
	}
	return ans;
}

