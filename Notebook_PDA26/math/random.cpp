mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct MyRandom() {
    uniform_int_distribution<int> dist;
    MyRandom(int l, int r) : dist(l, r) {}
    int get(int l, int r) { return dist(rng); }
};
shuffle(all(v), rng);