#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

struct RandomAll {
    mt19937 rng;
    RandomAll(int seed) {rng.seed(seed);}
    int nextInt(int l, int r) {
        uniform_int_distribution<int> dist(l, r);
        return dist(rng);
    }
    vector<int> permutation(int n) {
        vector<int> perm(n);
        iota(all(perm), 1);
        shuffle(all(perm), rng);
        return perm;
    }
    vector<int> randomVector(int n, int l, int r) {
        vector<int> vec(n);
        for (int i = 0; i < n; i++) vec[i] = nextInt(l, r);
        return vec;
    }
};

int main(int argc, char** argv) {
    int seed = argc > 1 ? atoi(argv[1]) : chrono::steady_clock::now().time_since_epoch().count();
    RandomAll rand(seed);
    int n = rand.nextInt(1, 10);
    int sum = rand.nextInt(1, 200);
    cout << n << " " << sum << "\n";
    vector<int> v = rand.randomVector(n, 1, 100);
    for(int u : v) cout << u << " ";
    cout << "\n";

    return 0;
}