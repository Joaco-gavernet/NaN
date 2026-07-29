struct state {
    int len, link;
    map<char,int> next;
}; 
const int MAXN = 300010;
state st[MAXN*2];
int sz, last;
void sa_init(){
    forn(i,2*MAXN) {
        st[i].next.clear();
        st[i].link = 0;
        st[i].len = 0;
    }
    last= st[0].len=0; sz=1;
    st[0].link=-1;
}
void sa_extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    int p;
    for(p = last; p != -1 && !st[p].next.count(c); p = st[p].link) {
        st[p].next[c] = cur;
    }
    if (p == -1) st[cur].link = 0;
    else {
        int q = st[p].next[c];
        if(st[p].len + 1 == st[q].len) st[cur].link = q;
        else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}