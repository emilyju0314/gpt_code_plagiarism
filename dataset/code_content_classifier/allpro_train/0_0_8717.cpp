#include <iostream>
#include <vector>

const long long MOD = 1e9 + 7;

long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    int R, a1, a2, a3, a4;
    std::cin >> R >> a1 >> a2 >> a3 >> a4;

    std::vector<long long> p = {a1, a2, a3, a4};
    for (int i = 0; i < 4; i++) {
        p[i] = (p[i] * mod_pow(1000, MOD - 2, MOD)) % MOD;
    }

    long long ans = 0;
    for (int x = -50; x <= 50; x++) {
        for (int y = -50; y <= 50; y++) {
            if (x == 0 && y == 0) continue;
            long long prob = 1;
            if (x < 0) prob = (prob * p[0]) % MOD;
            else prob = (prob * p[2]) % MOD;
            if (y < 0) prob = (prob * p[1]) % MOD;
            else prob = (prob * p[3]) % MOD;
            long long dist = x * x + y * y;
            ans = (ans + prob * mod_pow(dist, MOD - 2, MOD)) % MOD;
        }
    }

    ans = (ans * mod_pow(1000, MOD - 2, MOD)) % MOD;
    ans = (ans * mod_pow(1000, MOD - 2, MOD)) % MOD;
    ans = (ans - 1 + MOD) % MOD;

    std::cout << ans << std::endl;

    return 0;
}