// Shoelace formula
tipo area(vector <punto> &v) {
    tipo ans = 0.0; int n = v.size();
    forn(i,n) ans += v[i] ^ v[(i+1)%n];
    return fabs(ans/2.0);
}

tipo find_alpha(recta r, punto p) {
    return r.v.x != 0 ? (p.x-r.p.x)/r.v.x : (p.y-r.p.y)/r.v.y;
}
