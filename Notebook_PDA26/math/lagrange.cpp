ll lagrange(vii a, ll x){
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

