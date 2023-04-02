// Angular sort
struct frac {
    ll num, den;
    frac() {}
    frac(ll x, ll y) {
        ll m = __gcd(abs(x),abs(y));
        num = x / m; den = y / m;
    }
    int cuad(ll n, ll d) {
        if(n >= 0 && d >= 0) return 1;
        if(n >= 0 && d < 0) return 2;
        if(n < 0 && d < 0) return 3;
        if(n < 0 && d >= 0) return 4;
    }
    bool operator <(frac &p) {
        if(cuad(num,den) != cuad(p.num,p.den)) {
            return cuad(num,den) < cuad(p.num,p.den); }
        return num * p.den < p.num * den;
    }
    bool operator ==(frac &p) {
        return (num * p.den == den * p.num) && (cuad(num,den) == cuad(p.num,p.den));
    }
};

struct punto {
    ll x, y;
    frac pend;
    ll val;
    punto() {}
    punto(ld a, ld b, ll z) {
        x = a, y = b, val = z, pend = frac(b,a);}
    bool operator <(punto p) {
        return pend < p.pend;
    }
};
