/*
Algoritmo de Edmonds-Karp, halla el max flow en O(VE^2).
Para eso, va eligiendo caminos de aumento con la menor cantidad de aristas
en el grafo residual.

El min_cut esta formado por las aristas que unen un nodo alcanzable por
s en el grafo residual final, con un nodo inalcanzable.
*/
typedef long long tipo; // el tipo en que se mide el flow

struct max_flow { // Edmonds-Karp, O(VE^2)
    int n;
    vector<vector<int>> g;
    vector<vector<tipo>> cap; 
    // si n es grande (>5000), hay que usar un map de capacidades

    max_flow(int n): n(n){
        g.resize(n), cap.resize(n, vi(n)); 
    }
    void add_edge(int x, int y, tipo z){
        g[x].pb(y), g[y].pb(x);
        cap[x][y] += z;
    }
    tipo bfs(int s, int t, vector<int> &parent){
        fill(all(parent), -1);
        queue<pair<int, tipo>> q; q.push({s, INF});
        parent[s] = s;

        while(!q.empty()){
            int cur = q.front().first; 
            tipo flow = q.front().second; q.pop();

            for(int next: g[cur]){
                if(parent[next] == -1 && cap[cur][next]) {
                    parent[next] = cur; 
                    tipo new_flow = min(flow, cap[cur][next]);
                    if(next == t) return new_flow;
                    q.push({next,new_flow});
                }
            }
        }
        return 0; // no encontre aug paths
    }

    tipo get_max_flow(int s, int t){
        tipo flow = 0, new_flow;
        vector<int> parent(n);

        while((new_flow = bfs(s, t, parent))){
            flow += new_flow;
            int cur = t;
            while(cur != s){
                int prev = parent[cur];
                cap[prev][cur] -= new_flow;
                cap[cur][prev] += new_flow;
                cur = prev;
            }
        }
        return flow;
    }

    void remove_dups(vector<int> &a){
        sort(all(a)); a.erase(unique(all(a)), a.end());
    }

    vector<pair<int, int>> get_min_cut(int s, int t) {
        // cambiar ans a set<pair<int, int>> 
        // si no se quiere usar remove dups
        vector<pair<int, int>> ans;
        for(auto &x: g) remove_dups(x);

        get_max_flow(s, t); // si ya se corrio afuera, comentar

        vector<int> parent(n);
        bfs(s, t, parent); // hago bfs en el grafo residual final
        forn(v, n){
            for(auto u: g[v]){
                if(parent[v] != -1 && parent[u] == -1){
                    ans.pb({v, u});
                }
            }
        }
        return ans;
    }
};

// encontrar paths disjuntos (si tienen cap 1)
// ini_cap es lo mismo que cap antes de correr el flow.
vector<int> path;
bool find_paths(int v, max_flow &mf){
    path.pb(v);
    if(v == mf.n-1) return true;
    for(int u : mf.g[v]) {
        if(mf.ini_cap[v][u] && !mf.cap[v][u]){
            mf.cap[v][u] = 1; // marco la arista como usada (dessaturandola)
            if(find_paths(u, mf)) return true;
            mf.cap[v][u] = 0;
        }
    }
    path.pop_back();
    return false;
}