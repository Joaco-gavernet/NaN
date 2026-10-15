struct st2d{ // 0 indexado, [l, r] 
	// PARA HACER BUILD HAY QUE HACER LOS N*N updates
	int n;
	vector<vi> st;
	ll NEUT=0; // NEUTRO DE LA OPERACION
	ll op(ll a, ll b){return a+b;} // OPERACION
	
	st2d(int _n): n(_n) { st.resize(2*n+5, vi(2*n+5, 0)); }
	
	void upd(int x, int y, ll v){
		st[x+n][y+n]=v;
		for(int j=y+n;j>1;j>>=1)st[x+n][j>>1]=op(st[x+n][j],st[x+n][j^1]);
		for(int i=x+n;i>1;i>>=1)for(int j=y+n;j;j>>=1) st[i>>1][j]=op(st[i][j],st[i^1][j]);
	}

	ll query(int x0, int x1, int y0, int y1){
		ll r=NEUT; x1++, y1++;
		for(int i0=x0+n,i1=x1+n;i0<i1;i0>>=1,i1>>=1){
			int t[4],q=0;
			if(i0&1)t[q++]=i0++;
			if(i1&1)t[q++]=--i1;
			forn(k,q) for(int j0=y0+n,j1=y1+n;j0<j1;j0>>=1,j1>>=1){
				if(j0&1)r=op(r,st[t[k]][j0++]);
				if(j1&1)r=op(r,st[t[k]][--j1]);
			}
		}
		return r;
	}
};
