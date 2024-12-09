#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int m;
    cin >> m;

    string s;
    cin >> s;

    while (m--) {
        int t;
        cin >> t;

        if (t == 1) {
            cin >> s;
        } else if (t == 2) {
            int n;
            cin >> n;

            vector<vector<int>> dp(s.size() + 1, vector<int>(n + 1, 0));
            dp[0][0] = 1;

            for (int i = 1; i <= s.size(); i++) {
                for (int j = 1; j <= n; j++) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                    if (s[i - 1] == 'a' + j - 1) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                    }
                }
            }

            int ans = 0;
            for (int i = 0; i <= n; i++) {
                ans = (ans + dp[s.size()][i]) % MOD;
            }

            cout << ans << endl;
        }
    }

    return 0;
}