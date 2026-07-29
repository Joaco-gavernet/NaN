punto getCircleCenter(punto a, punto b) {
    ld x = a.mod2(), y = b.mod2(), z = a^b;
    return {(b.y * x - a.y * y) / (2 * z),(a.x * y - b.x * x) / (2 * z) };
}
circ circleFrom(const punto &a, const punto &b, const punto &c) {
    punto o = getCircleCenter(b-a,c-a);
    return {o+a, o.mod()};
}
circ spanning_circle(vector<punto> &T) {
    int n = T.size();
    shuffle(all(T),rng);
    circ C={{0,0}, -1};
    forn(i,n) if (dist(C.c,T[i])>C.r+EPS) {
        C = {T[i], 0};
        forn(j,i) if (dist(C.c,T[j])>C.r+EPS) {
            C = {0.5*(T[i] + T[j]), dist(T[i],T[j])/2};
           forn(k,j) if (dist(C.c,T[k])>C.r+EPS) {
                C = circleFrom(T[i], T[j], T[k]);
            }
        }
    }
    return C;
}