#include <iostream>
#include <vector>

const int MOD = 1000000007;

int main() {
    int m;
    std::cin >> m;

    std::vector<long long> dp(m + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= m; ++i) {
        dp[i] = (dp[i - 1] * i) % MOD;
    }

    long long ans = dp[m];

    for (int i = 1; i < m; ++i) {
        ans = (ans * i) % MOD;
    }

    std::cout << ((dp[m] - ans + MOD) % MOD) << std::endl;

    return 0;
}