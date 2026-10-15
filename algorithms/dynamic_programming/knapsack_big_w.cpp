// Description: Given a set of items, each with a weight and a value, determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible.
// Time: O(n * MAXV)
// Usage: knapsack(v,n,w); // v --> vector of items, n --> number of items, w --> maximum weight

struct item { int w, v; };

ll knapsack(vector <item> &v, int n, int w) {
    int MAXV = 100005;
    vector <ll> dp(MAXV+1,INF), aux(MAXV+1,INF);
    vector <bool> visto(MAXV,false);
    visto[0]=true; dp[0]=0;
    forn(i,n) {
        forn(j,MAXV) {
            aux[j]=dp[j];
            if(j-v[i].v < 0) continue;
            if(visto[j-v[i].v] == true) {
                aux[j]=min(aux[j],dp[j-v[i].v]+v[i].w);
                visto[j]=true;
            }
        }
        forn(j,MAXV) dp[j]=aux[j];
    }
    ll ans = 0;
    forn(i,MAXV+1) if(dp[i] <= w && visto[i]==true) ans=i;
    return ans;
}
