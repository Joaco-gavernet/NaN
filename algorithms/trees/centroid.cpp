struct centroid {
	vector<vector<int>> g; int n;
	vector<vector<int>> c_tree;
	bool tk[MAXN];
	int fat[MAXN]; // father in centroid decomposition
	int szt[MAXN]; // size of subtree
	int centro = -1;
	int calcsz(int x, int f){
		szt[x]=1;
		for(auto y:g[x])if(y!=f&&!tk[y])szt[x]+=calcsz(y,x);
		return szt[x];
	}
	void cdfs(int x=0, int f=-1, int sz=-1){ // O(nlogn)
		if(sz<0)sz=calcsz(x,-1);
		for(auto y:g[x])if(!tk[y]&&szt[y]*2>=sz){
			szt[x]=0;cdfs(y,f,sz);return;
		}
		tk[x]=true;fat[x]=f;
		for(auto y:g[x])if(!tk[y])cdfs(y,x);
	}
	centroid(vector <vector<int>> gg, int nn) {
		g = gg; n = nn; memset(tk,false,sizeof(tk));cdfs();
		c_tree.resize(n);
		forn(i,n) {
			if(fat[i] == -1) centro = i;
			else c_tree[fat[i]].pb(i);
		}
	}
};
 
