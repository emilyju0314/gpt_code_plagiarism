#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main() {
    int n, k, m;
    std::cin >> n >> k >> m;

    std::vector<std::vector<int>> dp(k + 1, std::vector<int>(n + 1, 0));
    dp[0][1] = 1;

    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            for (int x = 1; x <= m && j - x >= 1; x++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % MOD;
            }
        }
    }

    int total_ways = 0;
    for (int j = 1; j <= n; j++) {
        total_ways = (total_ways + dp[k][j]) % MOD;
    }

    std::cout << total_ways << std::endl;

    return 0;
}