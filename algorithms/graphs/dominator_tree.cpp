// Dominator Tree
// Description: Given a directed graph, find the dominator tree of the graph
// Time: O(nlogn)
// Usage: Dominator_Tree dt(n,g,root); // n --> number of nodes, g --> graph, root --> root of the tree
// If u is an ancestor of v in the dominator tree, then u dominates v


#define rz(n) resize(n)

struct Dominator_Tree {
    vector<vector<int>> g, tree, rg, bucket;
    vector<int> sdom, par, dom, dsu, label;
    vector<int> arr, rev; 
    int n, T = 0, root;

    int Find(int u,int x=0) {
        if(u==dsu[u])return x?-1:u;
        int v = Find(dsu[u],x+1);
        if(v<0)return u;
        if(sdom[label[dsu[u]]]<sdom[label[u]]) {
            label[u] = label[dsu[u]];
        }
        dsu[u] = v;
        return x ? v : label[u];
    }

    void Union(int u,int v) { //Add an edge u-->v
        dsu[v] = u;   
    }

    void dfs0(int u) {
        T++; arr[u] = T; rev[T] = u;
        label[T] = T; sdom[T] = T; dsu[T] = T;
        for(int i = 0; i < SZ(g[u]); i++) {
            int w = g[u][i];
            if(!arr[w]) {
                dfs0(w);
                par[arr[w]]=arr[u];
            }
            rg[arr[w]].pb(arr[u]);
        }
    }

    Dominator_Tree(int _n, vector<vector<int>> _g, int _root) {
        n = _n; root = _root;
        g = _g; tree.rz(n+5); rg.rz(n+5); bucket.rz(n+5); sdom.rz(n+5); 
        par.rz(n+5); dom.rz(n+5); dsu.rz(n+5); label.rz(n+5);
        arr.rz(n+5); rev.rz(n+5);
        dfs0(root);


        for(int i = n; i >= 1; i--) {
            for(int j = 0; j < SZ(rg[i]); j++) {
                sdom[i] = min(sdom[i],sdom[Find(rg[i][j])]);
            }
            if(i>1)bucket[sdom[i]].pb(i);
            for(int j = 0; j < SZ(bucket[i]); j++) {
                int w = bucket[i][j],v = Find(w);
                if(sdom[v] == sdom[w]) dom[w] = sdom[w];
                else dom[w] = v;
            }
            if(i>1)Union(par[i],i);
        }

        forr(i, 2, n+1){
            if(dom[i] != sdom[i]) dom[i] = dom[dom[i]];
            tree[rev[i]].pb(rev[dom[i]]);
            tree[rev[dom[i]]].pb(rev[i]);
        }

    }
};

