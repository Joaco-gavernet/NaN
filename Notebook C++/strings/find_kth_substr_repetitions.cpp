typedef string str;
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
                                     //~ s += '$';
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

vector <ll> prefix;

ll suma(int l, int r) {
    return prefix[r+1] - prefix[l];
}

int BS(int l, int r, char &z, vector <int> &sa, str &pal, ll pos, ll k) {
    ll n = pal.size();
    ll a = l-1, b = r;
    while(b-a > 1) {
        ll med = (a+b) / 2;
        if((med-l+1)*(n-pos) - suma(l,med) >= k) b = med;
        else a = med;
    }
    z = pal[sa[b]+pos];
    return b;
}

int find_left(int l, int r, char z, vector<int> &sa, str &pal, int pos) {
    ll a = l-1, b = r;
    ll n = pal.size();
    while(b-a > 1) {
        ll med = (a+b)/2;
        if(sa[med]+pos >= n || pal[sa[med]+pos] != z) a = med;
        else b = med;
    }
    return b;
} 

int find_right(int l, int r, char z, vector<int> &sa, str &pal, int pos) {
    ll a = l, b = r+1;
    ll n = pal.size();
    while(b-a > 1) {
        ll med = (a+b)/2;
        if(sa[med]+pos >= n || pal[sa[med]+pos] != z) b = med;
        else a = med;
    }
    return a;
}


void solve(str &pal, str &ans, int l, int r, int pos, ll k, vector <int> &sa) {
    if(k <= 0) return;
    vector <int> cont(30,0);
    ll acum = 0; ll n = pal.size();
    char z = '#';
    int cr = BS(l,r,z,sa,pal,pos,k);
    ans += z;

    int new_start = find_left(l,cr,z,sa,pal,pos);
    int new_end = find_right(cr,r,z,sa,pal,pos);
    ll resta = (new_start - l) * (n -pos) - suma(l,new_start-1);
    if(sa[new_start] + pos == n) new_start++;
    solve(pal,ans,new_start,new_end,pos+1,k-resta-(new_end-new_start+1),sa);
}

string get_kth(string pal, ll k) {
    vector <int> sa = suffix_array(pal);
    prefix.resize(sa.size()+1,0);
    for(int i = 0; i < sa.size(); i++) {
        prefix[i+1] = prefix[i] + sa[i];
    }
    string ans;
    solve(pal,ans,0,pal.size()-1,0,k,sa);

    return ans;
}
