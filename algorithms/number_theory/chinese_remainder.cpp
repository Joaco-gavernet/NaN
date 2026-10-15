// Teorema chino del resto
// Resuelve el sistema de ecuaciones modulares
// ai*xi = bi (mi)
ii extendedEuclid(ll a, ll b){ //a * x + b * y = gcd(a,b)
    ll x,y;
    if (b==0) return {1, 0};
    auto p = extendedEuclid(b, a%b);
    x = p.second, y = p.first-(a/b)*x;
    if(a*x+b*y == -__gcd(a,b)) x=-x, y=-y;
    return {x, y};
}
pair<ii, ii> dioph(ll a, ll b, ll r) {
    // a*x+b*y=r donde r es multiplo de gcd(a,b);
    ll d=__gcd(a,b);
    a/=d; b/=d; r/=d;
    auto p = extendedEuclid(a,b);
    p.first*=r; p.second*=r;
    assert(a*p.first+b*p.second==r);
    return {p, {-b,a}}; // solutions: p+t*ans.second
}
ll inv(ll a, ll mod) { // inverso de a modulo mod
    assert(__gcd(a,mod)==1);
    ii sol = extendedEuclid(a,mod);
    return ((sol.first%mod)+mod)%mod;
}

#define mod(a,m) (((a)%m+m)%m)
ii sol(tuple<ll,ll,ll> c){ //requires inv, diophantine
    auto [a, x1, m] = c; ll d = __gcd(a,m);
    if(d==1) return {mod(x1*inv(a,m),m), m};
    
    return x1%d ? mp(-1LL,-1LL) : sol({a/d, x1/d, m/d});
}

// cond[i] = {ai,bi,mi} ai*xi=bi (mi); assumes lcm fits in ll
// Mucho cuidado con el overflow, usar __int128 si lcm no entra en ll
pair<ll,ll> crt(vector<tuple<ll,ll,ll>> cond) { // returns: (sol, lcm)
    ll x1=0,m1=1,x2,m2;
    for(auto t:cond){
        tie(x2,m2) = sol(t);
        if((x1-x2)%__gcd(m1,m2)) return {-1,-1};
        if(m1==m2) continue;
        ll k=dioph(m2,-m1,x1-x2).first.second, l=m1*(m2/__gcd(m1,m2));
        x1 = mod((__int128)m1*k+x1,l); m1=l;
    }
    return sol({1,x1,m1});
} 