vector<ll> fact, ifact;
void init_fact(int maxn){
    fact.resize(maxn), ifact.resize(maxn);
    fact[0] = 1; forr(i, 1, maxn) fact[i] = (fact[i-1]*i)%MOD;
    ifact[maxn-1] = inv_mod(fact[maxn-1], MOD);
    for(int i = maxn-2; i >= 0; i--) ifact[i] = (ifact[i+1]*(i+1))%MOD;
}
ll binom(ll n, ll k){
    if(n < 0 or k < 0 or n < k) return 0;
    ll ans = fact[n];
    ans *= ifact[k]; ans %= MOD;
    ans *= ifact[n-k]; ans %= MOD;
    return ans;
}
