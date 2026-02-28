ll lis(vi &a, int strict = 0){
	vi temp; temp.pb(a[0]);
	forr(i, 1, SZ(a)){
		ll x = a[i];
		if(x >= temp.back()+strict) temp.pb(x);
		else {	auto it = upper_bound(all(temp), x-strict); *it = x; } }
	return SZ(temp); }
