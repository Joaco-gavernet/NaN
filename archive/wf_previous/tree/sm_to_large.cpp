// Small to large techique. 
struct query { // Queries to answer, v: vertex, c: color, idx: ans pos
    ll v, c, idx; 
};
 
vi g[MAXN];
vector<query> q[MAXN]; // Queries to answer
vi ans(MAXN, -1), color; // Answer to each query
 
unordered_map<ll, ll> cnt[MAXN]; // struct to store the info and merge
 
int merge(int v, int u){ 
    if(SZ(cnt[v]) < SZ(cnt[u])) swap(u, v); // now v is the large one
    for(auto [x, y]: cnt[u]){
        cnt[v][x] += y;
    }
    cnt[u].clear(); // Clear the small one to mantain memory in O(n)
    return v; // return the large node
}   
 
// Process the queries of v, v_repr is the representative of v (large 
// node after merging v and its children)
void process_queries(int v, int v_repr){
    for(auto &[_v, c, i]: q[v]) {
		ans[i] = SZ(cnt[v_repr]); // Number of distinct colors
		//~ ans[i] = cnt[v_repr][c]; // Number of nodes with color c
	}
}
 
int dfs(int v, int p){
    int v_repr = v; // Initialize the representative of v
    cnt[v][color[v]]++; // Initialize counter
    
    for(auto u: g[v]){
        if(u == p) continue;
        int u_repr = dfs(u, v); // Get the representative of u
        v_repr = merge(v_repr, u_repr); // Merge u_repr into v_repr
    }
    
    process_queries(v, v_repr); // Offline process the queries of v
 
    return v_repr;
}

void solve(int m) { // number of queries
	dfs(0,-1);
	forn(i,m) cout << ans[i] << " ";
	cout << "\n";
}
 
