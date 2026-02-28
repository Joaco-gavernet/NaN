struct Hash {
    const ll P=1777771;
    const ll MOD[2] = {999727999, 1070777777};
    const ll PI[2] = {325255434, 10018302};
    vector<ll> h[2],pi[2];
    Hash(string& s){
        forn(k,2)h[k].resize(s.size()+1),pi[k].resize(s.size()+1);
        forn(k,2){
            h[k][0]=0;pi[k][0]=1;
            ll p=1;
            forr(i,1,s.size()+1){
                h[k][i]=(h[k][i-1]+p*s[i-1])%MOD[k];
                pi[k][i]=(1LL*pi[k][i-1]*PI[k])%MOD[k];
                p=(p*P)%MOD[k];
            }
        }
    }
    ll get(ll s, ll e){ // [s, e] (s y e van de 0 a n-1)
        e++;
        ll h0=(h[0][e]-h[0][s]+MOD[0]);
        h0=(1LL*h0*pi[0][s])%MOD[0];
        ll h1=(h[1][e]-h[1][s]+MOD[1]);
        h1=(1LL*h1*pi[1][s])%MOD[1];
        return (h0<<32)|h1;
    }
};
