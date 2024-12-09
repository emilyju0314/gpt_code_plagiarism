#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, rb, cb, rd, cd, p;
        cin >> n >> m >> rb >> cb >> rd >> cd >> p;

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = MOD;
            }
        }

        dp[rb][cb] = 0;
        int ans = 0;

        while (dp[rd][cd] == MOD) {
            vector<vector<int>> new_dp(n + 1, vector<int>(m + 1, MOD));

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (dp[i][j] == MOD) {
                        continue;
                    }

                    // Probability of cleaning the dirty cell
                    int prob_clean = p;

                    if (i != rd && j != cd) {
                        prob_clean = p * p % MOD;
                    }

                    // Update expected time based on moving in each direction
                    if (i + 1 <= n) {
                        new_dp[i + 1][j] = (new_dp[i + 1][j] + dp[i][j] + 1) % MOD;
                    }
                    if (j + 1 <= m) {
                        new_dp[i][j + 1] = (new_dp[i][j + 1] + dp[i][j] + 1) % MOD;
                    }
                    if (i - 1 >= 1) {
                        new_dp[i - 1][j] = (new_dp[i - 1][j] + dp[i][j] + 1) % MOD;
                    }
                    if (j - 1 >= 1) {
                        new_dp[i][j - 1] = (new_dp[i][j - 1] + dp[i][j] + 1) % MOD;
                    }

                    // Update expected time based on probability of cleaning
                    int cleaning_time = (dp[i][j] + 1) % MOD;
                    new_dp[i][j] = (new_dp[i][j] + 1LL * cleaning_time * prob_clean) % MOD;
                }
            }

            dp = new_dp;
            ans++;
        }

        cout << dp[rd][cd] << endl;
    }

    return 0;
}