#include <iostream>
#include <vector>

const int MOD = 998244353;

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<long long> dp(k + 1, 0);
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = k; j >= 1; j--) {
            dp[j] = ((dp[j] * (j - 1)) % MOD + dp[j - 1]) % MOD;
        }
    }

    for (int i = 1; i <= k; i++) {
        std::cout << dp[i] << " ";
    }

    return 0;
}