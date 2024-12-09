#include <iostream>
#include <algorithm>
#include <vector>

int longestCommonSubsequence(std::vector<int>& perm1, std::vector<int>& perm2) {
    int n = perm1.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (perm1[i - 1] == perm2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][n];
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<int>> perms(k, std::vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> perms[i][j];
        }
    }

    int longest = n;
    for (int i = 1; i < k; i++) {
        longest = std::min(longestCommonSubsequence(perms[i], perms[i - 1]), longest);
    }

    std::cout << longest << std::endl;

    return 0;
}