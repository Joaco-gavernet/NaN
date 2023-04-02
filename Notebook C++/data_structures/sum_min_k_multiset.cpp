typedef int tipo;

struct MultisetWithSum {
    multiset<tipo> ms;
    tipo sum = 0;
    void insert(tipo x) {ms.insert(x); sum += x;}
    void erase(tipo x) {ms.erase(ms.find(x)); sum -= x;}
    int size() const { return int(ms.size()); }
    tipo highest() const { return *ms.rbegin(); }
    tipo lowest() const { return *ms.begin(); }
};

struct SumMinKMultiset {
    MultisetWithSum low, high;
    void insert(tipo x) {low.insert(x);}
    void erase(tipo x) { (low.ms.find(x) != low.ms.end() ? low : high).erase(x);}
    tipo sumMinK(int k) { adjust(k); return low.sum; }
    tipo kth_element(int k) { adjust(k); return low.highest();}
    void adjust(int k) { // Low tenga k elementos
        assert(low.size() + high.size() >= k);
        while (low.size() < k) {
            tipo toMove = high.lowest();
            low.insert(toMove);
            high.erase(toMove);
        }
        while(high.size() > 0 && high.lowest() < low.highest()) {
            tipo toMove = high.lowest();
            high.erase(toMove); low.insert(toMove);
            toMove = low.highest();
            low.erase(toMove); high.insert(toMove);
        }
        while (low.size() > k) {
            tipo toMove = low.highest();
            low.erase(toMove);
            high.insert(toMove);
        }
    }
};
