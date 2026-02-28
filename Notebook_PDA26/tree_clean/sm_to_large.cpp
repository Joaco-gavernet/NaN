struct query { // v: vrtx, c: col, idx_ans
    ll v, c, idx; 
};
vi g[MAXN];
vector<query> q[MAXN]; // Queries to answer
vi ans(MAXN, -1), color; // Answer to each query
unordered_map<ll, ll> cnt[MAXN]; 
int merge(int v, int u){ 
    if(SZ(cnt[v]) < SZ(cnt[u])) swap(u, v);
    for(auto [x, y]: cnt[u]){
        cnt[v][x] += y;
    }
    cnt[u].clear(); 
    return v; 
}   
void process_queries(int v, int v_repr){
    for(auto &[_v, c, i]: q[v])
		ans[i] = SZ(cnt[v_repr]); 
}
int dfs(int v, int p){
    int v_repr = v; 
    cnt[v][color[v]]++;     
    for(auto u: g[v]){
        if(u == p) continue;
        int u_repr = dfs(u, v); 
        v_repr = merge(v_repr, u_repr);
    }
    process_queries(v, v_repr); 
    return v_repr;
}
void solve(int m) { 
	dfs(0,-1);
	forn(i,m) cout << ans[i] << " ";
	cout << "\n";
}
