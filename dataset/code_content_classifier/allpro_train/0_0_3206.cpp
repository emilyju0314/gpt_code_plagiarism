#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> dp(n+1, vector<int>(2*n+1, 0));
    dp[1][1] = 2;
    dp[1][2] = 2;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 2*i; j++) {
            dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
            if (j >= 2) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-2]) % MOD;
            }
        }
    }

    cout << dp[n][k] << endl;

    return 0;
}