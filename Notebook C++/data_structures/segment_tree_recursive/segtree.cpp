typedef long long tipo;
const tipo NEUT = 0; // REMINDER !!! 

struct node {
    int l, r; tipo ans;
    node() {ans = NEUT, l = r = -1;} // REMINDER !!! Set NEUT
    node(tipo val, int pos): l(pos), r(pos),ans(val) {} // Set node
    void update(tipo val) {ans = val;} // Define update function
};

struct segtree { // Segtree for Sum Range Query
    #define l(x) int(x<<1)
    #define r(x) int(x<<1|1)
    
    vector<node> t; int tam;

    node op(node a, node b) { //Operacion de query
        node aux; aux.ans = a.ans + b.ans; 
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
        tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
        t.resize(2*tam); v.resize(tam);
        forn(i,tam) t[tam+i] = node(v[i],int(i));
        for(int i = tam - 1; i > 0; i--) t[i] = op(t[l(i)],t[r(i)]); 
    }
};

//~ Max Sum Query
struct node {
	tipo ans, pref, suff, sum, l, r;
	node() {ans = pref = suff = sum = NEUT, l = r = -1;}
	node(tipo val, int pos) : ans(val), pref(val), suff(val), sum(val), l(pos), r(pos) {}
    void update(tipo val) {ans = pref = suff = sum = val;} 
};

node op(node a, node b) {
	node aux; 
	aux.pref = max(a.pref, a.sum + b.pref);
	aux.suff = max(b.suff, b.sum + a.suff);
	aux.sum = a.sum + b.sum;
	aux.ans = max(max(a.ans,b.ans),a.suff + b.pref);
	aux.l = a.l; aux.r = b.r;
	return aux;
}
