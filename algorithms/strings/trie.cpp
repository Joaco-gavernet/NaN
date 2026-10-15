const int K = 26;

struct Vertex {
    int next[K];
    int leaf;

    Vertex() {
        fill(begin(next), end(next), -1);
        leaf = 0;
    }
};

vector<Vertex> trie(1);

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (trie[v].next[c] == -1) {
            trie[v].next[c] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[c];
    }
    trie[v].leaf++;
}

bool find(string &pal) {
    int cur = 0;
    for(char u : pal) {
        cur = trie[cur].next[u-'a'];
        if(cur == -1) return false;
    }
    return true;
}  
