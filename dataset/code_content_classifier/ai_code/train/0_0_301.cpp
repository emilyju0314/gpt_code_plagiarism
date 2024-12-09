#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

std::vector<std::vector<int>> dp;

int countTrees(int n, int d) {
    dp.assign(n + 1, std::vector<int>(d + 1, 0));
    
    dp[0][0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= d; j++) {
            for (int k = 0; k < i; k++) {
                if (i - 1 - k >= 0) {
                    dp[i][j] = (dp[i][j] + (long long)dp[k][j - 1] * dp[i - 1 - k][j] % MOD) % MOD;
                }
            }
        }
    }
    
    return dp[n][d];
}

int main() {
    int n, d, mod;
    std::cin >> n >> d >> mod;
    
    int result = countTrees(n, d);
    
    std::cout << result << std::endl;
    
    return 0;
}