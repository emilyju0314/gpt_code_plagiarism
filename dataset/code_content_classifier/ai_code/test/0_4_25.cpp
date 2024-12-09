#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n + 1, vector<int>(m, 0));
    dp[1][0] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m - j; k++) {
                dp[i][j + k] = (dp[i][j + k] + dp[i - 1][j]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < m; j++) {
        ans = (ans + dp[n][j]) % MOD;
    }

    cout << ans << endl;

    return 0;
}