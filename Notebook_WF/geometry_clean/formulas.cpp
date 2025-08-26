// Shoelace formula
tipo area(vector <punto> &v) {
    tipo ans = 0.0; int n = v.size();
    forn(i,n) ans += v[i] ^ v[(i+1)%n];
    return fabs(ans/2.0);
}
tipo dist_point_line(punto &p, recta &r) {
    punto p1 = r.p, p2 = r.p + r.v; 
    return fabs((p1-p)^(p2-p))/r.v.mod();
}
punto project(punto a, punto b) { //Proyeccion de b sobre a
    return ((a*b)/a.mod2()) * a;
}
tipo find_alpha(recta r, punto p) {
    return r.v.x != 0 ? (p.x-r.p.x)/r.v.x : (p.y-r.p.y)/r.v.y;
}
