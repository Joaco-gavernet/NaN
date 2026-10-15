ll mod(ll x) {x%=MOD; if(x<0) x+=MOD; return x;}
ll add(ll a, ll b){return mod(a+b);}
ll sub(ll a, ll b){return mod(a-b);}
ll mul(ll a, ll b){return mod(mod(a)*mod(b));}
ll be(ll a, ll p) {
	ll ans=1; for(; p; p/=2, a = mul(a,a)) if(p&1) ans=mul(ans,a);
	return ans;
}
ll divi(ll a, ll b){return mul(a,be(b,MOD-2));}
