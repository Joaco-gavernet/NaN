/*
   Algoritmo para hallar las componentes fuertmente conexas.
   Una componente es fuertemente conexa cuando para todo nodo
   perteneciente a la componente, se puede llegar a cualquier 
   otro nodo tambien perteneciente a la componente.
*/
struct SCC {
    int n, scc;
    vector<vi> g, gr, ans;
    vb visto;
    vi order, comp_act, component;

    SCC(vector<vi> &_g): n(SZ(_g)) {
        g = _g;
        gr.resize(n), visto.resize(n), component.resize(n);
        forn(v, n) for(auto u: g[v]) gr[u].pb(v); // me lo creo aca el grafo traspuesto
    
        find_scc(); 
    }

    void DFS1 (int v) {
        visto[v] = true;
        for (int u : g[v]) if(!visto[u]) DFS1(u);
        order.pb(v);
    }

    void DFS2 (int v) {
        visto[v] = true;
        comp_act.pb(v);
        for (int u : gr[v]) if(!visto[u]) DFS2(u);
    }

    void find_scc() {
        fill(all(visto),false);
        forn(i,n) if(!visto[i]) DFS1(i);
        fill(all(visto),false);
        forn(i,n) {
            int v=order[n-i-1];
            if(!visto[v]) { 
                DFS2(v);
                ans.pb(comp_act);
                comp_act.clear();
            }
        }
        scc = SZ(ans); // cantidad de scc's
        forn(i, scc) for(auto v: ans[i]) component[v] = i;
    }
};
