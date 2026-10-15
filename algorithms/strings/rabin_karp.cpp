/*
   Dadas dos strings s y t, podemos hallar cuantas veces aparece el string s en el string t
   en O(|s|+|t|), mediante el uso de hashing.
   */

vector <ll> rabin_karp(string s, string t) {
    ll p=31, m=1e9+7, n=2147483647;
    ll S=s.size(), T=t.size();
    vector <ll> p_pow;
    p_pow.pb(1);
    forn(i,max(S,T)) p_pow.pb((p_pow.back()*p)%m);
    vector <ll> h; h.pb(0);
    forn(i,T) h.pb((h.back()+(t[i]-'a'+1)*p_pow[i])%m);
    ll h_s=0;
    forn(i,S) h_s=(h_s+(s[i]-'a'+1)*p_pow[i])%m;
    vector <ll> o;
    forn(i,T-S+1) {
        ll cur_h=(h[i+S]+m-h[i])%m;
        if(cur_h==(h_s*p_pow[i])%m) o.pb(i);
    }
    return 0;
}
