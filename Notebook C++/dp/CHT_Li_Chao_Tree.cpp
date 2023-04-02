//~ Li Chao Tree
//~ Permite resolver CHT dinamico
//~ Desventaja: si evaluamos x > 10^6, no aguanta el segment tree

const int N = int(1e6 + 1);
const ll INF = ll(1e18+10);

struct punto { ll x, y; };

vector <punto> tree(4*N, {0, INF});

ll f(punto line, ll x) { return line.x * x + line.y; }


void insert(punto line, ll lo = 1, ll hi = N, int i = 1){
    ll m = (lo + hi) / 2;
    bool left = f(line, lo) < f(tree[i], lo);
    bool mid = f(line, m) < f(tree[i], m);

    if(mid) swap(tree[i], line);

    if(hi - lo == 1) return;
    else if(left != mid) insert(line, lo, m, 2*i);
    else insert(line, m, hi, 2*i+1);
}

ll query(ll x, ll lo = 1, ll hi = N, int i = 1){
    int m = (lo+hi)/2;
    ll curr = f(tree[i], x);
    if(hi-lo==1) return curr;
    if(x<m) return min(curr, query(x, lo, m, 2*i));
    else return min(curr, query(x, m, hi, 2*i+1));
}
