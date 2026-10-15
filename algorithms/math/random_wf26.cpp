mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
T rnd(T l, T r) { return uniform_int_distribution<T>(l, r)(rng); }
using u128 = __uint128_t;
u128 rnd128() { return (u128(rng()) << 64) | rng(); }
shuffle(all(v), rng);
