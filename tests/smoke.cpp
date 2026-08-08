#include <cassert>
#include <queue>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using tipo = long long;
using vi = vector<int>;

#define forn(index, count) \
    for (int index = 0; index < static_cast<int>(count); ++index)

#include "../Notebook_WF26/data_structures_clean/dsu.cpp"
#include "../Notebook_WF26/grafos_clean/dijkstra.cpp"
#include "../Notebook_WF26/strings_clean/z_function.cpp"

int main() {
    DSU components(6);
    components.join(1, 2);
    components.join(2, 3);
    assert(components.same(1, 3));
    assert(!components.same(1, 4));

    const vector<int> expected_z = {0, 4, 3, 2, 1};
    assert(z_function("aaaaa") == expected_z);

    vector<vector<arista>> graph(4);
    graph[0].push_back({1, 2});
    graph[0].push_back({2, 10});
    graph[1].push_back({2, 3});
    graph[2].push_back({3, 1});

    const vector<nodo> shortest_paths = Dijkstra(0, 4, graph);
    assert(shortest_paths[3].d == 6);
    assert(shortest_paths[3].a == 2);

    return 0;
}
