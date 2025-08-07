const ll LOG = 60;
// Linear Recurrence
// Description: Calculates the kth term of a linear recurrence relation
// init O(n^2log) query(n^2 logk)
// input: terms: first n term; trans: transition function (calcular con BM); MOD; LOG=mxlog of k
// output calc(k): kth term mod MOD
// example: {1,1} {2,1} an=2*a_(n-1)+a_(n-2); calc(3)=3 calc(10007)=71480733
struct LinearRec {
    ll n; vi terms, trans; vector<vi> bin;
    vi add(vi &a, vi &b){
        vi res(n*2+1);
        forn(i, n+1) forn(j, n+1) res[i+j]=(res[i+j]*1LL+(ll)a[i]*b[j])%MOD;
        for(ll i=2*n; i>n; --i){
            forn(j, n) res[i-1-j]=(res[i-1-j]*1LL+(ll)res[i]*trans[j])%MOD;
            res[i]=0;
        }
        res.erase(res.begin()+n+1,res.end());
        return res;
    }
    LinearRec(vi &terms, vi &trans):terms(terms),trans(trans){
        n=SZ(trans);vi a(n+1);a[1]=1;
        bin.pb(a);
        forr(i,1,LOG)bin.pb(add(bin[i-1],bin[i-1])); // Precompute powers of a
    }
    ll calc(ll k){
        vi a(n+1);a[0]=1;
        forn(i,LOG) if((k>>i)&1)a=add(a,bin[i]);
        ll ret=0;
        forn(i,n) ret=(ret+a[i+1]*terms[i])%MOD;
        return ret;
    }
};