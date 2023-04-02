vector < vector <int> > g(MAXN);
vector <bool> visto(MAXN,false);

void DFS(int v, int &new_start, int &ans, int l) {
    visto[v] = true; 
    if(l > ans) ans = l, new_start = v;
    for(int u : g[v]) if(!visto[u]) DFS(u,new_start,ans,l+1);
}

int find_diameter() {
    int ans = 0, new_start;
    DFS(0,new_start,ans,0); fill(all(visto),false);
    DFS(new_start,new_start,ans,0);
    return ans;
}
