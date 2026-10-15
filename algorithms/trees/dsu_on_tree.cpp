#define rs(n) resize(n)

struct DSU_on_Tree { // count #vertex with color c in subtree v	
	vector<map<ll, ll>> h; // histogram [color,count]
	vi color, link, ans;
	vii sum;
	vector<vi> g;
	
	DSU_on_Tree(int n, vector<vi> _g, vi _c) : g(_g), color(_c) {
		ans.rs(n+5); link.rs(n+5); h.rs(n+5); sum.rs(n+5);
		forn(i,n+5) link[i] = i, sum[i] = {0,0};
		dfs(0);
	} 
	
	int find(int x) {
		return link[x] = (link[x] == x ? x : find(link[x]));
	}
	
	void add(int v, int c, int cnt) { // add [color,cnt] to root v
		ll &cur = h[v][c];
		cur += cnt; 
		if(sum[v].first == cur) sum[v].second += c;
		else if(sum[v].first < cur) sum[v] = {cur,c};
	}
	
	void merge(int i, int j){
		if(SZ(h[i]) < SZ(h[j])) swap(i,j);
		link[j] = i;
		for(auto x : h[j]){
			int c, cnt; tie(c,cnt) = x;
			add(i,c,cnt);
		}
		h[j].clear();
	}
	
	void dfs(ll v, ll p = -1){
		add(v,color[v],1);
		for(auto u : g[v]) {
			if(u == p) continue;
			dfs(u, v); 
			merge(find(v), find(u));
		}
		ans[v] = sum[find(v)].second; // here solve for vertex v
	}
};
