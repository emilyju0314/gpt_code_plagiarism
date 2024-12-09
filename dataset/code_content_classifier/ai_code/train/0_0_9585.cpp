#include <iostream>
#include <vector>
#include <cmath>

#define MOD 1000000007

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<std::vector<int>> dp(n+1, std::vector<int>(n+1, 0));
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            for(int k = 0; k < j; k++) {
                if (!sqrt(a[k]*a[i-1] + 0.1)) {  // Check if api·api + 1 is a perfect square
                    dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= n; i++) {
        ans = (ans + dp[n][i]) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}