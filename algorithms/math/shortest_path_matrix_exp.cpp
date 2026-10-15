#define INF 2e18

typedef vector<vector<ll> > Matrix;

ll funcion(ll x, ll y){
    if(x!=INF && y!=INF) return (x+y);
    else return INF;
}

Matrix operator*(Matrix &a, Matrix &b) {
    int n=a.size(),m=b[0].size(),z=a[0].size();
    Matrix r(n,vector<ll>(m,INF));
    forn(i,n) forn(j,m) forn(k,z)
        r[i][j]=min(r[i][j],funcion(a[i][k],b[k][j]));
    return r;
}

Matrix be(Matrix b, ll e) {
    Matrix r(b.size(),vector<ll>(b[0].size())); e--;
    forn(i,b.size()){ forn(j,b[0].size()) r[i][j]=b[i][j]; }
    while(e){if(e&1LL)r=r*b;b=b*b;e/=2;}
    return r;
}
