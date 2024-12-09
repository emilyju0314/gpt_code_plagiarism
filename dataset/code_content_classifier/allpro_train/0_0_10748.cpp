#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int len = 1; len <= n; len++) {
        for (int i = 0; i + len <= n; i++) {
            dp[i][i + len] = dp[i + 1][i + len] + 1;
            for (int j = i + 1; j < i + len; j++) {
                if (s[i] == s[j]) {
                    dp[i][i + len] = min(dp[i][i + len], dp[i + 1][j] + dp[j][i + len]);
                }
            }
        }
    }

    vector<int> costs(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        costs[i] = i * (i + 1) / 2;
    }

    vector<vector<int>> dp2(n + 1, vector<int>(k + 1, 1e9));
    dp2[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int l = i; l < n; l++) {
                dp2[l + 1][j + 1] = min(dp2[l + 1][j + 1], dp2[i][j] + (n - (l - i + 1) - dp[i][l + 1]));
            }
        }
    }

    int ans = 1e9;
    for (int i = 0; i <= n; i++) {
        ans = min(ans, dp2[i][k]);
    }

    if (ans == 1e9) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}