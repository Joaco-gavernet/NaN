typedef struct item *pitem;
struct item {
    ll key, prior, cont, mini, sum;
    bool rev; // (parameters for lazy prop)
    pitem l, r;
    item(ll key): 
        key(key),prior(rand()),cont(1),l(NULL),r(NULL),rev(0) {}
};
void push(pitem it) { //Lazy for reverse array
    if(it && it->rev) {
        swap(it->l,it->r);
        if(it->l)it->l->rev ^= true;
        if(it->r)it->r->rev ^= true;
        it->rev = false;
    }
}
int cont(pitem it) {return it ? it->cont : 0;}
ll mini(pitem it) {return it ? it->mini : 1<<30;}
ll sum(pitem it) {return it ? it->sum : 0LL;}
void upd_cont(pitem it){
    if(it) {
        it->cont = cont(it->l) + cont(it->r) + 1;
        it->mini = min(it->key,min(mini(it->l),mini(it->r)));
        it->sum = it->key + sum(it->l) + sum(it->r);
    }
}
void merge(pitem &t, pitem l, pitem r) { //Merge l and r, new root t
    push(l); push(r);
    if(!l || !r) t = l ? l : r;
    else if(l->prior > r->prior) merge(l->r,l->r,r), t=l;
    else merge(r->l,l,r->l), t = r;
    upd_cont(t);
}
void split(pitem t, pitem& l, pitem& r, int sz){ //sz:desired size of l
    if(!t) { l = r = 0; return;}
    push(t);
    if(sz <= cont(t->l)) split(t->l,l,t->l,sz), r = t;
    else split(t->r,t->r,r,sz-1-cont(t->l)), l = t;
    upd_cont(t);
}
int find_min(pitem t) { //Devuelve la posicion del minimo
    push(t);
    if(t->mini == t->key) return cont(t->l);
    else if(t->l && t->l->mini == t->mini) return find_min(t->l);
    else return cont(t->l)+1+find_min(t->r);
}
void set_treap(pitem &root, int p, ll val) {
    pitem aux1 = NULL, aux2 = NULL;
    split(root,root,aux2,p+1); split(root,root,aux1,p);
    aux1->key = val;
    merge(root,root,aux1); merge(root,root,aux2);
}
ll get_sum(pitem &root, int l, int r) {
    pitem aux1 = NULL, aux2 = NULL;
    split(root,root,aux2,r+1); split(root,root,aux1,l);
    ll ans = aux1->mini; // aux1->mini for minimum
    merge(root,root,aux1); merge(root,root,aux2);
    return ans;
}
void DFS(pitem t) { //Good for debug
    DBG(t->key);
    if(t->l != NULL) DBG(t->l->key); if(t->r != NULL) DBG(t->r->key);
    RAYA;
    if(t->l != NULL) DFS(t->l); if(t->r != NULL) DFS(t->r);
} 
