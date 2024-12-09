#include <iostream>
#include <vector>

const int MOD = 998244353;

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<long long>> dp(n, std::vector<long long>(m, 0));
    for (int i = 0; i < m; i++) {
        dp[0][i] = 1;
    }

    for (int k = 1; k < n; k++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                dp[k][i] = (dp[k][i] + dp[k-1][j]) % MOD;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < m; i++) {
        ans = (ans + dp[n - 1][i]) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}