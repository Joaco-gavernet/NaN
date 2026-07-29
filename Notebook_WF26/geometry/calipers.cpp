// Devuelve la distancia entre los puntos mas lejanos en O(N)
// Cuando se usa con nuestra convex_hull, hacer reverse porque vienen CW
ld callipers(vector<punto> p, int n){ 
    ld r=0;     // prereq: Convex, ccw, NO COLLINEAR POINTS
    for(int i=0,j=n<2?0:1;i<j;++i){
        for(;;j=(j+1)%n){
            r=max(r,(p[i]-p[j]).mod());
            if((p[(i+1)%n]-p[i])^(p[(j+1)%n]-p[j])<=EPS)break;
        }
    }
    return r;
}
