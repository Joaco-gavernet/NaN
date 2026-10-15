struct arista {
    int u, v;
    ll w;
    bool operator<(const arista& other) const { return w < other.w; }
};
struct DSU {
    vi link, sz;

    DSU(int tam) {
        link.resize(tam+5), sz.resize(tam+5);
        forn(i, tam+5) link[i] = i, sz[i] = 1;
    }

    ll find(ll x){ return link[x] = (link[x] == x ? x : find(link[x])); }
    bool same(ll a, ll b) { return find(a) == find(b); }

    void join(ll a, ll b) {
        a = find(a), b = find(b);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a,b);
        sz[a] += sz[b];
        link[b] = a;
    }
};

vector<arista> kruskal(int n, vector<arista> &g) {
    sort(all(g)); DSU dsu(n);
    vector<arista> mst;
    for(arista e : g) {
        if(!dsu.same(e.v, e.u)){
            dsu.join(e.v, e.u); mst.pb(e);
        }
    }
    return mst;
}
