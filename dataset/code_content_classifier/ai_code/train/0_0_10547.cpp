#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

const int MOD = 998244353;

int main() {
    std::string S;
    std::cin >> S;
    
    int n = S.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1));
    
    dp[0][0] = 1;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            dp[i][j] = (2 * dp[i - 1][j]) % MOD;
            if (j > 0) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
            }
        }
    }
    
    int ans = 0;
    for (int j = 0; j <= n; ++j) {
        std::sort(S.begin(), S.end());
        do {
            int k = 1;
            for (int i = 0; i < n; ++i) {
                if (S[i] == '1') {
                    k = (k * dp[n - i][j]) % MOD;
                }
            }
            ans = (ans + k) % MOD;
        } while (std::next_permutation(S.begin(), S.end()));
    }
    
    std::cout << ans << std::endl;
    
    return 0;
}