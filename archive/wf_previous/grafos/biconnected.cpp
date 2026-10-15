struct edge{ ll u, v, id; };

struct graph{
    int n;
    vector<vii> adj; // (to, id)
    vector<edge> edges;
    graph(int _n) : n(_n), adj(_n) {}

    void add_edge(ll u, ll v){
		ll id = SZ(edges);
        adj[u].pb({v, id}); adj[v].pb({u, id});
        edges.pb({u, v, id});
    }

    int add_node(){ adj.pb({}); return n++; }
    vii& operator[](ll u) { return adj[u]; }
};

struct BCC{
    int n; graph adj;
    vector<vi> comps;
    vi num, low, art, stk, bridge;
    BCC(graph &_adj): n(_adj.n), adj(_adj){
        num.resize(n), low.resize(n), art.resize(n), bridge.resize(SZ(adj.edges));
        for (ll u = 0, t; u < n; ++u) if (!num[u]) dfs(u, -1, t = 0);
    }

    void dfs(ll v, ll p, ll &t){
        num[v] = low[v] = ++t;
        stk.pb(v);

        for(auto [u, id]: adj[v]) if (u != p){
            if (!num[u]){
                dfs(u, v, t);
                low[v] = min(low[v], low[u]);
				
				if(low[u] > num[v]) bridge[id] = true;
                if(low[u] >= num[v]){
                    art[v] = (num[v] > 1 || num[u] > 2);

                    comps.pb({v});
                    while (comps.back().back() != u)
                        comps.back().pb(stk.back()), stk.pop_back();
                }
            }
            else low[v] = min(low[v], num[u]);
        }
    }

    // build the block cut tree
    pair<vi, graph> build_tree(){
        graph tree(0); vi id(n);

        forn(v, n) if (art[v]) id[v] = tree.add_node();

        for (auto &comp : comps){
            ll node = tree.add_node();
            for(ll v: comp){
                if (!art[v]) id[v] = node;
                else tree.add_edge(node, id[v]);
            }
        }
        return {id, tree};
    }
};
