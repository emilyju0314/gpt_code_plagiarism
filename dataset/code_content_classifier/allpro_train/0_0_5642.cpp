#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n, vector<int>(m, 0));

    dp[0][0] = 2;
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] * 2 % MOD;
    }

    for (int j = 1; j < m; j++) {
        dp[0][j] = dp[0][j - 1] * 2 % MOD;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }

    cout << dp[n - 1][m - 1] << endl;

    return 0;
}