const int MAXN = 200005;
typedef long long tipo;
tipo INF = (tipo)(1e18+7);

struct nodo {
    tipo d; bool visto; //d -> distance, visto -> seen
};

vector<nodo> BFS(int start, int n, vector<vector<int>> &g) {
    vector<nodo> ans(n); queue<int> q;
    forn(i, n) ans[i] = {INF,false};
    ans[start] = {0,true}; q.push(start);
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(int u : g[v]) {
            if(ans[u].visto) continue;
            ans[u] = {ans[v].d+1, true}; q.push(u);
        }
    }
    return ans;
}
