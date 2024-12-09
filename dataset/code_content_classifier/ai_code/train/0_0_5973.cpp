#include <iostream>
#include <vector>
#include <string>

const int MOD = 1000000007;

int main() {
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int m = s.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(m + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            if (j > 0) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
            }
            if (j < m) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }

    std::vector<int> pref(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        pref[i] = (pref[i - 1] + dp[m][i]) % MOD;
    }

    int result = 0;
    for (int i = 1; i <= n - m; i++) {
        result = (result + (1LL * pref[m] * pref[i]) % MOD) % MOD;
    }

    std::cout << result << std::endl;

    return 0;
}