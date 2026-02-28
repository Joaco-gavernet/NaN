struct two_sat { // 2*x es x, 2*x+1 es ~x
    int tot;
    vector<vector<int>> g, g_trans;
    vb used, assignment;
    vector<int> order, comp;

    two_sat(int _tot): tot(_tot){
        g.resize(tot); g_trans.resize(tot);
    } // tot = (normales + negados)

    void dfs1(int v) {
        used[v] = true;
        for(auto u: g[v]) if(!used[u]) dfs1(u);
        order.pb(v);
    }

    void dfs2(int v, int cl) { 
        comp[v] = cl;
        for(auto u: g_trans[v]) if(comp[u] == -1) dfs2(u, cl);
    }

    bool solve() {
        order.clear(); used.assign(tot, false);
        comp.assign(tot, -1);
        forn(i, tot) if(!used[i]) dfs1(i);

        int comp_act = 0;
        forn(i, tot){
            auto v = order[tot-i-1];
            if(comp[v] == -1) dfs2(v, comp_act++);
        }

        assignment.assign(tot/2, false);
        forn(i, tot/2){
            if(comp[2*i] == comp[2*i + 1]) return false;
            assignment[i] = comp[2*i] > comp[2*i+1]; 
        }
        return true;
    }

    void add_edge(int from, int to){ 
        g[from].pb(to); // from implica to
        g_trans[to].pb(from); 
    }

    void add_or(int v1, int v2) { 
        add_edge(v1 ^ 1, v2); // ~v1 -> v2
        add_edge(v2 ^ 1, v1); // ~v2 -> v1
    } // set x en true/false:
};    // add_or(x, x)/add_or(~x, ~x)
