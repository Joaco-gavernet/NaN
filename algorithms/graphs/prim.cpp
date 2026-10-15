//Prim Algorithm

//Dado un grado no direccionado, halla el arbol tal que la suma de
//los pesos de las aristas sea minimo

//Metodologia: insertamos un nodo cualquiera, agregamos en un priority
//queue las aristas, ordenadas desde el menor peso hasta el mayor.
//insertamos la menor arista y agregamos el otro extremo como un nodo
//nuevo. Iteramos estos pasos hasta obtener las n-1 aristas.

//El algoritmo retorna la lista con las arista que generan el minimum
//Spanning Tree

vector <pair<ll,ll>> v[500005];
vector <pair<ll,ll>> a;
vector <bool> visto(500005,false);
map <pair<ll,ll>,bool> mapa;

struct arista
{
    ll n, m; // n=nodo padre, m=nodo nuevo
    ll peso;
};

struct compare
{
    bool operator()(arista a, arista b)
    {
        if(a.peso!=b.peso) return a.peso<b.peso;
        else return true;
    }
};

vector <pair<ll,ll>> Prim(ll n)
{
    vector <pair<ll,ll>> lista;
    visto[n]=true;
    set <arista,compare> s;
    forn(i,v[n].size())
    {
        arista aux;
        aux.n=n; aux.m=v[n][i].F; aux.peso=v[n][i].S;
        s.insert(aux);
    }
    while(s.size()!=0)
    {
        auto it=s.begin();
        if(visto[it->m]==true) {s.erase(it); continue;}
        visto[it->m]=true;
        ll ini=it->n, fin=it->m, p=it->peso;
        lista.pb(mp(ini,fin));
        forn(i,v[fin].size())
        {
            arista aux;
            aux.n=fin; aux.m=v[fin][i].F; aux.peso=v[fin][i].S;
            if(visto[aux.m]==false) s.insert(aux);
        }
    }
    return lista;
}
