// Convex Hull Trick
// O(log n) para agregar linea y consultar
// Las linease agregan en orden creciente de pendiente
typedef long long tipo;
typedef __int128 ull;

struct punto {
    tipo x, y;
    punto operator -(const punto &p) const {return {x-p.x,y-p.y};}
    punto operator +(const punto &p) const {return {x+p.x,y+p.y};}
    tipo operator *(const punto &p) const {return x*p.x + y*p.y;}
    ull operator ^(const punto &p) const { // Producto Cruz
        return (ull)x * p.y - (ull)y * p.x; } // (ull) --> __int128
};

struct chull { // Agregar siempre pendientes en orden creciente
    ll op = 1; // 1 para minimo, -1 para maximo
    vector <punto> hull;
    
    chull(bool maxi) { // true para maximo, false para minimo
        if(maxi) op *= -1;
        // add_line(0,0); // Push base case {0,0} if necessary
    }
    ll get(tipo x) {
        punto query = {op * x,op * 1LL};
        int a=0, b=SZ(hull);
        while(b-a > 1) {
            int med = (a+b)/2;
            if(query * hull[med-1] >= query * hull[med]) a = med;
            else b = med;
        }
        return op * (query * hull[a]);
    }
    
    bool check(punto aux, int last) {
        return op * ((hull[last]-hull[last-1])^(aux-hull[last])) <= 0;
    }
    
    void add_line(ll x, ll y) {
        if(SZ(hull)) assert(x >= hull.back().x);  // Chequeo de pendientes crecientes

        punto aux = {x,y}; int last = SZ(hull)-1;
        while(last > 0 && check(aux,last)) {
            hull.pop_back(); last--;
        }
        hull.pb(aux);
    }
};
