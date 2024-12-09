#include <iostream>
#include <vector>

#define MOD 1000003

long long power(long long x, long long y, long long p) {
    long long res = 1;
    x = x % p;

    while (y > 0) {
        if (y & 1) {
            res = (res * x) % p;
        }
        y = y >> 1;
        x = (x * x) % p;
    }

    return res;
}

int main() {
    long long n, k;
    std::cin >> n >> k;

    long long A = 0, B = 1;
    if (k > n) {
        A = 1;
    } else {
        std::vector<long long> fact(2 * n + 1, 1);
        for (long long i = 1; i <= 2 * n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        long long temp = (fact[2 * n] * power(fact[n], MOD - 2, MOD)) % MOD;
        temp = (temp * power(fact[n], MOD - 2, MOD)) % MOD;

        for (long long i = 0; i < k; i++) {
            A = (A + (((i % 2 == 0) ? 1 : -1) * temp) + MOD) % MOD;
            temp = (temp * power(n - i, MOD - 2, MOD)) % MOD;
        }
    }

    std::cout << A << " " << B << std::endl;

    return 0;
}