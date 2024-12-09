#include <iostream>
#include <vector>
#include <algorithm>

const long long MOD = 998244353;

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> grid(N+1, std::vector<int>(N+1, -1));
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        std::cin >> a >> b >> c;
        grid[a][b] = c;
    }

    std::vector<std::vector<long long>> dp(N+1, std::vector<long long>(2, 0));
    dp[1][0] = dp[1][1] = 1;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (grid[i][j] != -1) {
                if (grid[i][j] == 0) {
                    if (i + 1 <= N) dp[i+1][1] = (dp[i+1][1] + dp[i][0]) % MOD;
                    if (j + 1 <= N) dp[i][j+1] = (dp[i][j+1] + dp[i][0]) % MOD;
                } else {
                    dp[i+1][1] = (dp[i+1][1] + dp[i][0]) % MOD;
                    dp[i][j+1] = (dp[i][j+1] + dp[i][0]) % MOD;
                }
            } else {
                dp[i+1][0] = (dp[i+1][0] + dp[i][0]) % MOD;
                dp[i][j+1] = (dp[i][j+1] + dp[i][0]) % MOD;
                dp[i+1][1] = (dp[i+1][1] + dp[i][1]) % MOD;
                dp[i][j+1] = (dp[i][j+1] + dp[i][1]) % MOD;
            }
        }
    }

    std::cout << (dp[N][1] + dp[N][0]) % MOD << std::endl;

    return 0;
}