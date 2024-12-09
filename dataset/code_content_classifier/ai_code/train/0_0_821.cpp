#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

int main() {
    int k;
    std::cin >> k;

    std::vector<int> colors(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> colors[i];
    }

    std::vector<std::vector<long long>> dp(k + 1, std::vector<long long>(1001, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j <= 1000; ++j) {
            for (int l = 0; l <= colors[i - 1]; ++l) {
                if (j >= l) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - l]) % MOD;
                }
            }
        }
    }

    long long ans = 1;
    for (int i = 1; i <= k; ++i) {
        ans = (ans * dp[i][colors[i - 1]]) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}