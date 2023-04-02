// Description: Fenwick Tree (BIT) for range queries and point updates
// Time: O(log n) for both queries and updates
// Usage: BIT bit(v); bit.query(l,r); bit.update(pos,val);
struct BIT {
    vector <ll> prefix, a;
    BIT(vector <ll> &v) {
        int n = v.size(); prefix.resize(n+1); a = v;
        vector <ll> aux(n+1,0);
        forn(i,n) aux[i+1] = aux[i] + v[i];
        forr(i,1,n+1) prefix[i] = aux[i] - aux[i - (i&(-i))];
    }
    ll query(int l, int r) { //[a,b] 0-indexed
        ll ans = 0; r++;
        while(r) ans += prefix[r], r -= r&(-r);
        while(l) ans -= prefix[l], l -= l&(-l);
        return ans;
    }
    void update(int pos, ll val) {
        int i = pos + 1; ll upd = val - a[pos];
        while(i < prefix.size()) prefix[i] += upd, i += i&(-i);
        a[pos] = val;
    }
};
