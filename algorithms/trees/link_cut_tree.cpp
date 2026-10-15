const int MAXN = 5e5+5;
int ls[MAXN],rs[MAXN],fa[MAXN],siz[MAXN],st[MAXN],ch[MAXN][2],siz2[MAXN];
bool rev[MAXN];
#define ls(x) ch[x][0]
#define rs(x) ch[x][1]
inline bool notrt(int x){return ls(fa[x])==x||rs(fa[x])==x;}
inline void pushdown(int x){
    if(rev[x]){
        if(ls(x)) ls(ls(x))^=rs(ls(x))^=ls(ls(x))^=rs(ls(x)),rev[ls(x)]^=1;
        if(rs(x)) ls(rs(x))^=rs(rs(x))^=ls(rs(x))^=rs(rs(x)),rev[rs(x)]^=1;
        rev[x]=0;
    }
}
inline void rotate(int x){
    int y=fa[x],z=fa[y];bool l=rs(y)==x,r=!l;
    if(notrt(y)) ch[z][rs(z)==y]=x;if(ch[x][r]) fa[ch[x][r]]=y;
    fa[y]=x,fa[x]=z,ch[y][l]=ch[x][r],ch[x][r]=y;
    siz[y]=siz[ls(y)]+siz[rs(y)]+1+siz2[y],siz[x]=siz[ls(x)]+siz[rs(x)]+1+siz2[x];
}
inline void splay(int x){
    int y=x,z=1;st[1]=y;
    while(notrt(y)) st[++z]=y=fa[y];
    while(z) pushdown(st[z--]);
    while(notrt(x)){
        y=fa[x],z=fa[y];
        if(notrt(y)) if(ls(z)==y^ls(y)==x) rotate(x);else rotate(y);rotate(x); 
    }
}
inline void access(int x){int y=0;while(x) splay(x),siz2[x]+=siz[rs(x)]-siz[y],rs(x)=y,siz[x]=siz[ls(x)]+siz[rs(x)]+1+siz2[x],x=fa[y=x];}
inline void make(int x){access(x),splay(x),ls(x)^=rs(x)^=ls(x)^=rs(x),rev[x]^=1;}
inline void split(int x,int y){make(x),access(y),splay(y);}
inline void link(int x,int y){make(x),make(y),fa[x]=y,siz2[y]+=siz[x];}
inline void cut(int x,int y){split(x,y),fa[x]=ls(y)=0,siz[y]=siz[ls(y)]+siz[rs(y)]+1+siz2[y];}
