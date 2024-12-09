#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, p;
    cin >> n >> p;
    
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<vector<vector<vector<int>>>> dp(n + 1, vector<vector<vector<int>>>(n + 1, vector<vector<int>>(n + 1, vector<int>(2, 0))));
    dp[0][0][0][0] = 1;
    if (c[0] == -1 || c[0] == p) dp[0][1][1 - p][p] = 1;
    if (c[0] == -1 || c[0] == 1 - p) dp[0][1][p][1 - p] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= i; k++) {
                for (int l = 0; l <= i; l++) {
                    if (j < i) dp[i][j + 1][k][l] = (dp[i][j + 1][k][l] + dp[i - 1][j][k][l]) % MOD;
                    if ((c[i] == -1 || c[i] == p) && k > 0) dp[i][j][k][l] = (dp[i][j][k][l] + dp[i - 1][j][k - 1][l]) % MOD;
                    if ((c[i] == -1 || c[i] == 1 - p) && l > 0) dp[i][j][k][l] = (dp[i][j][k][l] + dp[i - 1][j][k][l - 1]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = (ans + dp[n - 1][i][p][1 - p]) % MOD;
        ans = (ans + dp[n - 1][i][1 - p][p]) % MOD;
    }

    cout << ans << endl;

    return 0;
}