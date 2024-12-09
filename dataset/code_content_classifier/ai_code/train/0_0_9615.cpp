#include <iostream>
#include <vector>

const int MOD = 1000000007;

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<long long>> dp(N+1, std::vector<long long>(M+1, 0));
    dp[1][1] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i+1][j-1]) % MOD;
        }
    }

    std::cout << dp[N][M] << std::endl;

    return 0;
}