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

// Small to large techique. 
struct query { // Queries to answer, v: vertex, c: color, idx: ans pos
    ll v, c, idx; 
};
 
vi g[MAXN];
vector<query> q[MAXN]; // Queries to answer
vi ans(MAXN, -1), color; // Answer to each query
 
unordered_map<ll, ll> cnt[MAXN]; // struct to store the info and merge
vector <pair<ll,ll>> max_cnt(MAXN);

int merge(int v, int u){ 
    if(SZ(cnt[v]) < SZ(cnt[u])) swap(u, v); // now v is the large one
    for(auto [x, y]: cnt[u]){
        cnt[v][x] += y;
        if(cnt[v][x] > max_cnt[v].first) {
			max_cnt[v] = {cnt[v][x],x};
		} else if(cnt[v][x] == max_cnt[v].first) {
			max_cnt[v].second += x;
		}
    }
    cnt[u].clear(); // Clear the small one to mantain memory in O(n)
    return v; // return the large node
}   
 
// Process the queries of v, v_repr is the representative of v (large 
// node after merging v and its children)
void process_queries(int v, int v_repr){
    for(auto &[_v, c, i]: q[v]) {
		ans[i] = max_cnt[v_repr].second;
		//~ ans[i] = SZ(cnt[v_repr]); // Number of distinct colors
		//~ ans[i] = cnt[v_repr][c]; // Number of nodes with color c
	}
}
 
int dfs(int v, int p){
    int v_repr = v; // Initialize the representative of v
    cnt[v][color[v]]++; // Initialize counter
    max_cnt[v] = {1,color[v]};
    
    for(auto u: g[v]){
        if(u == p) continue;
        int u_repr = dfs(u, v); // Get the representative of u
        v_repr = merge(v_repr, u_repr); // Merge u_repr into v_repr
    }
    
    process_queries(v, v_repr); // Offline process the queries of v
 
    return v_repr;
}

void solve(int m) { // number of queries
	dfs(0,-1);
	forn(i,m) cout << ans[i] << " ";
	cout << "\n";
}
 

int main(){  
    FIN;

	int n; cin >> n;
	color.resize(MAXN);
	forn(i,n) cin >> color[i];
	forn(i,n-1) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		g[x].pb(y); g[y].pb(x);
	}
	forn(i,n) {
		q[i].pb({i,-1,i});
	}
	solve(n);
	//~ forn(i,n) cout << ans[i] << " "; cout << "\n";
	//~ forn(i,n) cerr << max_cnt[i].first << " " << max_cnt[i].second << endl;
    return 0;
}
