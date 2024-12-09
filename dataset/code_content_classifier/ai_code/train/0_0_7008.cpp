#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;

    int n = s.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, n));

    for (int i = 0; i <= n; ++i) {
        dp[i][i] = 0;
    }

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len <= n; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1];
            } else {
                dp[i][j] = std::min(dp[i + 1][j], dp[i][j - 1]) + 1;
            }
        }
    }

    std::cout << dp[0][n - 1] << std::endl;

    return 0;
}