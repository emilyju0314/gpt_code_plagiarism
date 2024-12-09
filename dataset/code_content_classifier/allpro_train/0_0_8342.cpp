#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int longestCommonSubsequence(std::vector<std::string>& baseStrings, std::vector<int>& indices, std::string& s) {
    int m = indices.size();
    int n = s.size();

    std::vector<std::vector<int>> dp(m+1, std::vector<int>(n+1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (baseStrings[indices[i-1]-1][j-1] == s[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> baseStrings(n);

    for (int i = 0; i < n; i++) {
        std::cin >> baseStrings[i];
    }

    int m;
    std::cin >> m;
    
    std::vector<int> indices(m);

    for (int i = 0; i < m; i++) {
        std::cin >> indices[i];
    }

    std::string s;
    std::cin >> s;

    int result = longestCommonSubsequence(baseStrings, indices, s);

    std::cout << result << std::endl;
    
    return 0;
}