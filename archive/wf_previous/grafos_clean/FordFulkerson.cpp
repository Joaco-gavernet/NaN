struct FordFulkerson {
	// Time complexity ((V+E) * MAXFLOW)
	vector < vector<arista> > g;
	map < pair<int,int>,int > cap;
	FordFulkerson(int n) {
		g.resize(n+5);
	}
	void add_edge(int x, int y, int z) { // x --> y con cap z
	  g[x].pb({y});
	  g[y].pb({x});
	  cap[{x,y}] = z; // cap[{x,y}] += z; if multiedges allowed
	}
	void DFS(int cur, vector <int> &parent, vector<int> &flow, int prev, int cur_flow = INF) {
		parent[cur] = prev;
		flow[cur] = cur_flow;
		for(auto [next] : g[cur]) {
			if(parent[next] != -1 or cap[{cur,next}] == 0) continue;
			DFS(next,parent,flow,cur,min(cur_flow,cap[{cur,next}]));
		}
	}
	int max_flow(int s, int t) {
		int maxflow = 0;
		vector <int> parent(MAXN,-1), flow(MAXN,-1);
		DFS(s,parent,flow,s);
		//~ forn(i,t) cerr << flow[i] << " "; cerr << endl;
		while(flow[t] > 0) {
			int new_flow = flow[t];
			maxflow += new_flow;
			int cur = t;
			while(cur != s) {
				int prev = parent[cur];
				cap[{prev,cur}] -= new_flow;
				cap[{cur,prev}] += new_flow;
				cur = prev;
			}
			fill(all(parent),-1);
			fill(all(flow),0);
			DFS(s,parent,flow,s);
		}
		return maxflow;
	}
};
