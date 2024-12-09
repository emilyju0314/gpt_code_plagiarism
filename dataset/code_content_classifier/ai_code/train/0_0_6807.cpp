#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main() {
    int n;
    std::cin >> n;

    std::vector<int> balls(n);
    for (int i = 0; i < n; i++) {
        std::cin >> balls[i];
    }

    std::vector<std::vector<long long>> dp(n, std::vector<long long>(n));

    for (int len = 1; len < n; len++) {
        for (int i = 0; i < n; i++) {
            int j = (i + len) % n;
            for (int k = 1; k < len; k++) {
                int a = (i + k) % n;
                int b = (i + k + 1) % n;
                dp[i][j] += (dp[i][a] + dp[b][j]) * balls[a] * balls[b];
                dp[i][j] %= MOD;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
       ans += dp[i][(i + n - 1) % n] * balls[i];
       ans %= MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}