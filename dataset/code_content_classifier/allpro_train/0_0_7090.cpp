#include <iostream>
#include <vector>

const int MOD = 1000000007;

int main() {
    int R, C;
    std::cin >> R >> C;

    std::vector<std::vector<int>> grid(R, std::vector<int>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            std::cin >> grid[i][j];
        }
    }

    std::vector<std::vector<std::vector<int>>> dp(R * C + 1, std::vector<std::vector<int>>(19, std::vector<int>(19, 0)));
    dp[1][0][0] = 1;

    for (int i = 1; i <= R * C; i++) {
        for (int j = 0; j <= 18; j++) {
            for (int k = 0; k <= 18; k++) {
                if (grid[(i - 1) / C][(i - 1) % C] == 0) {
                    for (int l = 1; l <= 3; l++) {
                        if (k + l <= 18) {
                            dp[i + 1][k + l][l] += dp[i][j][k];
                            dp[i + 1][k + l][l] %= MOD;
                        }
                    }
                } else {
                    int center = grid[(i - 1) / C][(i - 1) % C];
                    if (k + 1 <= center && j + 1 <= 3) {
                        dp[i + 1][center][j + 1] += dp[i][j][k];
                        dp[i + 1][center][j + 1] %= MOD;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= 18; i++) {
        for (int j = 0; j <= 18; j++) {
            ans = (ans + dp[R * C + 1][i][j]) % MOD;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}