#include <iostream>
#include <vector>
#include <string>

#define MOD 998244353

int main() {
    std::string s;
    std::cin >> s;

    std::vector<long long> dp(s.size() + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= s.size(); i++) {
        dp[i] = (dp[i-1] * 2) % MOD;
        for (int j = 1; j <= i-2; j++) {
            if (s[j-1] == s[i-1]) {
                dp[i] = (dp[i] + dp[j]) % MOD;
            }
        }
    }

    std::cout << dp[s.size()] << std::endl;

    return 0;
}