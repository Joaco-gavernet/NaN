/* Algoritmo de baby-step giant-step para 
 * hallar x tal que a^x = b (mod m) 
 * en O(sqrt(m))
 */
ll discrete_log(ll a, ll b, ll m) {
    a %= m, b %= m;
    ll n = sqrt(m) + 1;

    ll an = 1;
    for (ll i = 0; i < n; ++i)
        an = (an * 1ll * a) % m;

    unordered_map<ll, ll> vals;
    for (ll q = 0, cur = b; q <= n; ++q) {
        vals[cur] = q;
        cur = (cur * 1ll * a) % m;
    }

    for (ll p = 1, cur = 1; p <= n; ++p) {
        cur = (cur * 1ll * an) % m;
        if (vals.count(cur)) {
            ll ans = n * p - vals[cur];
            return ans;
        }
    }
    return -1;
}
