typedef long long tipo;
struct segtree {
  vector <tipo> t; int tam;
  tipo NEUT = 0; 
  tipo op(tipo a, tipo b){ return a+b; }
  void build(vector<tipo>v, int n) {  
    tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
    t.resize(2*tam,NEUT); forn(i, n) t[tam+i] = v[i];
    for(int i = tam - 1; i > 0; i--) t[i] = op(t[i<<1], t[i<<1|1]);
  }
  void update(int p, tipo value) {  
    for (t[p += tam] = value; p > 1; p >>= 1) t[p>>1] = op(t[p], t[p^1]);
  }
  tipo query(int l, int r) { 
    tipo res = NEUT;
    for (l += tam, r += tam; l <= r; l >>= 1, r >>= 1) {
      if (l&1) res = op(res, t[l++]);
      if (!(r&1)) res = op(res, t[r--]);
    }
    return res;
  }
};
