// Count the number of cycles in a graph
// Time: O(n*2^n)
// Usage: count_cycles(n); // n --> number of nodes
const int MAXN = 20;
int g[MAXN][MAXN];

bool bit(int mask, int i) {
    if((mask & 1<<i) != 0) return true;
    return false;
}

int first(int mask, int n) {
    for(int i = 0; i < n; i++) {
        if(bit(mask,i)) {return i;}
    }
    return -1;
}

int count(int mask, int n) {
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(bit(mask,i)) ans++;
    }
    return ans;
}

ll count_cycles(int n) {
    ll dp[1<<MAXN][MAXN];
    memset(dp,0,sizeof(dp));
    ll ans = 0;
    for(int mask = 1; mask < (1<<n); mask++) {
        if(count(mask,n) == 1) {
            dp[mask][first(mask,n)] = 1;
            continue;
        }
        int f = first(mask,n);
        for(int last = 0; last < n; last++) {
            if(!bit(mask,last) || last == f) continue;
            for(int next = 0; next < n; next++) {
                if(g[last][next]) {
                    dp[mask][last] += dp[mask ^ (1<<last)][next];
                }
            }
            if(count(mask,n) >= 3 && g[first(mask,n)][last]) ans += dp[mask][last];
        }
    }
    return ans / 2;
}
