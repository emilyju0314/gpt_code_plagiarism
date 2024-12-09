#include <iostream>
#include <vector>

#define MOD 1000000007

long long power(long long x, long long y) {
    long long res = 1;
    x = x % MOD;

    while (y > 0) {
        if (y & 1) {
            res = (res * x) % MOD;
        }
        y = y >> 1;
        x = (x * x) % MOD;
    }

    return res;
}

int main() {
    long long N;
    std::cin >> N;

    std::vector<long long> dp(60, 0);
    dp[0] = 1;

    for (int i = 1; i < dp.size(); i++) {
        dp[i] = (dp[i-1] * 3) % MOD;
    }

    long long ans = 1;
    for (int i = 0; i < 60; i++) {
        if (N & (1LL << i)) {
            ans = (ans * dp[i]) % MOD;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}