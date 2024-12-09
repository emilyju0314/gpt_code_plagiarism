#include <iostream>
#include <vector>

const int MOD = 1000003;

int countWalls(int n, int C) {
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(C + 1));
    
    // Base case
    for (int i = 1; i <= C; i++) {
        dp[1][i] = 1;
    }
    
    // DP calculation
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= C; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }
    
    // Sum the results for the number of different walls
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = (res + dp[i][C]) % MOD;
    }
    
    return res;
}

int main() {
    int n, C;
    std::cin >> n >> C;
    
    int result = countWalls(n, C);
    
    std::cout << result << std::endl;
    
    return 0;
}