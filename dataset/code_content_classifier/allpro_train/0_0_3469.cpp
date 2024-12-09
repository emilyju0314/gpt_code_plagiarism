#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<int> ambiguity(n);
    for (int i = 0; i < n; i++) {
        std::cin >> ambiguity[i];
    }

    std::string target = "hard";
    int m = target.length();

    std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m;j++) {
            if (s[i-1] == target[j-1]) {
                dp[i][j] = std::max(dp[i-1][j-1] + ambiguity[i-1], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= m; i++) {
        result = std::max(result, dp[n][i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ambiguity[i];
    }

    std::cout << sum - result << std::endl;

    return 0;
}