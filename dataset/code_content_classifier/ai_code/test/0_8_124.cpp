#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 1000000007;

int dp[2001][2][2]; // dp[i][j][k] represents the number of ways to reach configuration j by the ith position.

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s, t;
        cin >> s >> t;

        dp[0][0][0] = 1;
        dp[0][0][1] = 0;
        dp[0][1][0] = 0;
        dp[0][1][1] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    if (dp[i][j][k] == 0) continue;

                    for (int a = 0; a < 2; a++) {
                        for (int b = 0; b < 2; b++) {
                            if (s[i] != '?' && s[i] != a + '0') continue;
                            if (t[i] != '?' && t[i] != b + '0') continue;

                            if (a + b == j) {
                                dp[i + 1][k || (a != b)][b] += dp[i][j][k];
                                if (dp[i + 1][k || (a != b)][b] >= MOD) {
                                    dp[i + 1][k || (a != b)][b] -= MOD;
                                }
                            }
                        }
                    }
                }
            }
        }

        int ans = (dp[n][0][1] + dp[n][1][1]) % MOD;
        cout << ans << endl;
    }

    return 0;
}