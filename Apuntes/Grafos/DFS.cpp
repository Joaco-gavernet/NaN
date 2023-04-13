#include <bits/stdc++.h>

using namespace std;

#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
#define all(c) (c).begin(),(c).end()

const int MAXN = 2e5+5;
vector <vector<int>> grafo(MAXN);
vector <bool> visto(MAXN,false); 
int answer = 0, answer2 = 0;

void DFS(int cur) { // Depth first search
	answer++;
	visto[cur] = true;
	for(int next : grafo[cur]) {
		if(!visto[next]) DFS(next); 
	}
}


vector<int> BFS(int start) { // Breadth first search
	fill(all(visto),false);
	queue <int> q; q.push(start);
	visto[start] = true;
	vector <int> dist(MAXN,-1);
	dist[start] = 0;
	while(q.size() > 0) {
		int cur = q.front(); q.pop();
		answer2++;
		for(int next : grafo[cur]) {
			if(!visto[next]) {
				q.push(next);
				visto[next] = true;
				dist[next] = dist[cur] + 1;
			}
		}
	}
	return dist;
}

int main() {
	FIN;
	
	
	int n; cin >> n; // cantidad de nodos
	int m; cin >> m; // cantidad de aristas
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y; x--; y--;
		grafo[x].push_back(y);
		grafo[y].push_back(x);
	}
	for(int i = 0; i < n; i++) {
		cerr << i << ") ";
		for(int j = 0; j < grafo[i].size(); j++) {
			cerr << grafo[i][j] << " ";
		}
		cerr << endl;
	}
	
	DFS(0);
	vector <int> dist = BFS(0);
	
	cout << answer << "\n";
	cout << answer2 << "\n";
	for(int i = 0; i < n; i++) {
		cerr << i+1 << ") " << dist[i] << endl; 
	}
	//~ pair<int,int> x; 
	// x.first; x.second;
	
	// ./DFS < t1
	
	//~ 0) 1 3 4
	//~ 1) 0 3 2
	//~ 2) 1 5 7
	//~ 3) 0 1
	//~ 4) 0 5 6
	//~ 5) 2 4
	//~ 6) 4
	//~ 7) 2
	//~ 8) 9
	//~ 9) 8
	
	return 0;
}
