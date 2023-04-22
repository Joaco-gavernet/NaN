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
	ll u, next, peso;
	arista(int _u, int _next, int _peso) {
		u = _u;
		next = _next;
		peso = _peso;
	}
	arista() {}
};

int main() {
	FIN;
	
	int n, m;
	cin >> n >> m;
	vector <ll> dist(n);
	dist[0] = 0;
	vector <arista> edges;
	forn(i,m) {
		int x, y; ll peso;
		cin >> x >> y >> peso;
		edges.pb(arista(x,y,peso));
		//~ edges.pb(arista(y,x,peso));
	}
	
	forn(i,n-1) {
		for(arista u : edges) {
			dist[u.next] = min(dist[u.next], dist[u.u] + u.peso);
		}
	}
	
	
	return 0;
}
