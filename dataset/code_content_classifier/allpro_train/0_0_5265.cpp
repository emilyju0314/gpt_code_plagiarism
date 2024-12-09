#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main() {
    int N, A, B, C, D;
    std::cin >> N >> A >> B >> C >> D;

    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(N + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = A; k <= B && j - k >= 0; k++) {
                for (int l = C; l <= D && i - j - l >= 0; l++) {
                    dp[i][j] = (dp[i][j] + dp[i - j][j - k]) % MOD;
                }
            }
        }
    }

    int res = 0;
    for (int i = C; i <= D; i++) {
        res = (res + dp[N][i]) % MOD;
    }

    std::cout << res << std::endl;

    return 0;
}