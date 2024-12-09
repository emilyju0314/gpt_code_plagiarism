#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

const int MOD = 1e9 + 7;

uint64_t gcd(uint64_t a, uint64_t b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int k;
    cin >> k;

    vector<uint64_t> a(k);
    uint64_t n = 1;
  
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        n *= a[i] % MOD;
        n %= MOD;
    }

    uint64_t q = (1ULL << k) % MOD;
    uint64_t inv = 0;
    
    for (int i = 0; i < k; i++) {
        uint64_t tmp = q * a[i];
        tmp %= MOD;
        tmp *= inv;
        tmp %= MOD;
        inv += tmp;
        inv %= MOD;
    }

    uint64_t p = (n - inv + MOD) % MOD;
    uint64_t g = gcd(p, q);

    p /= g;
    q /= g;

    cout << p << "/" << q;

    return 0;
}