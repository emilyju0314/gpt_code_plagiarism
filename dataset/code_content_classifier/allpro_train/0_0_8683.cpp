#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    int n, l, k;
    std::cin >> n >> l >> k;

    std::vector<int> pi(n);
    for (int i = 0; i < n; i++) {
        std::cin >> pi[i];
    }

    std::vector<int> ai(n);
    for (int i = 0; i < n; i++) {
        std::cin >> ai[i];
    }

    std::vector<std::vector<double>> dp(n+1, std::vector<double>(n+1, 0.0));
    dp[0][0] = 1.0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i+1][j+1] += dp[i][j] * pi[i] / 100.0;
            dp[i+1][j] += dp[i][j] * (100 - pi[i]) / 100.0;
        }
    }

    double ans = 0.0;
    for (int i = l; i <= n; i++) {
        if (i - l <= k) {
            double curr_prob = dp[n][i];
            for (int j = 0; j < i - l; j++) {
                curr_prob *= ai[j] / 100.0;
            }
            ans += curr_prob;
        }
    }

    std::cout << std::fixed << std::setprecision(12) << ans << std::endl;

    return 0;
}