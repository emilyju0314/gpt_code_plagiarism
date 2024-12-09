#include <iostream>

const int MOD = 1e9 + 7;

int main() {
    int n;
    std::cin >> n;

    long long dp[n+1] = {0};
    
    dp[0] = 1;
    dp[1] = 0;

    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) * (i-1) % MOD;
    }

    std::cout << dp[n] << std::endl;

    return 0;
}