// Linked list based on arrays
struct linked_list {
    ll n;
    vi l, r;
    linked_list(int n): n(_n) {
        l.resize(n); r.resize(n);
        forn(i, n){
            l[i] = (i-1+n)%n;
            r[i] = (i+1)%n;
        }
    }
    void erase(int pos){
        r[l[pos]] = r[pos];
        l[r[pos]] = l[pos];
    }
};
