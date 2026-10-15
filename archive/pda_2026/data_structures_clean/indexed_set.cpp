using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
indexed_set s; s.insert(2); s.insert(3); s.insert(5);
auto x=s.find_by_order(2); // retorna el valor en la posicion 2 (5)
int pos=int(s.order_of_key(3)); // retorna la posicion que se encuentra el 3 (1)
