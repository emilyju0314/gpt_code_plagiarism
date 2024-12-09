#include <iostream>
#include <vector>

const int MOD = 998244353;

int main() {
    int N, K, A;
    std::cin >> N >> K >> A;

    std::vector<int> dp(K+1);
    dp[0] = 1;

    for (int i = 0; i < K; i++) {
        dp[i] %= MOD;
        dp[i+1] = (dp[i] * (N-1)) % MOD;
        dp[i] = (1LL * A * dp[i] + 1LL * (100-A) * dp[i+1]) % MOD;
    }

    std::cout << dp[K] << std::endl;

    return 0;
}