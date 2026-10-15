/*
Algoritmo de Kuhn para bipartite matching, se le pasa el grafo
y encuentra el matching maximo en O(VE).
La pareja de cada nodo se guarda en match[i], sino -1
*/

struct bipartite_matching { 
  int n;
  vector<vi> g; // 0-indexed
  vb vis; vi match;

  bipartite_matching(int _n, vector<vi> _g): n(_n), g(_g) {
    vis.resize(n), match.resize(n);
  }
  
  bool dfs(int node){
    if(vis[node])return 0;
    vis[node] = 1;
    for(auto nx : g[node]){
      if(match[nx]==-1 || dfs(match[nx])){
        match[node] = nx; match[nx] = node;
        return 1;
      }
    }
    return 0;
  }
  
  int solve() { // toma los nodos de 0 a n-1
    fill(all(match),-1);
    while(true) {
      fill(all(vis),false);
      bool cont = 0;
      forn(i, n) if(match[i] == -1) cont |= dfs(i);
      if(cont==0) break;
    }
    int matching = 0; 
    forn(i, n) if(match[i] != -1) matching++;
    return matching; // hay que dividir por 2 si quiero la cantidad de parejas
  }
};
