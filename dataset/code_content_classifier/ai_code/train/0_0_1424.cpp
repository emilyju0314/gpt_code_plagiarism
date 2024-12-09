#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2)));

    dp[0][0][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            for(int l = 0; l <= 1; l++) {
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    int val = ch - s[i-1];
                    int new_j = j + l * (1LL * (val >= 0) * dp[i-1][j][l] % MOD); // Update beauty
                    new_j %= MOD;
                    int new_l = val > 0 ? 1 : 0; // Update whether the substring s[i] in t equals s[i]
                    dp[i][new_j][new_l] += dp[i-1][j][l];
                    dp[i][new_j][new_l] %= MOD;
                }
            }
        }
    }

    int ans = (dp[n][k][0] + dp[n][k][1]) % MOD;
    cout << ans << endl;

    return 0;
}