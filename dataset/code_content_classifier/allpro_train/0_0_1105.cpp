#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 998244353;

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> p(N);
    for (int i = 0; i < N; i++) {
        std::cin >> p[i];
    }

    std::vector<std::vector<int>> dp(N, std::vector<int>(K+1, 0));

    for (int i = N-1; i >= 0; i--) {
        int sum = 0;
        for (int j = K-1; j >= 0; j--) {
            sum += dp[i+1][j];
            sum %= MOD;
        }
        dp[i][0] = sum;

        for (int j = 1; j <= K; j++) {
            dp[i][j] = (dp[i+1][j-1] + MOD - (p[i] > p[i+j-1] ? dp[i+1][j] : 0)) % MOD;
        }
    }

    std::cout << dp[0][K] << std::endl;

    return 0;
}