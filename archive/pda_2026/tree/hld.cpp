struct hld { 
	#define rs(x) resize(x)
	int n;
	vector <vector<int>> g;
	vector <tipo> values, sz, heavy, parent, depth, top, r, pos;
	segtree st; // iterative is faster
	
	hld(int _n, vector <vector<int>> _g, vector <tipo> _v) {
		n = _n; g = _g; values = _v;
		sz.rs(n); parent.rs(n); depth.rs(n); top.rs(n); pos.rs(n);
		heavy.rs(n);
		forn(i,n) heavy[i] = i;
		dfs(0);
		get_order(0,0);
		st.build(r,r.size());
	}
	
	ll dfs(int v, int p = -1, int d = 0) {
		depth[v] = d; parent[v] = p;
		for(int &u : g[v]) {
			if(u == p) continue;
			ll tam = dfs(u,v,d+1);
			// move heavy node to the begining 
			if(sz[u] > sz[heavy[v]]) heavy[v] = u, swap(u,g[v][0]); 
			sz[v] += tam;
		}
		sz[v] += 1;
		return sz[v];
	}
	
	void get_order(int v, int t, int p = -1) { //first child is heavy
		pos[v] = r.size(); top[v] = t; r.pb(values[v]); 
		for(int u : g[v]) {
			if(u == p) continue;
			if(u == heavy[v]) get_order(u,t,v);
			else get_order(u,u,v);
		}
	}
	
	void op(ll &res, int a, int b) { // Set operation
		res = max(res, st.query(pos[a],pos[b]));
		// ------- for segtree recursive use ---------- 
		// res = max(res, st.query(pos[a],pos[b]).ans); 
	}
	
	tipo query_hld(int a, int b) {
		tipo res = NEUT;
		for(; top[a] != top[b]; b = parent[top[b]]) {
			if(depth[top[a]] > depth[top[b]]) swap(a, b);
			op(res,top[b],b);
		}
		if(depth[a] > depth[b]) swap(a, b);
		op(res,a,b);
		return res;
	}
	
	void update_hld(int p, tipo val) { st.update(pos[p],val); }
};
