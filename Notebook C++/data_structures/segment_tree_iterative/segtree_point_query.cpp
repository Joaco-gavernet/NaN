typedef ll tipo;
struct segtree {
  vector<tipo> t; int tam;
  tipo NEUT = 0;
  tipo op(tipo a, tipo b){ return a + b; }

  void build(vector<tipo> v, int n) { // build the tree
      // root en 1, ojas en el intervalo [tam, 2*tam-1]
      tam = sizeof(int) * 8 - __builtin_clz(n);
      tam = 1 << tam; //Primera potencia de 2 mayor a n
      t.resize(2 * tam, 0); forn(i, n) t[tam+i] = v[i];
      for(int i = tam - 1; i > 0; i--)
          t[i] = op(t[i << 1], t[i << 1 | 1]); //Poner la operacion del seg
  }

  void modify(int l, int r, tipo value) {
    for (l += tam, r += tam; l <= r; l >>= 1, r >>= 1) {
      if (l&1) t[l] = op(t[l], value); //Poner la operacion del seg
      if (!(r&1)) t[r] = op(t[r], value); //Poner la operacion del seg
      l++, r--;
    }
  }

  tipo query(int p) {
    tipo res = NEUT;
    for (p += tam; p > 0; p >>= 1) res = op(res, t[p]); //Operacion del seg
    return res;
  }
};
