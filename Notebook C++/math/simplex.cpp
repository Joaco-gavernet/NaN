struct Simplex {
    vector<int> X,Y;
    vector<vector<double>> A;
    vector<double> b,c;
    double z;
    int n,m;
    void add_equation(vector<double> v, double val){ A.pb(v); b.pb(val); }
	void set_objective(vector<double> _c){ c = _c; }
    void pivot(int x,int y){
        swap(X[y],Y[x]);
        b[x]/=A[x][y];
        forr(i,0,m)if(i!=y)A[x][i]/=A[x][y];
        A[x][y]=1/A[x][y];
        forr(i,0,n)if(i!=x&&abs(A[i][y])>EPS){
            b[i]-=A[i][y]*b[x];
            forr(j,0,m)if(j!=y)A[i][j]-=A[i][y]*A[x][j];
            A[i][y]=-A[i][y]*A[x][y];
        }
        z+=c[y]*b[x];
        forr(i,0,m)if(i!=y)c[i]-=c[y]*A[x][i];
        c[y]=-c[y]*A[x][y];
    }
    pair<double,vector<double>> simplex() { 
		// maximiza c^T x, dado Ax<=b, x>=0
        // retorna par (maximum value, solution vector)
        n=b.size();m=c.size();z=0.;
        X=vector<int>(m);Y=vector<int>(n);
        forn(i,m)X[i]=i;
        forn(i,n)Y[i]=i+m;
        while(1){
            int x=-1,y=-1;
            double mn=-EPS;
            forn(i,n)if(b[i]<mn)mn=b[i],x=i;
            if(x<0) break;
            forr(i,m)if(A[x][i]<-EPS){y=i;break;}
            assert(y>=0 && "No solution found"); // no solution to Ax<=b
            pivot(x,y);
        }
        while(1){
            double mx=EPS;
            int x=-1,y=-1;
            forn(i,m)if(c[i]>mx)mx=c[i],y=i;
            if(y<0)break;
            double mn=1e200;
            forn(i,n)if(A[i][y]>EPS&&b[i]/A[i][y]<mn)mn=b[i]/A[i][y],x=i;
            assert(x>=0 && "c^T x is unbounded"); // c^T x is unbounded
            pivot(x,y);
        }
        vector<double> r(m);
        forn(i,n)if(Y[i]<m)r[Y[i]]=b[i];
        return mp(z,r);
    }
};
