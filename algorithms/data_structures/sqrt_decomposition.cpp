// This code solves the same problem as lazy arithmetic sum

struct block {
	ll l, r, a, b, ans;
	block(ll _l, ll _r) {
		l = _l; r = _r; ans = a = b = 0;
	}
	block() {}
};

const int BSIZE = 350; // Size of each block

struct segment_block {
	int n;
	vi v;
	vector <block> t;
	
	void refresh_block(block &u) { //clean block and refresh vector
		block new_b = block(u.l,u.r);
		forr(i,u.l,u.r+1) {
			v[i] += u.a + u.b * (i - u.l);
			new_b.ans += v[i];
		}
		u = new_b;
	}
	
	ll query_block(block &u, ll l, ll r) { // The answer of one blck
		if(l <= u.l && u.r <= r) { // full intersection
			ll last = u.a + u.b * (u.r - u.l);
			return u.ans + (u.a + last) * (u.r-u.l+1) / 2; 
		}
		// partial intersection
		refresh_block(u);
		ll ans = 0;
		forr(i,max(l,u.l),min(u.r+1,r+1)) {
			ans += v[i];
		}
		return ans;
	}
	
	void update_block(block &u, ll l, ll r, ll a, ll b) {// upd one blck
		if(l <= u.l && u.r <= r) { // full intersection
			u.a += (u.l - l) * b + a;
			u.b += b;
			return;
		}
		// partial intersection
		refresh_block(u);
		forr(i,max(l,u.l),min(u.r+1,r+1)) {
			v[i] += (i - l) * b + a;
			u.ans += (i - l) * b + a;
		}
	}
	
	ll query(ll l, ll r) {
		ll ans = 0;
		for(block &u : t) {
			if(r < u.l || l > u.r) continue;
			ans += query_block(u,l,r);
		}
		return ans;
	}
	
	void update(ll l, ll r, ll a, ll b) {
		for(block &u : t) {
			if(r < u.l || l > u.r) continue;
			update_block(u,l,r,a,b);
		}
	}
	
	void build(vi _v, int _n) {
		v = _v; n = _n; 
		int tam = 0;
		while(tam <= n-1) {
			t.pb(block(tam,min(n-1,tam+BSIZE-1)));
			tam += BSIZE;
			refresh_block(t.back());
		}
	} 
	
	void debug() { // good for check if updates are correct
		for(block u : t) {
			refresh_block(u);
			forr(i,u.l,u.r+1) cerr << v[i] << " ";
		}
		cerr << "\n"; RAYA;
	}
};
