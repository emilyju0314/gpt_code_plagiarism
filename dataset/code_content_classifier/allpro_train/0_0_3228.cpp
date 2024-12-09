#include <iostream>
#include <vector>
#include <cstring>

const int MOD = 51123987;

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;

    std::vector<std::vector<std::vector<int>>> dp(n+1, std::vector<std::vector<int>>(n+1, std::vector<int>(n+1, 0)));
    dp[0][0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= i; k++) {
                if (j + k > i) continue;

                dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k]) % MOD;
                if (s[i-1] == 'a') {
                    dp[i][j][k] = (dp[i][j][k] + dp[i-1][j-1][k]) % MOD;
                }
                if (s[i-1] == 'b') {
                    dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k-1]) % MOD;
                }
                if (s[i-1] == 'c') {
                    dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (std::abs(i - j) <= 1) {
                ans = (ans + dp[n][i][j]) % MOD;
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}