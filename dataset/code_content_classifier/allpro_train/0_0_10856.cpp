#include <iostream>
#include <vector>

const int MOD = 1000000007;

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            // Place element i at position j
            dp[i][j] = dp[i-1][j] % MOD;

            if (j > 0) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
            }
            if (j < n) {
                dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
            }
        }
    }

    std::cout << dp[n][k] << std::endl;

    return 0;
}