#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n + 1, vector<int>(m, 0));
    vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
    dp[0][0] = sum[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = (sum[i - 1][j] - (j >= m - 1 ? 0 : sum[i - 1][m - 1] - dp[i - 1][m - 1]) + MOD) % MOD;
            sum[i][j + 1] = (sum[i][j] + dp[i][j]) % MOD;
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        ans = (ans + dp[n][i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}