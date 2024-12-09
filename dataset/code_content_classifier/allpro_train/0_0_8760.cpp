#include <iostream>
#include <vector>

const int MOD = 998244353;

int main() {
    std::string S, T;
    std::cin >> S >> T;

    int n = S.length();
    int m = T.length();

    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(n + 1)); // dp[i][j] represents number of ways to make A with i characters from S and j characters used from S
    dp[0][0] = 1;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i < n && S[i] == T[dp[i][j] - 1]) {
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
            }
            if (j < n && S[n - 1 - j] == T[dp[i][j] - 1]) {
                dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD;
            }
        }
    }

    long long ans = 0;
    for (int i = m; i <= n; i++) {
        ans = (ans + dp[i][n - i]) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}  