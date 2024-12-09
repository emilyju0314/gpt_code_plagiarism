#include <iostream>
#define MOD 1000000007

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    long long dp[k+1];
    dp[0] = 1;

    for(int i = 1; i <= k; i++) {
        dp[i] = 1;
        for(int j = 1; j < n * m; j++) {
            dp[i] = (dp[i] * i) % MOD;
        }
    }

    long long ans = 1;
    for(int i = 1; i <= k; i++) {
        ans = (ans * dp[i]) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}