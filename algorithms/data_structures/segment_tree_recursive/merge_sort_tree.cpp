//~ Puede resolver Kth Min en O(Q * log^3 N)
//~ La funcion query(l,r,k) retorna la cantidad de numeros en el 
//~ intervalo que son menores o iguales a k en [L,R] en O(log^2 N)

typedef long long tipo;
 
struct segtree {
  struct node {
    tipo ans = 0, l, r, inv = 0; // Poner el neutro del update
    vector <tipo> cur, left, right;
    tipo nomatch = 0; // No match en el intervalo de query
    node base(node aux) { aux.ans = aux.inv = 0, aux.cur.clear(); return aux;} //Poner el neutro de la query
    void set_node(tipo x, tipo pos) {ans = 0, cur.pb(x); l = r = pos;}
    void combine(node a, node b) {
      left = a.cur, right = b.cur;
      int p1 = 0, p2 = 0; inv = ans = 0;
      while(p1 < a.cur.size() && p2 < b.cur.size()) {
        if(a.cur[p1] <= b.cur[p2]) cur.pb(a.cur[p1++]);
        else cur.pb(b.cur[p2++]), inv += a.cur.size() - p1;
      }
      while(p1 < a.cur.size()) cur.pb(a.cur[p1++]);
      while(p2 < b.cur.size()) cur.pb(b.cur[p2++]);
      inv += a.inv + b.inv;
      l = min(a.l,b.l); r = max(a.r,b.r);
    }
  };
  vector <node> t; 
  
  int BS(int k, vector <tipo> &aux) {
    int a = -1, b = aux.size();
    while(b-a > 1) {
      int med = (a+b)/2;
      if(aux[med] > k) b = med;
      else a = med;
    }
    return b; //return aux.size()-b for K-Query
  }
    
  ll ask(int p, tipo l, tipo r, tipo k) {
    if(l > t[p].r || r < t[p].l) return 0LL;
    if(l <= t[p].l && t[p].r <= r) {
      return BS(k,t[p].cur); 
    }
    return ask(2*p+1,l,r,k)+ask(2*p+2,l,r,k);
  }
  
  void update(int p, tipo pos, tipo val) {
    if(t[p].r < pos || t[p].l > pos) return;
    if(t[p].l == t[p].r) { t[p].set_node(val,pos); return; }
    update(2*p+1, pos, val); update(2*p+2, pos, val);
    t[p].combine(t[2*p+1], t[2*p+2]);
  }
  
  void build(tipo a, tipo b, int p, vector <tipo> &v) {
    if(a==b) {t[p].set_node(v[a],a); return;}
    tipo med=(a+b)/2;
    build(a, med, 2*p+1, v); build(med+1, b, 2*p+2, v);
    t[p].combine(t[2*p+1], t[2*p+2]);
  }
  ll query(tipo l, tipo r, tipo k) {return ask(0,l,r,k);}
  void modificar(tipo pos, tipo val) {update(0,pos,val);}  
  void construir(vector <tipo> &v, int n) { t.resize(4*n); build(0,n-1,0,v); }
  
  tipo find_kth(int l, int r, tipo k) {
    tipo minA = (tipo)(-1e9-7), maxA = (tipo)(1e9+7);
    while(maxA - minA > 1) {
      tipo med = (maxA + minA)/2;
      int ans = query(l,r,med);
      if(ans >= k) maxA = med;
      else minA = med;
    }
    return maxA; 
  } 
};
