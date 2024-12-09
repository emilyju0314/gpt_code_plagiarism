#include <iostream>
#include <vector>
#include <numeric>

const int MOD = 1000000007;

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(N + 1));
    dp[0][0] = 1;

    for(int i = 1; i <= N; i++) {
        std::partial_sum(dp[i-1].begin(), dp[i-1].end(), dp[i].begin());
        for(int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
        }
    }

    int ans = 0;
    for(int i = 0; i <= K; i++) {
        ans = (ans + (long long)dp[K][i] * dp[N-K][i]) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}