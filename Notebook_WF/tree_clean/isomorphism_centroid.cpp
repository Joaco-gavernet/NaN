struct centroid {
    vector < vector <int> > g;
    vector <bool> is_centroid;
    vector <int> sz;
    centroid(vector <vector <int> > &graph, int tam) {
        g = graph;
        is_centroid.resize(tam,true);
        sz.resize(tam,0);
    }
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
        forn(i,n) if(is_centroid[i]) ans.pb(i); 
        return ans;
    }
};
struct iso {
    vector <vector <int> > t1, t2;
    map <vector <int>,int> mapa;
    int idx = 0;
    iso(vector <vector <int> > &tree1, vector <vector <int> > &tree2) {
        t1 = tree1; t2 = tree2; 
    }
    int dfs(int cur, int p, vector < vector<int> > &g) {
        vector <int> v;
        for(int u : g[cur]) {
            if(u != p) v.push_back(dfs(u,cur,g));
        }
        sort(all(v));
        if(!mapa.count(v)) mapa[v] = idx++;
        return mapa[v];
    }
    bool check_iso(vector <int> &centroid1, vector <int> &centroid2) {
        int s1 = dfs(centroid1[0],-1,t1);
        for(int u : centroid2) {
            int s2 = dfs(u,-1,t2);
            if(s1 == s2) return true;
        }
        return false;
    }
};
