#include <cassert>
#include <queue>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using tipo = long long;
using vi = vector<int>;

#define forn(index, count) \
    for (int index = 0; index < static_cast<int>(count); ++index)
#define forr(index, start, end) \
    for (int index = (start); index < static_cast<int>(end); ++index)

#include "../algorithms/data_structures/dsu.cpp"
#include "../algorithms/graphs/dijkstra_wf26.cpp"
#include "../algorithms/strings/hashing.cpp"
#include "../algorithms/strings/z_function.cpp"

// Issue: Hash must accept const strings and temporaries, and be reassignable.
static_assert(is_constructible_v<Hash, const string&>);
static_assert(is_constructible_v<Hash, string&&>);
static_assert(is_copy_assignable_v<Hash> && is_move_assignable_v<Hash>);

int main() {
    DSU components(6);
    components.join(1, 2);
    components.join(2, 3);
    assert(components.same(1, 3));
    assert(!components.same(1, 4));

    const vector<int> expected_z = {0, 4, 3, 2, 1};
    assert(z_function("aaaaa") == expected_z);

    const string text = "abcabc";
    Hash text_hash(text);
    assert(text_hash.get(0, 2) == text_hash.get(3, 5));
    assert(text_hash.get(0, 2) != text_hash.get(1, 3));
    text_hash = Hash(string("xabc"));
    assert(text_hash.get(1, 3) == Hash(text).get(0, 2));

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
