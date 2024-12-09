#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 1000000007;

int main() {
    int q;
    std::cin >> q;

    std::vector<std::vector<int>> dp(110, std::vector<int>(110, 0));
    for (int i = 1; i <= 109; ++i) {
        for (int j = 1; j <= 109; ++j) {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1] + i + j) % MOD;
        }
    }

    for (int i = 0; i < q; ++i) {
        int x1, y1, x2, y2, k;
        std::cin >> x1 >> y1 >> x2 >> y2 >> k;

        int result = (dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1] + MOD) % MOD;
        std::cout << (result <= k ? result : 0) << std::endl;
    }

    return 0;
}