typedef long long tipo;
typedef double tipo_cost;
const int MAXN = 505;
tipo INF = (tipo)(1e9+7);
tipo_cost MAX_COST = (double)(1e16);

struct arista {
  int v; // Next node
  tipo_cost c; // Cost
};

vector < vector<arista> > g(MAXN);
map < pair<int,int>,tipo > cap;
map < pair<int,int>,tipo_cost > cost;

void add_edge(int x, int y, tipo z, tipo_cost c) {
  g[x].pb({y,c});
  g[y].pb({x,-1.0*c});
  cap[{x,y}] += z;
  cost[{x,y}] += c;
  cost[{y,x}] -= c;
}

void Bellman_Ford(int s, int t, vector <int> &parent, vector <tipo_cost> &d) {
  fill(all(parent),-1);
  fill(all(d),MAX_COST);
  vector <bool> inq(MAXN,false);
  queue <int> q; q.push(s); parent[s] = s; inq[s] = true; d[s] = 0;
  
  while(q.size() > 0) {
    int u = q.front(); q.pop(); inq[u] = false;
    for(arista next : g[u]) {
      if(cap[{u,next.v}]>0 && d[next.v] > d[u] + next.c) {
        d[next.v] = d[u] + next.c;
        parent[next.v] = u;
        if(!inq[next.v]) {
          inq[next.v] = true;
          q.push(next.v);
        }
      }
    }
  }
}


tipo_cost max_flow_min_cost(int s, int t) {
  tipo flow = 0;
  tipo_cost min_cost = 0;
  vector <int> parent(MAXN);
  vector <tipo_cost> d(MAXN);
  
  while(true) {
    Bellman_Ford(s,t,parent,d);
    if(d[t] == MAX_COST) break;
    
    tipo new_flow = INF;
    int cur = t;
    while(cur != s) {
      new_flow = min(new_flow,cap[{parent[cur],cur}]);
      cur = parent[cur];
    }
    
    flow += new_flow;
    min_cost += d[t] * (tipo_cost)(new_flow);
    cur = t;
    while(cur != s) {
      int prev = parent[cur];
      cap[{prev,cur}] -= new_flow;
      cap[{cur,prev}] += new_flow;
      cur = prev;
    }
  }
  return min_cost;
}
