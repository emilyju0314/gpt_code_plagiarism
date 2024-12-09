#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n, p;
        std::cin >> n >> p;

        std::vector<int> k(n);
        int totalSum = 0;
        for(int i = 0; i < n; i++) {
            std::cin >> k[i];
            totalSum += k[i];
        }

        std::sort(k.begin(), k.end(), std::greater<int>());

        std::vector<std::vector<int>> dp(n+1, std::vector<int>(totalSum+1, 0));
        dp[0][0] = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= totalSum; j++) {
                dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD;
                dp[i+1][j + k[i]] = (dp[i+1][j + k[i]] + dp[i][j]) % MOD;
            }
        }

        int ans = MOD;
        for(int i = 0; i <= totalSum; i++) {
            ans = std::min(ans, std::abs(totalSum - 2*i));
        }

        std::cout << ans << std::endl;
    }

    return 0;
}