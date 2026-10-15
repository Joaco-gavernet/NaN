vector<int> prime;
bool is_composite[MAXN];
int moebius[MAXN];

void sieve_moebius(int n) {
    fill(is_composite, is_composite + n, false);
    moebius[1] = 1;
    forr(i, 2, n){
        if(!is_composite[i]){
            prime.pb(i); moebius[i] = - 1; // i is prime
        }
        for(int j = 0; j < SZ(prime) && i * prime[j] < n; ++j) {
            is_composite[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                moebius[i * prime[j]] = 0;  // prime[j] divides i
                break;
            } else {
                moebius[i * prime[j]] = moebius[i] * moebius[prime[j]]; // prime[j] does not divide i
            }
        }
    }
}