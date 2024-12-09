#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const int MOD = 1e9 + 7;

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::string s, t;
        std::cin >> s >> t;

        std::vector<int> dp(n + 1);
        dp[0] = 1;

        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == '?' && t[i - 1] == '?') {
                dp[i] = (dp[i - 1] * 3) % MOD;
            } else if (s[i - 1] == '?' || t[i - 1] == '?') {
                dp[i] = (dp[i - 1] * 2) % MOD;
            } else if (s[i - 1] == t[i - 1]) {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = 0;
            }
        }

        std::cout << dp[n] << std::endl;
    }

    return 0;
}