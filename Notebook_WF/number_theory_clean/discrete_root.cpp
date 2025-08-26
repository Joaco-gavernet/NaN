// Finds the primitive root modulo p
ll generator(ll p) {
    vi fact;
    ll phi = p-1, n = phi;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            fact.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        fact.push_back(n);
    forr(res, 2, p+1){
        bool ok = true;
        for (ll factor : fact) {
            if (be(res, phi / factor, p) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return res;
    }
    return -1;
}
// This program finds all numbers x such that x^k = a (mod n)
vi discrete_root(ll n, ll k, ll a){
    if (a == 0) return {0};
    ll g = generator(n);
    // Baby-step giant-step discrete logarithm algorithm
    ll sq = (ll) sqrt (n + .0) + 1;
    vector<pair<ll, ll>> dec(sq);
    forr(i, 1, sq+1)
        dec[i-1] = {be(g, i * sq * k % (n - 1), n), i};
    sort(all(dec));
    ll any_ans = -1;
    forn(i, sq){
        ll my = be(g, i * k % (n - 1), n) * a % n;
        auto it = lower_bound(all(dec), mp(my, 0));
        if (it != dec.end() && it->first == my) {
            any_ans = it->second * sq - i;
            break;
        }
    }
    if (any_ans == -1) return {};
    // Print all possible answers
    ll delta = (n-1) / __gcd(k, n-1);
    vi ans;
    for (ll cur = any_ans % delta; cur < n-1; cur += delta)
        ans.push_back(be(g, cur, n));
    sort(ans.begin(), ans.end());
    return ans;
}
