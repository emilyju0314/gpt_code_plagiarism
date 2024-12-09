#include <iostream>
#include <vector>

const int MOD = 998244353;

int main() {
    int N, X;
    std::cin >> N >> X;

    std::vector<std::vector<std::vector<int>>> dp(N+1, std::vector<std::vector<int>>(X+1, std::vector<int>(3, 0)));
    
    dp[0][0][0] = 1;
    dp[0][0][1] = 1;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= X; j++) {
            for (int k = 0; k < 3; k++) {
                dp[i][j][0] = (dp[i][j][0] + dp[i-1][j][k]) % MOD;
                if (j+i <= X) {
                    dp[i][j+i][1] = (dp[i][j+i][1] + dp[i-1][j][k]) % MOD;
                }
                dp[i][j][2] = (dp[i][j][2] + dp[i-1][j][k]) % MOD;
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = (ans + dp[i][X][1]) % MOD;
    }
    
    std::cout << ans << std::endl;

    return 0;
}