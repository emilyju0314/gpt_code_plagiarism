#include <iostream>
#include <iomanip>
#include <vector>

const int MOD = 998244353;

int main() {
    int n;
    std::cin >> n;

    std::vector<double> x(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }

    std::vector<std::vector<double>> dp(n + 1, std::vector<double>(n * 1000 + 1, 0));
    dp[0][0] = 1.0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i * 1000; j++) {
            for (int t = 0; t <= 1000; t++) {
                if (j - t >= 0) {
                    dp[i][j] += dp[i - 1][j - t] / 1001;
                }
            }
        }
    }

    double ans = 0.0;
    for (int i = 1; i <= n; i++) {
        ans += dp[n][i] * (x[i - 1] - x[i - 2] + 1);
    }

    int result = ((long long)(ans * MOD) - 1) % MOD;
    std::cout << result << std::endl;

    return 0;
}