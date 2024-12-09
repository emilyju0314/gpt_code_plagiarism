#include <iostream>
#include <vector>

const int MOD = 1000000007;

int main() {
    int N, H, D;
    std::cin >> N >> H >> D;

    std::vector<int> dp(N + 1, 0);
    dp[0] = 1;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= std::min(i, H); j++) {
            dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }

    int ans = dp[N];

    for (int i = 1; i < N; i++) {
        if (H - D > 0) {
            ans = (ans * 2) % MOD;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}