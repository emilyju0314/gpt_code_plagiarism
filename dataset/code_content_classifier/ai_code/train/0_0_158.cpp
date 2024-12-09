#include <iostream>
#include <vector>
using namespace std;

const int MOD = 100000007;

int main() {
    int r, c, a1, a2, b1, b2;
    cin >> r >> c >> a1 >> a2 >> b1 >> b2;

    vector<vector<int>> dp(r, vector<int>(c, 0));
    dp[a1][a2] = 1;

    for (int i = a1; i != b1; i = (i + 1) % r) {
        vector<vector<int>> new_dp(r, vector<int>(c, 0));
        for (int j = 0; j < c; j++) {
            new_dp[i][j] = dp[i][j];
            if (i != 0) new_dp[i][j] = (new_dp[i][j] + dp[(i - 1 + r) % r][j]) % MOD;
            if (i != r - 1) new_dp[i][j] = (new_dp[i][j] + dp[(i + 1) % r][j]) % MOD;
            if (j != 0) new_dp[i][j] = (new_dp[i][j] + dp[i][j - 1]) % MOD;
            if (j != c - 1) new_dp[i][j] = (new_dp[i][j] + dp[i][j + 1]) % MOD;
        }
        dp = new_dp;
    }

    int ans = dp[b1][b2];
    cout << ans << endl;

    return 0;
}