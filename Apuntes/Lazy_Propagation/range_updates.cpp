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

typedef long long tipo;
const int NEUT = 0; // REMINDER !!! 

// op == 1 --> incrementar
// op == 2 --> setear

struct node {
	tipo ans, l, r, lazy = 0, op = 0;
	bool upd = false;
	node() {ans = lazy = 0; upd = false; l = r = -1;} // REMINDER !!! SET NEUT
	node(tipo val, int pos) : ans(val), l(pos), r(pos), op(0) {} // Set node
	void set_lazy(tipo x, int op_nueva) {
		if(op == 0) {
			op = op_nueva;
			lazy = x;
			upd = true;
		} else if(op == 1) {
			if(op_nueva == 1) {
				lazy += x; upd = true;
			} else if(op_nueva == 2) {
				lazy = x; op = 2; upd = true;
			}
		} else if(op == 2) {
			if(op_nueva == 1) {
				lazy += x; upd = true;
			} else if(op_nueva == 2) {
				lazy = x; upd = true;
			}
		}
	}
};
 
struct segtree_lazy {
	#define l(x) int(x<<1)
	#define r(x) int(x<<1|1)
    
	vector <node> t; int tam;
 
	node op(node a, node b) {
		node aux; aux.ans = a.ans + b.ans; //Operacion de query
		aux.l = a.l; aux.r = b.r;
		return aux;
	}
	
	void push(int p) {
		node &cur = t[p];
		if(cur.upd == true) {
			if(cur.op == 1) {
				cur.ans += cur.lazy * (cur.r-cur.l+1);
			} else if(cur.op == 2) {
				cur.ans = cur.lazy * (cur.r-cur.l+1);
			}
			if(cur.l < cur.r) {
				t[l(p)].set_lazy(cur.lazy,cur.op);
				t[r(p)].set_lazy(cur.lazy,cur.op);
			}
			cur.lazy = 0; cur.upd = false; cur.op = 0;//Poner el neutro del update
		}
	}
 
	node query(int l, int r, int p = 1) {
		push(p); node &cur = t[p];
		if(l > cur.r || r < cur.l) return node(); // Return NEUT
		if(l <= cur.l && cur.r <= r) return cur;
		return op(query(l,r,l(p)),query(l,r,r(p)));
	}
 
	void update(int l, int r, tipo val, int op_nueva, int p = 1) { // root at p = 1
		push(p); node &cur = t[p];
		if(l > cur.r || r < cur.l) return;
		if(l <= cur.l && cur.r <= r) {
			cur.set_lazy(val,op_nueva); push(p); return;
		}
		update(l, r, val, op_nueva, l(p)); update(l, r, val, op_nueva, r(p));
		cur = op(t[l(p)], t[r(p)]);
		
	}
 
	void build(vector <tipo> v, int n) { // iterative build
		tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
		t.resize(2*tam); v.resize(tam);
		forn(i,tam) t[tam+i] = node(v[i],i);
		for(int i = tam - 1; i > 0; i--) t[i] = op(t[l(i)],t[r(i)]); 
	}
};

int main(){  
    FIN;
	
	int n, q;
	cin >> n >> q;
	vector <ll> v(n);
	forn(i,n) cin >> v[i];
	segtree_lazy st;
	st.build(v,n);
	
	forn(_,q) {
		int op; cin >> op;
		if(op == 1) {
			int l, r; ll x;
			cin >> l >> r >> x;
			l--; r--;
			st.update(l,r,x,1);
		} else if(op == 2) {
			int l, r; ll x;
			cin >> l >> r >> x;
			l--; r--;
			st.update(l,r,x,2);
		} else {
			int l, r;
			cin >> l >> r;
			l--; r--;
			cout << st.query(l,r).ans << "\n";
		}
	}


    return 0;
}
