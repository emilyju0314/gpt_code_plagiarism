#include <iostream>
#include <vector>
#include <numeric>

const int MOD = 998244353;

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    int total_biscuits = 0;

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        total_biscuits += a[i];
    }

    long long ans = 0;
    long long inv_n = 1;
    for (int i = 2; i <= n; i++) {
        inv_n *= (MOD - MOD / i);
        inv_n %= MOD;
    }

    for (int i = 0; i < n; i++) {
        ans = (ans + (long long)a[i] * (n - 1) % MOD * inv_n) % MOD;
    }

    std::cout << (ans * total_biscuits) % MOD << std::endl;

    return 0;
}