typedef long long tipo;
const int NEUT = 0; // REMINDER !!! 

struct node {
	tipo ans, l, r, lazy = 0;
	bool upd = false;
	node() {ans = lazy = 0; upd = false; l = r = -1;} // REMINDER !!! SET NEUT
	node(tipo val, int pos) : ans(val), l(pos), r(pos) {} // Set node
	void set_lazy(tipo x) {lazy += x; upd = true;}
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
			cur.ans += cur.lazy * (cur.r-cur.l+1); //Operacion update
			if(cur.l < cur.r) {
				t[l(p)].lazy += cur.lazy; t[l(p)].upd = true;
				t[r(p)].lazy += cur.lazy; t[r(p)].upd = true;
			}
			cur.lazy = 0; cur.upd = false; //Poner el neutro del update
		}
	}
 
	node query(int l, int r, int p = 1) {
		push(p); node &cur = t[p];
		if(l > cur.r || r < cur.l) return node(); // Return NEUT
		if(l <= cur.l && cur.r <= r) return cur;
		return op(query(l,r,l(p)),query(l,r,r(p)));
	}
 
	void update(int l, int r, tipo val, int p = 1) { // root at p = 1
		push(p); node &cur = t[p];
		if(l > cur.r || r < cur.l) return;
		if(l <= cur.l && cur.r <= r) {
			cur.set_lazy(val); push(p); return;
		}
		update(l, r, val, l(p)); update(l, r, val, r(p));
		cur = op(t[l(p)], t[r(p)]);
		
	}
 
	void build(vector <tipo> v, int n) { // iterative build
		tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
		t.resize(2*tam); v.resize(tam);
		forn(i,tam) t[tam+i] = node(v[i],i);
		for(int i = tam - 1; i > 0; i--) t[i] = op(t[l(i)],t[r(i)]); 
	}
};
