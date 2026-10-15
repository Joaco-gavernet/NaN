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
    int ans = 0;
    forn(i,n) {
        while(sum >= v[i]) {
            sum -= v[i];
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}