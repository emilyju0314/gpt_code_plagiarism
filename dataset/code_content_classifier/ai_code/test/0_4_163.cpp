#include <iostream>
#include <vector>
#include <algorithm>

const long long MOD = 1e9 + 7;

long long modpow(long long base, long long exp) {
    long long result = 1;
    base = base % MOD;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

long long modinv(long long a) {
    return modpow(a, MOD - 2);
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, m, rb, cb, rd, cd, p;
        std::cin >> n >> m >> rb >> cb >> rd >> cd >> p;

        long long dr = std::abs(rb - rd);
        long long dc = std::abs(cb - cd);

        long long probability = (p * modinv(100)) % MOD;
        long long expected_time = ((modpow(probability, dr + dc) - 1) * modinv(probability - 1)) % MOD;
        
        std::cout << expected_time << std::endl;
    }

    return 0;
}