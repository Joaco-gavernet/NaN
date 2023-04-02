struct ntt {
    const int mod = 998244353;
    const int root = 15311432;
    const int root_1 = 469870224;
    const int root_pw = 1 << 23;

    void fft(vector<int> &a, bool invert) {
        int n = SZ(a);

        for(int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            for (; j&bit; bit >>= 1) j ^= bit;
            j ^= bit;

            if (i < j) swap(a[i], a[j]);
        }

        for(int len = 2; len <= n; len <<= 1) {
            int wlen = invert ? root_1 : root;
            for (int i = len; i < root_pw; i <<= 1)
                wlen = (int)(1LL * wlen * wlen % mod);

            for(int i = 0; i < n; i += len) {
                int w = 1;
                for (int j = 0; j < len / 2; j++) {
                    int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
                    a[i+j] = u + v < mod ? u + v : u + v - mod;
                    a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                    w = (int)(1LL * w * wlen % mod);
                }
            }
        }

        if (invert) {
            int n_1 = (int) inv_mod(n, mod);
            for (int &x : a) x = (int)(1LL * x * n_1 % mod);
        }
    }

    vector<int> multiply(vector<int> const &a, vector<int> const &b){
        vector<int> fa(all(a)), fb(all(b));
        int n = 1;
        while(n < SZ(a)+SZ(b)) n <<= 1;
        fa.resize(n), fb.resize(n);
        fft(fa, false); fft(fb, false); // transformo
        forn(i, n) fa[i] = (int) (1LL*fa[i]*fb[i]%mod);
        fft(fa, true); // anti-transformo

        vector<int> result(n);
        forn(i, n) result[i] = fa[i];
        return result;
    }    
};