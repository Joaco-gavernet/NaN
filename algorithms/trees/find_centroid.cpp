vector < vector <int> > g(MAXN);
vector <bool> is_centroid(MAXN,true);
vector <int> sz(MAXN,0);

void DFS(int v, int prev, int n) {
    sz[v] = 1;
    for(int u : g[v]) {
        if(u == prev) continue;
        DFS(u,v,n);
        sz[v] += sz[u];
        if(sz[u] > n/2) is_centroid[v] = false;
    }
    if(n - sz[v] > n/2) is_centroid[v] = false;
}

vector <int> find_centroid(int n) {
    // Centroid: A node so that each subtree has at most floor(n/2) nodes
    vector <int> ans;
    DFS(0,-1,n);
    forr(i,1,n+1) if(is_centroid[i]) ans.pb(i); 
    return ans;
}
