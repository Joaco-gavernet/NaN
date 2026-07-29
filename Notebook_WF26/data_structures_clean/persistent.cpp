struct Vertex {
    Vertex *l, *r;
    ll sum;
    Vertex(ll val) : l(nullptr), r(nullptr), sum(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};
Vertex* build(ll a[], ll tl, ll tr) {
    if (tl == tr)
        return new Vertex(a[tl]);
    ll tm = (tl + tr) / 2;
    return new Vertex(build(a, tl, tm), build(a, tm+1, tr));
}
ll get_sum(Vertex* v, ll tl, ll tr, ll l, ll r) {
    if (l > r)
        return 0;
    if (l == tl && tr == r)
        return v->sum;
    ll tm = (tl + tr) / 2;
    return get_sum(v->l, tl, tm, l, min(r, tm))
         + get_sum(v->r, tm+1, tr, max(l, tm+1), r);
}
Vertex* update(Vertex* v, ll tl, ll tr, ll pos, ll new_val) {
    if (tl == tr)
        return new Vertex(new_val);
    ll tm = (tl + tr) / 2;
    if (pos <= tm)
        return new Vertex(update(v->l, tl, tm, pos, new_val), v->r);
    else
        return new Vertex(v->l, update(v->r, tm+1, tr, pos, new_val));
}
vector <Vertex*> estado; 
