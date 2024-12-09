#include <iostream>
#include <vector>
#include <cmath>

const long long MOD = 998244353;

long long calc(int m, int n) {
    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(m, 0));
    
    for (int i = 0; i < m; i++) {
        dp[1][i] = 1;
    }
    
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                if (j + k < m) {
                    dp[i][j + k] = (dp[i][j + k] + dp[i-1][j]) % MOD;
                }
            }
        }
    }
    
    long long total = 0;
    for (int i = 0; i < m; i++) {
        total = (total + dp[n][i]) % MOD;
    }
    
    return total;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    
    long long ans = calc(m, n);
    
    std::cout << ans << std::endl;
    
    return 0;
}