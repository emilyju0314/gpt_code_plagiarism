#include <iostream>
#include <string>
#include <vector>

const int MOD = 998244353;

int main() {
    std::string s;
    std::cin >> s;
    
    int n = s.length();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            if (s[i] == '(' || s[i] == '?') {
                dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % MOD;
            }
            if (s[i] == ')' || s[i] == '?') {
                if (j > 0) {
                    dp[i+1][j-1] = (dp[i+1][j-1] + dp[i][j]) % MOD;
                }
            }
            if (s[i] == '?') {
                dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= n; j++) {
        ans = (ans + dp[n][j] * j) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}