typedef long double tipo;

struct punto { 
    tipo x, y; int ind; 
    punto operator -(punto p) const {return {x-p.x,y-p.y};}
    bool operator <(punto p) const {return x != p.x ? x < p.x : y < p.y;}
    tipo mod() {return sqrtl(x*x + y*y);}
    tipo mod2() {return x*x + y*y;}
}; 

tuple<tipo,int,int> closest(vector<punto> &p) { //closest and indices
    int n = p.size();
    set<punto> s;
    tipo best = (tipo)(1e18); int ansi, ansj;
    int j = 0;
    forn(i,n) {
        tipo d = ceil(sqrt(best));
        while(p[i].x - p[j].x >= best) s.erase({p[j].y, p[j].x, j}), j++;
        auto it1 = s.lower_bound({p[i].y - d, p[i].x});
        auto it2 = s.upper_bound({p[i].y + d, p[i].x});
        for(auto it = it1; it != it2; ++it) {
            tipo dx = p[i].x - it->y;
            tipo dy = p[i].y - it->x;
            if(dx * dx + dy * dy < best) {
                best = dx * dx + dy * dy;
                ansi = i, ansj = it->ind;
            }
        }
        s.insert({p[i].y, p[i].x, (int)i});
    }
    return {sqrtl(best),ansi,ansj};
}
