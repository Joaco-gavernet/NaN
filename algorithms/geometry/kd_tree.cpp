struct pt {  // for 3D add z coordinate
	ll x,y;
	pt(ll x, ll y):x(x),y(y){}
	pt(){}
	ll norm2(){return *this**this;}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	ll operator*(pt p){return x*p.x+y*p.y;}
	// 2D from now on
	bool operator<(pt p)const{ // for convex hull
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);}
};

ll manhattan(pt a, pt b){ return abs(a.x-b.x)+abs(a.y-b.y); }

// given a set of points, answer queries of nearest point in O(log(n))
bool onx(pt a, pt b){return a.x<b.x;}
bool ony(pt a, pt b){return a.y<b.y;}
struct Node {
	pt pp;
	ll x0=INF, x1=-INF, y0=INF, y1=-INF;
	Node *first=0, *second=0;
	ll distance(pt p){
		ll x=min(max(x0,p.x),x1);
		ll y=min(max(y0,p.y),y1);
		return manhattan(pt(x,y), p);
	}
	Node(vector<pt>&& vp):pp(vp[0]){
		for(pt p:vp){
			x0=min(x0,p.x); x1=max(x1,p.x);
			y0=min(y0,p.y); y1=max(y1,p.y);
		}
		if(SZ(vp)>1){
			sort(all(vp),x1-x0>=y1-y0?onx:ony);
			int m=SZ(vp)/2;
			first=new Node({vp.begin(),vp.begin()+m});
			second=new Node({vp.begin()+m,vp.end()});
		}
	}
};
struct KDTree {
	Node* root;
	KDTree(const vector<pt>& vp):root(new Node({all(vp)})) {}
	pair<ll,pt> search(pt p, Node *node){
		if(!node->first){
			//avoid query point as answer
			//if(p==node->pp) {INF,pt()};
			return {manhattan(p, node->pp),node->pp};
		}
		Node *f=node->first, *s=node->second;
		ll bf=f->distance(p), bs=s->distance(p);
		if(bf>bs)swap(bf,bs),swap(f,s);
		auto best=search(p,f);
		if(bs<best.first) best=min(best,search(p,s));
		return best;
	}
	// Return nearest point and its distance to p
	pair<ll,pt> nearest(pt p){return search(p,root);}
};
