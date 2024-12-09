#include <iostream>
#include <vector>

const int MOD = 998244353;

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k, x;
        std::cin >> n >> k >> x;

        if (n == 1) {
            std::cout << "1\n";
        } else {
            std::vector<long long> dp(1 << k, 0);
            dp[x] = 1;
            for (int i = 1; i < n; ++i) {
                std::vector<long long> new_dp(1 << k, 0);
                for (int j = 0; j < (1 << k); ++j) {
                    if (dp[j] == 0) continue;
                    for (int a = 0; a < (1 << k); ++a) {
                        if ((j & a) == 0) {
                            new_dp[j | a] += dp[j];
                            new_dp[j | a] %= MOD;
                        }
                    }
                }
                dp = new_dp;
            }

            long long ans = 0;
            for (int i = 0; i < (1 << k); ++i) {
                ans += dp[i];
                ans %= MOD;
            }
            std::cout << ans << "\n";
        }
    }

    return 0;
}