#include <iostream>
#include <vector>
#include <string>

#define MOD 1000000007

int main() {
    std::string s, t;
    std::cin >> s >> t;

    int n = s.length();
    int m = t.length();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i-1][j];
            if (s[i-1] == t[j-1]) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-1] + 1) % MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + dp[i][m]) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}