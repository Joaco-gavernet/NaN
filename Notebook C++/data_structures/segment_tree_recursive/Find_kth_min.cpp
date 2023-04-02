struct Vertex {
    Vertex *l, *r;
    ll sum;

    Vertex(ll val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};

Vertex* build(vector <int> &a, ll tl, ll tr) {
    if (tl == tr) return new Vertex(a[tl]);
    ll tm = (tl + tr) / 2;
    return new Vertex(build(a, tl, tm), build(a, tm+1, tr));
}

ll get_sum(Vertex* v, ll tl, ll tr, ll l, ll r) {
    if (l > r) return 0;
    if (l == tl && tr == r) return v->sum;
    ll tm = (tl + tr) / 2;
    return get_sum(v->l, tl, tm, l, min(r, tm))
         + get_sum(v->r, tm+1, tr, max(l, tm+1), r);
}

Vertex* update(Vertex* v, ll tl, ll tr, ll pos, ll new_val) {
    if(tl == tr) return new Vertex(new_val);
    ll tm = (tl + tr) / 2;
    if(pos <= tm) return new Vertex(update(v->l, tl, tm, pos, new_val), v->r);
    else return new Vertex(v->l, update(v->r, tm+1, tr, pos, new_val));
}

void compresion(vector <int> ValoresQueAparecen, vector <int> &todos) {
	for(int x : ValoresQueAparecen) todos.pb(x);
	sort(todos.begin(),todos.end());
	todos.erase(unique(todos.begin(),todos.end()),todos.end());
}

// Retorna el valor de f(x)

int obtener(vector <int> &todos, int x) {
	return (int)(lower_bound(todos.begin(),todos.end(),x)-todos.begin());
}

struct kth_min {
  int n; 
  vector <int> v, todos, v_comp, real_num;
  vector <Vertex*> estado;
  void read(int z) {
    n = z;
    v.resize(n); v_comp.resize(n); real_num.resize(n);
    forn(i,n) cin >> v[i];
  }
  void prepare() {
    compresion(v,todos);
    forn(i,n) v_comp[i] = obtener(todos,v[i]);
    forn(i,n) real_num[v_comp[i]] = v[i];
    vector <int> cont(n,0);
    estado.pb(build(cont,0,n-1));
    for(int u : v_comp) {
      cont[u]++;
      estado.pb(update(estado.back(),0,n-1,u,cont[u]));
    }
  }
  int find_kth(int l, int r, int k) {
    //tl and tr --> 0 indexed, k --> 1 indexed
    Vertex* posl = estado[l]; 
    Vertex* posr = estado[r+1];
  
    int tl = 0, tr = n-1;
    while(tl!=tr) {
      int tm = (tr + tl)/2;
      if(posr->l->sum - posl->l->sum >= k) {
        posr = posr->l;
        posl = posl->l;
        tr = tm;
      }
      else {
        k -= posr->l->sum - posl->l->sum;
        posr = posr->r;
        posl = posl->r;
        tl = tm+1;
      }
    }
    return real_num[tl];
  } 
};
