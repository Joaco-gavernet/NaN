struct arista {
    int next; tipo w;
};
struct nodo {
    tipo d, v, a;
    bool operator<(const nodo& next) const {return d > next.d;}
};
vector<nodo> Dijkstra(int start, int n, vector<vector<arista>> &g) {
    vector<nodo> ans(n);
    vector<bool> visto(n, false);
    priority_queue<nodo> p; p.push({0,start,-1});
    while(!p.empty()) {
        nodo it=p.top(); p.pop();
        if(visto[it.v]) continue;
        else {
            ans[it.v] = it; visto[it.v] = true;
            for(arista u : g[it.v]) {
                if(!visto[u.next]) p.push({it.d + u.w, u.next, it.v});
            }
        }
    }
    return ans;
}
