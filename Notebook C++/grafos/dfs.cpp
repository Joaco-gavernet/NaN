const int MAXN = 200005;
vector< vector<int> > g; // graph represented as an adjacency list
vector <bool> visto(MAXN,false);

void dfs(int v) {
    visto[v] = true;
    for (int u : g[v]) if (!visto[u]) dfs(u);
}

