#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
#define forr(i,a,b) for(int i = int(a); i < int(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
const int MAXN = 2e5+5;
const ll INF = 1LL<<60;
 
void floyd(vector<vector<ll>> &dp, ll n) {
    forn(k,n) forn(i,n) forn(j,n) {
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    }
}

int main() {
	FIN;
	
	int n, m, q;
	cin >> n >> m >> q;
	vector <vector<ll>> dist(n,vector<ll>(n,INF));
	forn(i,n) dist[i][i] = 0;
	forn(i,m) {
		ll x, y, z;
		cin >> x >> y >> z;
		x--; y--;
		dist[x][y] = min(dist[x][y],z);
		dist[y][x] = min(dist[y][x],z);
	}
	
	floyd(dist,n);
	
	forn(_,q) {
		int x, y;
		cin >> x >> y; x--; y--;
		if(dist[x][y] != INF) cout << dist[x][y] << "\n";
		else cout << "-1\n";
	}
	
	return 0;
}
