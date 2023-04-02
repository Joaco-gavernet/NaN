struct recta { // Puede usarse para segmentos ([p,p+v] o alpha = [0,1])
    punto v, p; // v -> director, p -> punto por donde pasa
    recta(punto p1, punto p2) { v = (p2-p1); p = p1;}
    recta() {}
    recta(tipo A, tipo B, tipo C) { // Transform Ax + By + C = 0 
        v = {-B,A}; A != 0 ? p = {-C / A,0} : p = {0,-C / B}; 
    }
    bool is_in(punto q){return fabs((q.x-p.x)*v.y - (q.y-p.y)*v.x) < EPS;}
    punto eval(double x) {return x * v + p;}
};

bool inter_recta(recta &r1, recta &r2, punto &ans) {
    // Retorna false si son paralelas, sino guarda el punto en ans
    if(abs(r1.v ^ r2.v) < EPS) return false;
    tipo alpha = tipo((r2.p - r1.p)^r2.v) / tipo(r1.v^r2.v);
    ans = r1.p + alpha * r1.v;
    return true;
}

bool inter_seg(recta &r1, recta &r2, punto &ans) {
    if(r1.p == r2.p || r1.p == r2.p+r2.v) {ans = r1.p; return true;}
    if(r1.p+r1.v == r2.p || r1.p+r1.v == r2.p+r2.v) { 
        ans = r1.p+r1.v; return true; } //Casos que coincidan extremos
    if(abs(r1.v ^ r2.v) < EPS) return false; // son paralelos
    tipo alpha = tipo((r2.p - r1.p)^r2.v) / tipo(r1.v^r2.v);
    tipo beta = tipo((r1.p - r2.p)^r1.v) / tipo(r2.v^r1.v);
    if(alpha < -EPS || beta < -EPS) return false;
    if(alpha > 1.0+EPS || beta > 1.0+EPS) return false;
    ans = r1.p + alpha * r1.v; return true;
} 

struct circ { punto c; tipo r; };

tipo dist_point_line(punto &p, recta &r) {
    punto p1 = r.p, p2 = r.p + r.v; 
    return fabs((p1-p)^(p2-p))/r.v.mod();
}

punto project(punto a, punto b) { //Proyeccion de b sobre a
    return ((a*b)/a.mod2()) * a;
}

vector <punto> inter_circ_line(recta r, circ c) {
    vector <punto> ans; tipo dist = dist_point_line(c.c,r);
    if(dist > c.r+EPS) return ans;
    (c.c-r.p) * r.v != 0 ? r.p = r.p : r.p = r.p + r.v;
    punto aux = c.c - r.p, dir = project(r.v,aux);
    if(fabs(dist-c.r) <= EPS) {ans.pb(r.p + dir); return ans;}
    tipo factor = sqrt(c.r*c.r - dist*dist)/dir.mod();
    ans.pb(r.p + dir + factor * dir); ans.pb(r.p + dir - factor * dir);
    return ans;
}

tipo intersection_area(circ a, circ b) {
    punto aux = (b.c - a.c); tipo dist=aux.mod(), dist2=aux.mod2();
    if(a.r + b.r - dist < -EPS) return 0;
    if(fabs(a.r - b.r) - dist > -EPS) {
        return min(a.r, b.r) * min(a.r, b.r) * 2*acosl(0); }
    tipo alpha = acosl((dist2 + a.r*a.r - b.r*b.r) / (2 * dist * a.r));
    tipo beta = acosl((dist2 + b.r*b.r - a.r*a.r) / (2 * dist * b.r));
    tipo ans1 = (alpha - sinl(alpha+alpha)*0.5) * a.r * a.r;
    tipo ans2 = (beta - sinl(beta+beta)*0.5) * b.r * b.r;
    return ans1 + ans2;
}

vector <punto> inter_circ_circ(circ a, circ b) {
    vector <punto> ans;
    if(a.c==b.c) {
        return abs(a.r-b.r) <= EPS ? vector<punto>{a.c,a.c,a.c} : ans; }
    b.c = b.c - a.c; punto aux = a.c; a.c = a.c - a.c;
    recta r(-2*b.c.x , -2*b.c.y , a.r*a.r - b.r*b.r + b.c.x*b.c.x + b.c.y*b.c.y);
    ans = inter_circ_line(r,a); 
    forn(i,ans.size()) ans[i] = ans[i] + aux; return ans;
}
