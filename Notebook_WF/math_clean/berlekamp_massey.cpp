// Berlekamp-Massey algorithm
// Description: Finds the shortest linear recurrence relation that generates a given sequence. 
// Time: O(N^2)
// Output: A vector of integers, where the first element is the constant term and the last element is the coefficient of x^(n-1).
vi BM(vi x){
    vi ls,cur; ll lf,ld;
    forn(i,SZ(x)){
        ll t=0;
        forn(j,SZ(cur)) t=(t+x[i-j-1]*(ll)cur[j])%MOD;
        if((t-x[i])%MOD==0) continue;
        if(!SZ(cur)){
            cur.resize(i+1); lf=i; ld=(t-x[i])%MOD;
            continue;
        }
        ll k=-(x[i]-t)*be(ld,MOD-2,MOD)%MOD;
        vi c(i-lf-1); c.pb(k);
        forr(j,0,SZ(ls))c.pb(-ls[j]*k%MOD);
        if(SZ(c)<SZ(cur))c.resize(SZ(cur));
        forr(j,0,SZ(cur))c[j]=(c[j]+cur[j])%MOD;
        if(i-lf+SZ(ls)>=SZ(cur)) ls=cur,lf=i,ld=(t-x[i])%MOD;
        cur=c;
    }
    forn(i,SZ(cur)) cur[i]=(cur[i]%MOD+MOD)%MOD;
    return cur;
}