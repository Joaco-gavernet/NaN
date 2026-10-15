// Description: Bellman-Ford algorithm for finding the shortest path from a source to all other nodes in a graph. It can also detect negative cycles.
// Time: O(VE)

typedef long long tipo;
const int MAXN = 3000;
tipo INF = (tipo)(1e18+7);

struct arista {
    int x, y; tipo w; // Edge from x to y, w = weight
};

struct nodo {
    int p; tipo d; //f -> parent, d -> distance
};

vector<nodo> ans(MAXN);
vector<int> ciclo; 

bool bFord(vector<arista> &lista, int n, int start) {
    forn(i,n) ans[i].p = i, ans[i].d = INF;
    ans[start].d = 0; int x;
    forn(i,n) {
        x = -1;
        for(arista u : lista) {
            if(ans[u.y].d > ans[u.x].d + u.w) {
                ans[u.y].d = ans[u.x].d + u.w;
                ans[u.y].p = u.x;
                x = u.y;
            }
        }
    }
    if(x == -1) return false;
    else {
        forn(i,n) x = ans[x].p;
        for(int v = x ;; v = ans[v].p) {
            ciclo.push_back(v);
            if(v == x && ciclo.size() > 1) break;
        }
        reverse(all(ciclo));
        return true;
    }
}

