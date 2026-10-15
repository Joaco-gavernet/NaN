#include <bits/stdc++.h>

using namespace std;

#define forn(i,n) for(int i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()

// Gready Solution for Coin Sum

int main() {
    
    int n, sum; cin >> n >> sum;
    vector <int> v(n);
    forn(i,n) cin >> v[i];
    sort(all(v));
    reverse(all(v));
    vector <int> dp(sum+1, 1e9);
    dp[0] = 0;
    forn(i,n) {
        for(int j = v[i]; j <= sum; j++) {
            dp[j] = min(dp[j], dp[j-v[i]] + 1);
        }
    }

    cout << dp[sum] << "\n";

    return 0;
}