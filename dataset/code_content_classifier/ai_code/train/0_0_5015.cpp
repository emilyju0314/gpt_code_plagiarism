#include <iostream>
#include <vector>

const int MOD = 1000000007;

int main() {
    int N, C, s, t;
    std::cin >> N >> C >> s >> t;
    
    std::vector<std::vector<int>> dp(N+1, std::vector<int>(N+1, 0));
    
    for(int i = 1; i <= C; i++) {
        int a, b;
        std::cin >> a >> b;
        dp[a][b] = 1;
    }
    
    for(int i = 1; i <= N; i++) {
        dp[i][i] = 1;
    }
    
    for(int len = 2; len <= N; len++) {
        for(int l = 1; l + len - 1 <= N; l++) {
            int r = l + len - 1;
            for(int k = l; k < r; k++) {
                dp[l][r] += dp[l][k] * dp[k+1][r];
                dp[l][r] %= MOD;
            }
        }
    }
    
    int result = dp[s][t];
    std::cout << result << std::endl;
    
    return 0;
}