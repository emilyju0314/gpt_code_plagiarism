#include <iostream>
#include <vector>

const int MOD = 998244353;

int main() {
    int n, x;
    std::cin >> n >> x;

    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(x + 1));

    for(int i = 1; i <= x; i++) {
        dp[1][i] = 1;
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= x; j++) {
            for(int k = 1; k < j; k++) {
                dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
            }
        }
    }

    long long ans = 0;
    for(int i = 1; i <= x; i++) {
        ans = (ans + dp[n][i]) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}