typedef ll tipo;
const int MAXN = 200005;

struct arista {
    int x; tipo w; // x -> next node, w = weight
};

struct nodo {
    tipo d, v, a; // d -> distance, v -> actual node, a = previous node
    bool operator<(const nodo& x) const {return d > x.d;}
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
                if(!visto[u.x]) p.push({it.d + u.w, u.x, it.v});
            }
        }
    }
    return ans;
}

