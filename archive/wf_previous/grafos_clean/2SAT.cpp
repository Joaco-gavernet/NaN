// 2sat (2-satisfiability) - O(n + m) (Korasaju)
struct two_sat { // 2*x representa a x, y 2*x+1 a ~x
    int tot;
    vector<vector<int>> g, g_trans;
    vb used, assignment;
    vector<int> order, comp;
    two_sat(int _tot): tot(_tot){
        g.resize(tot); g_trans.resize(tot);
    } // tot = total de nodos (normales + negados), en general n = tot/2
    void dfs1(int v) {
        used[v] = true;
        for(auto u: g[v]) if(!used[u]) dfs1(u);
        order.pb(v);
    }
    void dfs2(int v, int cl) { // Korasaju para encontrar las SCC
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
            assignment[i] = comp[2*i] > comp[2*i+1]; // asignacion greedy de variables
        }
        return true;
    }
    void add_edge(int from, int to){ // implicancia comun from->to
        g[from].pb(to);
        g_trans[to].pb(from); // agregar en el TRANSPUESTO
    }
    void add_or(int v1, int v2) { // agrega (v1 or v2)
        add_edge(v1 ^ 1, v2); // ~v1 -> v2
        add_edge(v2 ^ 1, v1); // ~v2 -> v1
    }
    // setear variable x en true/false: add_or(x, x)/add_or(~x, ~x)
};
