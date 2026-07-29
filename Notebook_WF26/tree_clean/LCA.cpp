const int MAXN = 200005, LOG = 20;  
struct LCA {
    int n, root;  
    vector<vector<int>> g;
    int jmp[MAXN][LOG], depth[MAXN]; 
    void lca_dfs(int x) {
        for(int u : g[x]) {
            if(u == jmp[x][0]) continue;
            jmp[u][0] = x; depth[u] = depth[x]+1;
            lca_dfs(u);
        }
    }
    LCA(int tam, vector<vector<int>> &tree, int r): n(tam),root(r),g(tree) {
        depth[root] = 0;
        memset(jmp,-1,sizeof(jmp)); jmp[root][0] = root;
        lca_dfs(root);
        forr(k, 1, LOG){ forn(i, n){
                if(jmp[i][k-1]<0) jmp[i][k] = -1;
                else jmp[i][k] = jmp[jmp[i][k-1]][k-1];
            }
        }
    }
    int lca(int x, int y){
        if(depth[x] < depth[y]) swap(x,y);
        for(int i = LOG-1; i >= 0; i--) {
            if(depth[x]-(1<<i) >= depth[y]) x = jmp[x][i];
        }
        if(x == y) return x;
        for(int i = LOG-1; i >= 0; i--) {
            if(jmp[x][i] != jmp[y][i]) x = jmp[x][i], y = jmp[y][i];
        }
        return jmp[x][0];
    }
    int dist(int x, int y) { 
        return depth[x] + depth[y] - 2 * depth[lca(x,y)];
    }
};
