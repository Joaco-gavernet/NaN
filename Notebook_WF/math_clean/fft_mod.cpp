/**
Implementacion iterativa de FFT and FFTmod. O(N log N)
La precision de la FFT depende de la respuesta.
x <= 5e14 (double), x <= 1e18(long double)
donde x = max(ans[i]) para la FFT, y x = N*mod for FFTmod
**/
typedef double ld;
typedef complex<ld> cd;
void fft(vector<cd> &a){
    int n=SZ(a), L=31-__builtin_clz(n);
    vi rev(n);
    forn(i, n) rev[i]=(rev[i/2]+((i&1)<<L))/2;
    forn(i, n) if(i<rev[i]) swap(a[i],a[rev[i]]);
    static vector<cd> root(2,1);
    for(static int k=2;k<n;k*=2){
        root.resize(n);
        cd z=polar(1.0,acos(-1)/k);
        forr(i, k, 2*k) root[i]=root[i/2]*((i&1)?z:1);
    }
    for(int k=1;k<n;k*=2){
        for(int i=0;i<n;i+=2*k){
            forn(j, k){
                cd z=root[j+k]*a[i+j+k];
                a[i+j+k]=a[i+j]-z;
                a[i+j]+=z;
            }
        }
    }
}
vi mul(vi &a, vi &b){
    int sa=SZ(a), sb=SZ(b);
    if(sa==0||sb==0) return {};
    int n=1<<(32-__builtin_clz(sa+sb-2));
    vector<cd> f(n),h(n);
    forn(i, n) f[i]=cd(ld(i<sa?a[i]:0),ld(i<sb?b[i]:0));
    fft(f);
    forn(i, n){
        ll j=(-i)&(n-1);
        h[i]=(f[j]*f[j]-conj(f[i]*f[i]))*cd(0,-0.25/n);
    }
    fft(h);
    vi c(sa+sb-1);
    forn(i, sa+sb-1) c[i]=ll(round(h[i].real()));
    return c;
}
vi mul_mod(vi &a, vi &b, ll mod){
    int sa=SZ(a), sb=SZ(b);
    if(sa==0||sb==0) return {};
    vi a1(sa),a2(sa),b1(sb),b2(sb);
    forn(i, sa) a1[i]=(a[i]&((1<<15)-1)),a2[i]=(a[i]>>15);
    forn(i, sb) b1[i]=(b[i]&((1<<15)-1)),b2[i]=(b[i]>>15);
    vi c1=mul(a1,b1),c2=mul(a1,b2),c3=mul(a2,b1),c4=mul(a2,b2);
    vi c(sa+sb-1);
    forn(i, sa+sb-1) c[i]=(c1[i]+((1<<15)*(c2[i]%mod+c3[i]%mod))+((1<<30)*(c4[i]%mod)))%mod;
    return c;
}
