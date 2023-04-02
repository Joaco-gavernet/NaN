struct frac {
    ll n, d;
    frac(ll x, ll y) {
        ll g = __gcd(x,y);
        n = x/g; d = y/g;
        if(d < 0) n *= -1LL, d *= -1LL;
    }
    bool const operator <(const frac &a) const {
        return n * a.d < d * a.n; }
    bool const operator ==(const frac &a) const {
        return n * a.d == d * a.n; }
    frac const operator +(const frac &a) const {
        return frac(n*a.d + a.n*d, d*a.d); }
    frac const operator -(const frac &a) const {
        return frac(n*a.d - a.n*d, d*a.d); }
    frac const operator *(const frac &a) const {
        return frac(n * a.n, d * a.d); }
    frac const operator /(const frac &a) const {
        return frac(n * a.d, d * a.n); }
};
