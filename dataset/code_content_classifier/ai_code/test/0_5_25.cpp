#include <iostream>
#include <vector>

const int MOD = 998244353;

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m - j && k < m; k++) {
                dp[i][j + k] = (dp[i][j + k] + dp[i - 1][j]) % MOD;
            }
        }
    }

    int result = 0;
    for (int j = 0; j < m; j++) {
        result = (result + dp[n][j]) % MOD;
    }

    std::cout << result << std::endl;

    return 0;
}