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