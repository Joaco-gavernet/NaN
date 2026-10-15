#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long;
using vi = vector<ll>;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#include "../algorithms/number_theory/miller_rabin_pollard_rho.cpp"

int main() {
    Factorization f;
    rng.seed(9);
    vector<bool> prime(100001, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= 100000; ++i)
        if (prime[i])
            for (int j = i * i; j <= 100000; j += i) prime[j] = false;
    for (int i = 0; i <= 100000; ++i) assert(f.miller(i) == prime[i]);
    assert(!f.miller(-1));
    for (ll n : {3474749660383LL, 341550071728321LL, 3825123056546413051LL, LLONG_MAX})
        assert(!f.miller(n));
    assert(f.miller(2305843009213693951LL));
    assert(f.factorize(3474749660383LL) == vi({1303, 16927, 157543}));
    assert(f.factorize(1000000016000000063LL) == vi({1000000007, 1000000009}));
    assert(f.factorize(1).empty());
    assert(f.factorize(1LL << 60) == vi(60, 2));
}
