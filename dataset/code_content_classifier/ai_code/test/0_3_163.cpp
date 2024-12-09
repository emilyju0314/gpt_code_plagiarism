#include <iostream>
#include <vector>

const int MOD = 1000000007;

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, m, rb, cb, rd, cd, p;
        std::cin >> n >> m >> rb >> cb >> rd >> cd >> p;

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
        dp[rd][cd] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == rd && j == cd) {
                    continue; // Skip the dirty cell
                }

                int prob = 100 - p;
                int invProb = 1;
                int totalProb = prob;
                int expectation = 0;

                if (i != rd && j != cd) {
                    invProb = (MOD + 1 - prob) % MOD;
                    totalProb = (1LL * prob * prob + 1) % MOD;
                }

                expectation = (1LL * dp[i - 1][j] * prob + 1LL * dp[i][j - 1] * prob) % MOD;
                expectation = (1LL * expectation * prob + 1) % MOD;

                if (i != rd && j != cd) {
                    int addExpectation = (1LL * totalProb * expectation % MOD * invProb % MOD) % MOD;
                    dp[i][j] = (MOD + expectation - addExpectation) % MOD;
                } else {
                    dp[i][j] = expectation;
                }
            }
        }

        std::cout << dp[rb][cb] << std::endl;
    }

    return 0;
}