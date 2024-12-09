#include <iostream>
#include <vector>
#include <cmath>

const int MOD = 1000000007;

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> vertices(n);
    for (int i = 0; i < n; i++) {
        std::cin >> vertices[i].first >> vertices[i].second;
    }

    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    for (int i = 2; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int k = (j + i) % n;
            for (int m = (j + 1) % n; m != k; m = (m + 1) % n) {
                if (std::abs((vertices[j].first - vertices[m].first) * (vertices[k].second - vertices[m].second) -
                             (vertices[j].second - vertices[m].second) * (vertices[k].first - vertices[m].first)) !=
                    0) {
                    dp[j][k] += (1LL * dp[j][m] * dp[m][k]) % MOD;
                    dp[j][k] %= MOD;
                }
            }
        }
    }

    std::cout << dp[0][n-1] << std::endl;

    return 0;
}