ll be(ll b, ll e, ll m = MOD) {
    ll r=1; b%=m;
    while(e){if(e&1LL)r=r*b%m;b=b*b%m;e/=2;}
    return r;
}
ll inv_mod(ll x, ll m = MOD) {return be(x,m-2,m);}