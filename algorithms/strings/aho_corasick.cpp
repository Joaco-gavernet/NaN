struct vertex {
    map<char,int> next, go; 
    int p,link,nextleaf;
    char pch;
    vector<int> leaf;
    vertex(int p=-1, char pch=-1,int nextleaf=-1):
        p(p),pch(pch),link(-1),nextleaf(nextleaf){}
};

vector<vertex> t;
vector <vector <int> > g(MAXN); // Suffix-links tree

void aho_init(){ //do not forget!!
    t.clear(); t.pb(vertex());
}

void add_string(string s, int id) {
    int v=0;
    for(char c:s) {
        if(!t[v].next.count(c)){
            t[v].next[c]=t.size();
            t.pb(vertex(v,c));
        }
        v=t[v].next[c];
    }
    t[v].leaf.pb(id);
}

int go(int v, char c);

int get_link(int v) {
    if(t[v].link < 0) {
        if(v == 0 || t[v].p == 0) t[v].link = 0;
        else t[v].link = go(get_link(t[v].p),t[v].pch);
        g[t[v].link].pb(v);
    }
    return t[v].link;
}

int go(int v, char c){
    if(!t[v].go.count(c)) {
        if(t[v].next.count(c))t[v].go[c]=t[v].next[c];
        else t[v].go[c] = v == 0 ? 0 : go(get_link(v),c);
    }
    return t[v].go[c];
}

int init_next_leaf(int v) {
    if(v == 0) t[v].nextleaf=0;
    if(t[get_link(v)].leaf.size()) return t[v].nextleaf=get_link(v);

    else return t[v].nextleaf = t[get_link(v)].nextleaf != -1 ? 
        t[get_link(v)].nextleaf : 
            init_next_leaf(get_link(v));
}

void construct_links() { forn(i,t.size()) get_link(i); }
