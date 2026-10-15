typedef long long tipo;

struct node {
	tipo ans, l, r, a=0, d=0;
	bool upd; 
	node() {ans = a = d = 0;}
	node(tipo val, int pos) {ans = val; l = r = pos;}
	void set_lazy(tipo _a, tipo _d, tipo start) {
		upd=true, a += (l-start)*_d + _a; d += _d;
	}
};
 
struct lazy {
	
	#define l(x) int(x<<1)
	#define r(x) int(x<<1|1)
  
	vector <node> t; int tam;
	
	node op(node a, node b) { //Operacion de query
        node aux; aux.ans = a.ans + b.ans;
		aux.l = a.l; aux.r = b.r;
        return aux;
    }
  
	void push(tipo p) {
		if(t[p].upd == true) {
			tipo d = t[p].r - t[p].l + 1;
			t[p].ans += d * t[p].a;
			t[p].ans += t[p].d * (d-1)*(d)/2;
			if(t[p].l < t[p].r) {
				t[l(p)].set_lazy(t[p].a,t[p].d,t[p].l);
				t[r(p)].set_lazy(t[p].a,t[p].d,t[p].l);
			}
			t[p].a = 0; t[p].d = 0; t[p].upd = false;
		}
	}
  
	node query(tipo l, tipo r, int p = 1) {
		push(p); 
		if(l > t[p].r || r < t[p].l) return node();
		if(l <= t[p].l && t[p].r <= r) return t[p];
		return op(query(l,r,l(p)),query(l,r,r(p)));		
	}
  
	void update(tipo l, tipo r, tipo a, tipo d, int p = 1) {
		push(p); node &cur = t[p];
		if(l > cur.r || r < cur.l) return;
		if(l <= cur.l && cur.r <= r) {
			cur.set_lazy(a,d,l); push(p); return;
		}
		update(l, r, a, d, l(p)); update(l, r, a, d, r(p));
		cur = op(t[l(p)], t[r(p)]);
	}
  
	void build(vector<tipo> v, int n) { // iterative build
        tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
        t.resize(2*tam); v.resize(tam);
        forn(i,tam) t[tam+i] = node(v[i],int(i));
        for(int i = tam - 1; i > 0; i--) t[i] = op(t[l(i)],t[r(i)]); 
    }
};
