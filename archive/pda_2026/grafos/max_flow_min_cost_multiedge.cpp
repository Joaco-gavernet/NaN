typedef long long tipo;
typedef long long tipo_cost;
const int MAXN = 505;
tipo INF = (tipo)(1e9+7);
tipo_cost MAX_COST = (tipo_cost)(1e16);

struct arista {
  int v; 
  tipo cap;
  tipo_cost c; // Cost
  int id;
};

struct prev_node {
  int prev, id;
  void setting() {prev = -1, id = -1;}
};

vector < vector<arista> > g(MAXN);
vector <tipo> cap;

void add_edge(int x, int y, tipo z, tipo_cost c) {
  int id = cap.size();
  g[x].pb({y,z,c,id});
  g[y].pb({x,0,-1*c,id+1});
  cap.pb(z); cap.pb(0);
}

void Bellman_Ford(int s, int t, vector <prev_node> &parent, vector <tipo_cost> &d) {
  for(prev_node u : parent) u.setting();
  fill(all(d),MAX_COST);
  vector <bool> inq(MAXN,false);
  queue <int> q; q.push(s); parent[s] = {s,-1}; inq[s] = true; d[s] = 0;
  
  while(q.size() > 0) {
    int u = q.front(); q.pop(); inq[u] = false;
    for(arista next : g[u]) {
      if(cap[next.id]>0 && d[next.v] > d[u] + next.c) {
        d[next.v] = d[u] + next.c;
        parent[next.v] = {u,next.id};
        if(!inq[next.v]) {
          inq[next.v] = true;
          q.push(next.v);
        }
      }
    }
  }
}


tipo_cost max_flow_min_cost(int s, int t, int total) {
  tipo flow = 0;
  tipo_cost min_cost = 0;
  vector <prev_node> parent(MAXN);
  vector <tipo_cost> d(MAXN);
  
  while(true) {
    Bellman_Ford(s,t,parent,d);
    if(d[t] == MAX_COST) break;
    
    tipo new_flow = INF;
    int cur = t;
    while(cur != s) {
      new_flow = min(new_flow,cap[parent[cur].id]);
      cur = parent[cur].prev;
    }
    
    flow += new_flow;
    min_cost += d[t] * (tipo_cost)(new_flow);
    cur = t;
    while(cur != s) {
      int prev = parent[cur].prev;
      int id = parent[cur].id;
      cap[id] -= new_flow;
      cap[(id^1)] += new_flow;
      cur = prev;
    }
  }
  if(flow < total) return -1;
  return min_cost;
}
