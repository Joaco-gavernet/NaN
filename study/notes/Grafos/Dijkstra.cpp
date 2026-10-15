#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
#define forr(i,a,b) for(int i = int(a); i < int(b); i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
const int MAXN = 2e5+5;
const ll INF = 1LL<<60;
 
struct arista {
	ll next, w;
};
 
struct nodo {
	ll id, dist;
	bool operator <(nodo p) const {
		return dist > p.dist;
	}
};
 
vector <vector<arista>> g(MAXN);
 
vector <ll> Dijkstra(int start, int n) {
	vector <ll> dist(n,INF);
	priority_queue <nodo> pq;
	pq.push({start,0});
	while(pq.size() > 0) {
		auto[cur,d] = pq.top(); pq.pop();
		if(dist[cur] != INF) continue;
		dist[cur] = d;
		for(arista u : g[cur]) {
			if(dist[u.next] == INF) {
				pq.push({u.next,d+u.w});
			}
		}
	}
	return dist;
}
 
int main() {
	FIN;
	
	int n, m; cin >> n >> m;
	forn(i,m) {
		ll x, y, z;
		cin >> x >> y >> z;
		x--; y--;
		g[x].pb({y,z});
	}
	
	vector <ll> dist = Dijkstra(0,n);
	forn(i,n) cout << dist[i] << " \n"[i == n-1];
	
	return 0;
}
