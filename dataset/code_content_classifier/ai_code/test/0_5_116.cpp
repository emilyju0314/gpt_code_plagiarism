#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 998244353

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        std::vector<int> cnt(n + 1, 0);
        std::vector<int> dp(n + 1, 0);
        
        int ans = 0;

        for (int i = 0; i < n; i++) {
            dp[i + 1] = dp[i] + cnt[a[i]];
            if (dp[i + 1] >= MOD) {
                dp[i + 1] -= MOD;
            }

            if (a[i] < n) {
                cnt[a[i]] += dp[i];
                if (cnt[a[i]] >= MOD) {
                    cnt[a[i]] -= MOD;
                }
            }
        }

        for (int i = 0; i <= n; i++) {
            ans += dp[i];
            if (ans >= MOD) {
                ans -= MOD;
            }
        }

        std::cout << ans << std::endl;
    }

    return 0;
}