#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long ll;

using namespace __gnu_pbds;
using namespace std;

typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
    indexed_set s;
    s.insert(2); s.insert(3); s.insert(5);
    auto x=s.find_by_order(2); // retorna el valor en la posicion 2 (5) (se puede desreferenciar con *)
    int pos=int(s.order_of_key(3)); // retorna la posicion que se encuentra el 3 (1)
    return 0;
}
