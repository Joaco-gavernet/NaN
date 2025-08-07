typedef long double ld;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myrand(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(rng); }

struct Factorization {
    inline ll mul(ll a, ll b, ll c){
        ll s = a * b - c * ll((ld) a / c * b + 0.5);
        return s < 0 ? s + c : s;
    }

    ll be(ll a, ll k, ll mod) {
        ll res = 1;
        for(; k; k >>= 1, a = mul(a, a, mod)) if (k & 1) res = mul(res, a, mod);
        return res;
    }

    bool miller(ll n) { // chequea si un numero es primo
        auto test = [&](ll n, ll a) {
            if (n == a) return true;
            if (n % 2 == 0) return false;

            ll d = (n - 1) >> __builtin_ctzll(n - 1);
            ll r = be(a, d, n);
            while (d < n - 1 && r != 1 && r != n - 1) {
                d <<= 1;
                r = mul(r, r, n);
            }
            return r == n - 1 || d & 1;
        };

        if(n == 2) return 1;
        for(auto p: vi{2, 3, 5, 7, 11, 13}) if(!test(n, p)) return 0;
        return 1;
    }

    ll pollard(ll n) { // devuelve un factor no trivial de n
        auto f = [&](ll x) { return ll((__int128(x) * x + 1) % n); };

        ll x = 0, y = 0, t = 30, prd = 2;
        while (t++ % 40 || __gcd(prd, n) == 1) { // speedup: no tomar gcd en cada iteracion
            if (x == y) x = myrand(2, n - 1), y = f(x);
            ll tmp = mul(prd, abs(x - y), n);
            if (tmp) prd = tmp;
            x = f(x), y = f(f(y));
        }
        return __gcd(prd, n);
    }

    vi factorize(ll n) {
        vi res;
        auto dfs = [&](auto &dfs, ll x) {
            if (x == 1) return;
            if (miller(x)) res.pb(x);
            else {
                ll d = pollard(x);
                dfs(dfs, d); dfs(dfs, x / d);
            }
        };
        dfs(dfs, n); sort(all(res));
        return res;
    }
};
