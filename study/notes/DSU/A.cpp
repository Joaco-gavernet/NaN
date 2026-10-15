/*   AUTHOR: Estufa en Piloto   */
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl
#else
#define DBG(x)
#define RAYA
#endif

typedef long long ll;
typedef vector<ll> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1<<30; // const ll INF = (1LL<<60);
const int MOD = 1e9+7;  // const int MOD = 998244353;
const int MAXN  = 2e5+5;

struct arista {
    int u, v;
    ll w;
    arista(int _u, int _v, ll _w) {
		u = _u;
		v = _v;
		w = _w;
	}
    bool operator<(const arista& other) const { return w < other.w; }
};

struct DSU {
    vi link, sz;

    DSU(int tam) {
        link.resize(tam+5), sz.resize(tam+5);
        forn(i, tam+5) link[i] = i, sz[i] = 1;
    }

    ll find(ll x){ return link[x] = (link[x] == x ? x : find(link[x])); }
    bool same(ll a, ll b) { return find(a) == find(b); }

    void join(ll a, ll b) {
        a = find(a), b = find(b);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a,b);
        sz[a] += sz[b];
        link[b] = a;
    }
};

vector<arista> kruskal(int n, vector<arista> &g) {
    sort(all(g)); DSU dsu(n);
    vector<arista> mst;
    for(arista e : g) {
        if(!dsu.same(e.v, e.u)){
            dsu.join(e.v, e.u); mst.pb(e);
        }
    }
    return mst;
}

int main(){  
    FIN;

	int n, m;
	cin >> n >> m;
	vector <arista> g;
	forn(i,m) {
		int x, y; ll peso;
		cin >> x >> y >> peso;
		x--; y--;
		g.pb(arista(x,y,peso));
	}
	vector <arista> mst = kruskal(n,g);
	ll min_w = 0;
	for(arista u : mst) min_w += u.w;
	cout << min_w << "\n";
	

    return 0;
}
