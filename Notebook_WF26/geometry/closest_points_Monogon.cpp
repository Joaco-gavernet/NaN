const ll INF = (ll)(1e15+10); // (1e18+10) 

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

struct punto {
    ll x, y;
    punto (ll x = 0, ll y = 0) : x(x), y(y) {}
    punto operator -(const punto &p) const {
        return punto(x - p.x, y - p.y); }
    ll len2() const { return x * x + y * y; }
    bool const operator <(const punto &p) const {
        return (x != p.x) ? x < p.x : y < p.y;
    }
};

istream& operator>>(istream &is, punto &p) {
    return is >> p.x >> p.y;
}

ll closest(vector<punto> &p, int l, int r) { //Init l = 0 and r = p.size()-1
    if(l == r) return INF;
    int m = (l + r) / 2;
    ll mid = p[m].x;
    ll d = min(closest(p, l, m), closest(p, m + 1, r));
    vector<punto> A, B, C;
    forr(i, l, m + 1) {
        ll r = mid - p[i].x;
        if(r * r <= d) A.push_back(p[i]);
    }
    forr(i, m + 1, r + 1) {
        ll r = mid - p[i].x;
        if(r * r <= d) B.push_back(p[i]);
    }
    auto cmpy = [&](punto a, punto b) { return a.y < b.y; };
    merge(all(A), all(B), back_inserter(C), cmpy);
    forr(i, 0, C.size()) {
        int j = i + 1;
        while(j < C.size() && (C[i] - C[j]).y * (C[i] - C[j]).y <= d) {
            d = min(d, (C[i] - C[j]).len2());
            j++;
        }
    }
    inplace_merge(p.begin() + l, p.begin() + m + 1, p.begin() + r + 1, cmpy);
    return d;
}

void sorting(vector <punto> &p) { sort(all(p)); } // Don't Forget 
