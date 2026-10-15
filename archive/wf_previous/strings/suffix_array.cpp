#define RB(x) (x<n?r[x]:0)
void csort(vector<int>& sa, vector<int>& r, int k){
    int n=sa.size();
    vector<int> f(max(255,n),0),t(n);
    forr(i,0,n)f[RB(i+k)]++;
    int sum=0;
    forr(i,0,max(255,n))f[i]=(sum+=f[i])-f[i];
    forr(i,0,n)t[f[RB(sa[i]+k)]++]=sa[i];
    sa=t;
}

vector<int> suffix_array(string& s){ // O(n logn)
    s += '$';
    int n=s.size(),rank;
    vector<int> sa(n),r(n),t(n);
    forr(i,0,n)sa[i]=i,r[i]=s[i];
    for(int k=1;k<n;k*=2){
        csort(sa,r,k);csort(sa,r,0);
        t[sa[0]]=rank=0;
        forr(i,1,n){
            if(r[sa[i]]!=r[sa[i-1]]||RB(sa[i]+k)!=RB(sa[i-1]+k))rank++;
            t[sa[i]]=rank;
        }
        r=t;
        if(r[sa[n-1]]==n-1)break;
    }
    return sa;
}

vector<int> lcp_construction(string const& s, vector<int> const& p) {
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++) rank[p[i]] = i;
    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if(rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k]) k++;
        lcp[rank[i]] = k;
        if(k) k--;
    }
    return lcp;
}

bool substr_search(string &text, string &pal, vector <int> &sa) {
    int n = text.size(), a = -1, b = n-1;
    while(b-a > 1) {
        int med = (a+b)/2, pos = sa[med]; bool d = false;
        int tam = min((int)pal.size(),int(n-sa[med]));
        string check = text.substr(sa[med],tam);
        if(check < pal) a=med;
        else b = med;
    }
    int tam = min(int(pal.size()),int(n-sa[b]));
    string fin = text.substr(sa[b],tam);
    return fin == pal ? true : false;
}

ll count_substring(string &pal) {
    ll n = pal.size();
    vector <int> sa = suffix_array(pal);
    vector <int> lcp = lcp_construction(pal,sa);
    ll ans = n * (n+1) / 2;
    for(int u : lcp) ans -= (ll)u;
    return ans;
}

#define SZ(a) ((int)a.size())
string lcsubstr(string s, string t) {
    string r = s + '#' + t + '$';
    int best = 0; int pos = 0;
    vector <int> sa = suffix_array(r);
    vector <int> lcp = lcp_construction(r, sa);
    forr(i, 1, SZ(sa)) {
        if(isInRange(sa[i - 1], 0, SZ(s)) && isInRange(sa[i], SZ(s) + 1, SZ(r) - 1)) {
            if(lcp[i-1] > best) best = lcp[i-1], pos = sa[i];
        }
        if(isInRange(sa[i], 0, SZ(s)) && isInRange(sa[i - 1], SZ(s) + 1, SZ(r) - 1)) {
            if(lcp[i-1] > best) best = lcp[i-1], pos = sa[i];
        }
    }
    return r.substr(pos,best);
    // To find de LCSubstr between n string, we can concatenate the n
    // strings and apply min_segtree in lcp ans intervals with at least 
    // one suffix of each string. 
}
