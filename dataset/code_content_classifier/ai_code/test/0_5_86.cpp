#include <iostream>
#include <vector>

const int MOD = 998244353;

int main() {
    int t;
    std::cin >> t;
    
    while (t--) {
        int n, k, x;
        std::cin >> n >> k >> x;
        
        int maxVal = 1 << k;
        std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(maxVal, 0));
        
        dp[1][x] = 1;
        dp[1][0] = maxVal - 1;
        
        for (int i = 2; i <= n; i++) {
            for (int xorVal = 1; xorVal < maxVal; xorVal++) {
                for (int prevXor = 0; prevXor < maxVal; prevXor++) {
                    if ((prevXor & xorVal) == x) {
                        continue;
                    }
                    
                    dp[i][xorVal] = (dp[i][xorVal] + dp[i - 1][prevXor]) % MOD;
                }
            }
        }
        
        long long ans = 0;
        for (int i = 0; i < maxVal; i++) {
            ans = (ans + dp[n][i]) % MOD;
        }
        
        std::cout << ans << std::endl;
    }
    
    return 0;
}