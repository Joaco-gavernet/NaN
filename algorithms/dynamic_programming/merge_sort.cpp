// Merge sort con inversiones
// Complejidad: O(n log n)
// Usage: merge_sort(0,n-1,v)

ll inv = 0; // Inversiones

vector <int> merge_sort(int li, int ri, vector <int> &v) {
    if(li == ri) return {v[li]};
    vector <int> ans;
    int med = (li+ri)/2;
    vector <int> l = merge_sort(li,med,v);
    vector <int> r = merge_sort(med+1,ri,v);
    int a = 0, b = 0;
    while(a < l.size() && b < r.size()) {
        if(l[a] <= r[b]) ans.pb(l[a++]);
        else { inv += (ll)(l.size() - a); ans.pb(r[b++]);}
    }
    while(a < l.size()) ans.pb(l[a]), a++;
    while(b < r.size()) ans.pb(r[b]), b++;
    return ans;
}
