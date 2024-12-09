#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    vector<vector<int>> dp(r2+1, vector<int>(c2+1, 0));
    dp[0][0] = 1;

    for (int i = 0; i <= r2; i++) {
        for (int j = 0; j <= c2; j++) {
            if (i > 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
        }
    }

    int ans = 0;
    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            ans = (ans + dp[i][j]) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}