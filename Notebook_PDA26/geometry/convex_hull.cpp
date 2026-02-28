const ld EPS = 1e-10;
void convex_hull(vector<punto> &a) {
    if(SZ(a) == 1) return;
    sort(all(a));
    punto p1 = a[0];
    vector<punto> up, down;
    up.pb(p1); down.pb(p1);
    forr(i,1,SZ(a)) {
        int n = SZ(up), m = SZ(down);
        while(n > 1 && ((up[n-1]-up[n-2])^(a[i]-up[n-1])) >= -EPS) {
            up.pop_back(); n--; 
        } up.pb(a[i]);
        while(m > 1 && ((down[m-1]-down[m-2])^(a[i]-down[m-1])) <= EPS) {
            down.pop_back(); m--;
        } down.pb(a[i]);
    } // Cambiar EPS a 0 para mejor precision en enteros. 
    a.clear();
    for(punto u : up) a.pb(u);
    for(int i = SZ(down)-2; i > 0; i--) a.pb(down[i]);
}

