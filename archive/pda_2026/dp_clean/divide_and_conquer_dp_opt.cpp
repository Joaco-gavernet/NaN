ll costo[MAXN][MAXN];
vector <ll> last(MAXN), dp(MAXN);
void calc_costo(int n, vector <ll> &v) {}
void compute(int l, int r, int optl, int optr) {
    if(l > r) return;
    int med = (l+r)/2;
    pair<ll,ll> best = {INF,-1};
    for(int p = optl; p <= min(med,optr); p++) {
        best = min(best,{last[p] + costo[p+1][med],p});
    }
    dp[med] = best.first;
    int opt = best.second;
    compute(l,med-1,optl,opt);
    compute(med+1,r,opt,optr);
}
ll solve_dac(int n, int k) { 
    for(int i = 0; i < n; i++) last[i] = costo[0][i];
    for(int i = 2; i <= k; i++) {
        fill(all(dp),INF);
        compute(0,n-1,0,n-1);
        last = dp;
    }
    return dp[n-1];
}
