#include <iostream>
#include <vector>

const int MOD = 1000000007;

int main() {
    int t, k;
    std::cin >> t >> k;

    std::vector<long long> dp(100001, 0);
    dp[0] = 1;
    for (int i = 1; i < 100001; i++) {
        dp[i] = (dp[i - 1] + (i >= k ? dp[i - k] : 0)) % MOD;
    }

    for (int i = 0; i < t; i++) {
        int a, b;
        std::cin >> a >> b;

        long long ways = (dp[b] - dp[a - 1] + MOD) % MOD;
        std::cout << ways << std::endl;
    }

    return 0;
}