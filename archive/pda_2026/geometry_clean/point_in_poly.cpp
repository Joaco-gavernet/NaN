bool point_in_poly(vector <punto> &v, punto p) { // O(n) for non-convex
    unsigned i, j, mi, mj, c = 0;
    for(i = 0, j = v.size()-1; i < v.size(); j = i++) {
        if((v[i].y <= p.y && p.y < v[j].y) || (v[j].y <= p.y && p.y < v[i].y)) {
            mi = i; mj = j; if(v[mi].y > v[mj].y) swap(mi,mj);
            if(((p-v[mi]) ^ (v[mj]-v[mi])) < 0 ) c ^= 1;
        }
    }
    return c;
}
bool point_in_poly_convex(vector <punto> &v, punto p) { // O(log n)
    bool ans = true;
    if( ((v[1]-v[0]) ^ (v[2]-v[1])) >= 0) reverse(all(v));
    int a = 1, b = v.size()-1;
    while(b-a > 1) {
        int med = (a+b)/2;
        if( ((v[med]-v[0]) ^ (p-v[med])) <= 0 ) a = med;
        else b = med;
    }
    if( ((v[a]-v[0]) ^ (p - v[a])) > 0) ans = false;
    if( ((v[b]-v[a]) ^ (p - v[b])) > 0) ans = false;
    if( ((v[0]-v[b]) ^ (p - v[0])) > 0) ans = false;
    return ans;
}
