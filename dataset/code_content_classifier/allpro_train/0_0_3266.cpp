#include <iostream>
#include <vector>

const int MOD = 998244353;

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<long long>> dp(M + 1, std::vector<long long>(2 * N, 0));
    dp[0][0] = 1;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            dp[i + 1][j + 2] = (dp[i + 1][j + 2] + dp[i][j]) % MOD;
            dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
        }
    }

    long long ans = 0;
    for (int j = 0; j < N; j++) {
        ans = (ans + dp[M][j]) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}