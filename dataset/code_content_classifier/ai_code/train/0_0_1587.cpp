#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    string s, t;
    cin >> s >> t;

    int n = s.length();
    int m = t.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1] + 1) % MOD;
            } else {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + MOD) % MOD;
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}