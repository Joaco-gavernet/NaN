//~ Solucion DP

vector<vector<ll>> binomial(int n) { // O (N^2)
    vector<vector<ll>> binom(n+1,vector<ll>(n+1));
    binom[0][0] = binom[1][0] = binom[1][1] = 1;
    forr(i,2,n+1){ forn(j,i+1) {
            if(j==0 || j==i) binom[i][j]=1;
            else binom[i][j] = binom[i-1][j-1] + binom[i-1][j];
        }
    }
    return binom;
}

//~ ==================================================================

//~ Solucion O(N + Log N)

vector<ll> fact, ifact;

ll be(ll b, ll e, ll m) {
    ll r=1; b%=m;
    while(e){if(e&1LL)r=r*b%m;b=b*b%m;e/=2;}
    return r;
}
ll inv_mod(ll x, ll m){ return be(x,m-2,m); }

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
