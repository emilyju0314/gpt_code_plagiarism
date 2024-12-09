#include <iostream>
#define MOD 998244353

long long powerMod(long long base, long long exp) {
    long long result = 1;
    base = base % MOD;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        exp = exp / 2;
        base = (base * base) % MOD;
    }

    return result;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (k % i == 0) {
            ans = (ans + powerMod(k / i, n)) % MOD;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}