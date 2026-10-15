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
const ll INF = 1LL<<60; // const ll INF = (1LL<<60);
const int MOD = 1e9+7;  // const int MOD = 998244353;
const int MAXN  = 2e5+5;

typedef long long tipo;
const tipo NEUT = INF; // REMINDER !!! 

struct node {
    int l, r; tipo ans, cont;
    node() {ans = NEUT, l = r = -1;} // REMINDER !!! Set NEUT
    node(tipo val, int pos): l(pos), r(pos),ans(val), cont(1) {} // Set node
    void update(tipo val) {ans = val;} // Define update function
};

struct segtree { // Segtree for Sum Range Query
    #define l(x) int(x<<1)
    #define r(x) int(x<<1|1)
    
    vector<node> t; int tam;

    node op(node a, node b) { //Operacion de query
        node aux; 
        if(a.ans == b.ans) {
			aux.ans = a.ans;
			aux.cont = a.cont+b.cont;
		} else if(a.ans < b.ans) {
			aux.ans = a.ans;
			aux.cont = a.cont;
		} else {
			aux.ans = b.ans;
			aux.cont = b.cont;
		}
        aux.l = a.l; aux.r = b.r;
        return aux;
    }

	node query(int l, int r, int p = 1) {
		node &cur = t[p];
		if(l > cur.r || r < cur.l) return node(); // Return NEUT
		if(l <= cur.l && cur.r <= r) return cur;
		return op(query(l,r,l(p)),query(l,r,r(p)));
    }

	void update(int pos, tipo val, int p = 1) { // root at p = 1
        node &cur = t[p];
		if(cur.r < pos || cur.l > pos) return;
		if(cur.l == cur.r) { cur.update(val); return; }
		update(pos, val, l(p)); update(pos, val, r(p));
		cur = op(t[l(p)], t[r(p)]);
	}

    void build(vector<tipo> v, int n) { // iterative build
        tam = sizeof(int) * 8 - __builtin_clz(n-1); tam = 1<<tam;
        t.resize(2*tam); v.resize(tam);
        forn(i,tam) t[tam+i] = node(v[i],int(i));
        for(int i = tam - 1; i > 0; i--) t[i] = op(t[l(i)],t[r(i)]); 
    }
};

int main() {
	FIN;
	
	int n, m;
	cin >> n >> m;
	
	vector <ll> v(n);
	forn(i,n) cin >> v[i];
	
	segtree st;
	st.build(v,n);
	
	forn(_,m) {
		int op; cin >> op;
		if(op == 1) {
			int idx; ll val;
			cin >> idx >> val;
			st.update(idx,val); // 0 indexado en el array
			//~ forn(i,n) cerr << st.query(i,i).ans << " "; cerr << endl;
		} else {
			int l, r;
			cin >> l >> r;
			node ans = st.query(l,r-1);
			cout << ans.ans << " " << ans.cont << "\n";
		}
	}
	
	
	
	
	return 0;
}
