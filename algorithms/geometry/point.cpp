typedef long double tipo; //Cambiar a long long para operar en enteros
double EPS = (double)(1e-10);

struct punto { // Puede usarse para vectores
    tipo x, y;
    punto const operator -(const punto &p) const {return {x-p.x,y-p.y};}
    punto const operator +(const punto &p) const {return {x+p.x,y+p.y};}
    tipo operator *(const punto &p) const {return x*p.x + y*p.y;}
    tipo operator ^(const punto &p) const {return x*p.y - y*p.x;}
    bool operator == (const punto &p) const {
        return (abs(x-p.x) < EPS && abs(y-p.y) < EPS); // Para double
    }
    bool operator <(punto p) const {return x != p.x ? x < p.x : y < p.y;}
    tipo arg() {return atan2(y,x);} 
    tipo mod() {return sqrtl(x*x + y*y);}
    tipo mod2() {return x*x + y*y;}
};

punto operator*(tipo k, const punto &p) {return {k*p.x, k*p.y};}

ostream &operator << (ostream &os, const punto &p) { //Para imprimir
    return os << "(" << p.x << "," << p.y << ")";
}

istream &operator >> (istream &is, punto &p) { //Para leer
    return is >> p.x >> p.y;
}

struct frac { // Por si es necesario trabajar con enteros
    tipo n, d;
    ll mcd(ll a, ll b) {
        a = abs(a); b = abs(b);
        while(a > 0 && b > 0) {
            if(a >= b) a %= b;
            else b %= a;
        }
        return a == 0 ? b : a;
    }
    frac(ll x, ll y) {
        ll g = mcd(x,y);
        n = x/g; d = y/g;
        if(d < 0) d *= -1, n *= -1; 
    }
    frac() {}
    bool operator ==(frac &F) const {return n*F.d == d*F.n;}
    bool operator < (frac &F) const {return n*F.d  < d*F.n;}
};
