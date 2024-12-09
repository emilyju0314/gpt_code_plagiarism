#include <iostream>
#include <vector>

const int MOD = 998244353;

int power(int x, int y) {
    if (y == 0) return 1;
    int res = power(x, y / 2);
    res = (1LL * res * res) % MOD;
    if (y % 2 == 1) res = (1LL * res * x) % MOD;
    return res;
}

int main() {
    int n, k, c;
    std::cin >> n >> k >> c;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> dp(1 << c, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        std::vector<int> temp(1 << c, 0);
        for (int mask = 0; mask < (1 << c); mask++) {
            temp[mask] = (temp[mask] + dp[mask]) % MOD;
            temp[mask ^ a[i]] = (temp[mask ^ a[i]] + dp[mask]) % MOD;
        }
        dp = temp;
    }

    int inv = power(n, MOD - 2);
    int total_inv = power(power(2, c), MOD - 2);

    for (int mask = 0; mask < (1 << c); mask++) {
        std::cout << (1LL * dp[mask] * inv % MOD * total_inv % MOD + MOD) % MOD << " ";
    }

    return 0;
}