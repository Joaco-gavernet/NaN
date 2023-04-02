typedef long long tipo;

struct CD{
    double r,i;
    CD(double r=0,double i=0):r(r),i(i){}
    double real()const{return r;}
    void operator /=(const tipo c){r/=c; i/=c;}
};
CD operator*(const CD& a, const CD& b){return CD(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);}
CD operator+(const CD& a, const CD& b){return CD(a.r+b.r,a.i+b.i);}
CD operator-(const CD& a, const CD& b){return CD(a.r-b.r,a.i-b.i);}
const double pi=acos(-1);
const tipo MAXN=1<<21;
CD cp1[MAXN+9],cp2[MAXN+9];
tipo R[MAXN+9];

void dft(CD* a, tipo n, bool inv){
    forn(i, n) if(R[i]<i) swap(a[R[i]],a[i]);
    for(int m=2;m<=n;m*=2){
        double z=2*pi/m*(inv?-1:1);
        CD wi=CD(cos(z),sin(z));
        for(int j=0;j<n;j+=m){
            CD w(1);
            for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
                CD u=a[k]; CD v=a[k2]*w;a[k]=u+v;a[k2]=u-v;w=w*wi;
            }
        }
    }
    if(inv) forn(i,n) a[i]/=n;
}
vector<tipo> multiply(vector<tipo> &p1, vector<tipo> &p2){
    tipo n=SZ(p1)+SZ(p2)+1;
    tipo m=1,cnt=0;
    while(m<=n) m+=m,cnt++;
    forn(i, m){R[i]=0;forr(j,0,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
    forn(i, m) cp1[i]=cp2[i]=0;
    forn(i, SZ(p1)) cp1[i]=p1[i];
    forn(i, SZ(p2)) cp2[i]=p2[i];
    dft(cp1,m,0); dft(cp2,m,0);
    forn(i, m) cp1[i]=cp1[i]*cp2[i];
    dft(cp1,m,1);
    vector<tipo> res;
    n -= 2;
    forn(i,n) res.pb((ll)floor(cp1[i].real()+.5));
    return res;
}
