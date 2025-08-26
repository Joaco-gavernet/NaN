struct UnionFind {
    int n,comp;
    vi uf,si,c;
    UnionFind(int n=0):n(n),comp(n),uf(n),si(n,1){
        forn(i,n) uf[i]=(int)i;
    }
    int find(int x){return x==uf[x]?x:find(uf[x]);}
    bool join(int x, int y){
        if((x=find(x))==(y=find(y)))return false;
        if(si[x]<si[y])swap(x,y);
        si[x]+=si[y];uf[y]=x;comp--;c.pb(y);
        return true;
    }
    int snap(){return SZ(c);}
    void rollback(int snap){
        while(SZ(c)>snap){
            int x=c.back();c.pop_back();
            si[uf[x]]-=si[x];uf[x]=x;comp++;
        }
    }
};
enum {ADD,DEL,QUERY};
struct Query {int type,x,y;};
struct DynCon {
    vector<Query> q;
    UnionFind dsu;
    vector<int> mt;
    map<pair<int,int>,int> last;
    DynCon(int n):dsu(n){}
    void add(int x, int y){
        if(x>y)swap(x,y);
        q.pb({ADD,x,y});mt.pb(-1);last[{x,y}]=SZ(q)-1;
    }
    void remove(int x, int y){
        if(x>y)swap(x,y);
        q.pb({DEL,x,y});
        int pr=last[{x,y}];mt[pr]=SZ(q)-1;mt.pb(pr);
    }
    void query(int x, int y){q.pb({QUERY,x,y});mt.pb(-1);} // modificar que query se tiene que usar
    void process(){ // answers all queries in order
        if(!SZ(q)) return;
        forn(i,SZ(q))if(q[i].type==ADD&&mt[i]<0)mt[i]=SZ(q);
        go(0,SZ(q));
    }
    void go(int s, int e){
        if(s+1==e){
            if(q[s].type==QUERY) // answer query using DSU q[s]
                assert(false); // poner alguna operacion entre q[s].x y q[s].y
            return;
        }
        int k=dsu.snap(),m=(s+e)/2;
        for(int i=e-1;i>=m;--i)if(mt[i]>=0&&mt[i]<s)dsu.join(q[i].x,q[i].y);
        go(s,m);dsu.rollback(k);
        for(int i=m-1;i>=s;--i)if(mt[i]>=e)dsu.join(q[i].x,q[i].y);
        go(m,e);dsu.rollback(k);
    }
};
