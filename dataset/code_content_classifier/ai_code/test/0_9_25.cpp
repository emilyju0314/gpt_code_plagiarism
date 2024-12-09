#include <iostream>
#include <vector>

const int MOD = 998244353;

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
    dp[1][0] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[i][j] = (2LL * dp[i - 1][j] % MOD + (j > 0 ? dp[i - 1][j - 1] : 0)) % MOD;
            if (j + m - j < m) {
                dp[i][j] = (dp[i][j] + (j > 0 ? dp[i - 1][j - 1] : 0)) % MOD;
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < m; ++j) {
        ans = (ans + dp[n][j]) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}