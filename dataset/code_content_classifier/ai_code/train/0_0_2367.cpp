#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int modpow(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (1LL * result * base) % MOD;
        }
        base = (1LL * base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k;
        std::cin >> n >> k;

        int numerator = 1, denominator = 1;
        for (int i = 1; i <= n && i < k; ++i) {
            numerator = (1LL * numerator * (k - i)) % MOD;
            denominator = (1LL * denominator * i) % MOD;
        }

        int total = modpow(n, MOD - 2);
        int expected = (1LL * total * numerator) % MOD;

        std::cout << expected << std::endl;
    }

    return 0;
}