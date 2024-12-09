#include <iostream>

using namespace std;

const int MOD = 1000000007;

int main() {
    int k;
    cin >> k;

    long long dp[k + 1][6];
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < 6; j++) {
            dp[i][j] = 0;
        }
    }

    dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = dp[1][5] = 1;

    for (int i = 2; i <= k; i++) {
        dp[i][0] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][4] + dp[i-1][5]) % MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2] + dp[i-1][3] + dp[i-1][5]) % MOD;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][3] + dp[i-1][4]) % MOD;
        dp[i][3] = (dp[i-1][1] + dp[i-1][2] + dp[i-1][4] + dp[i-1][5]) % MOD;
        dp[i][4] = (dp[i-1][0] + dp[i-1][2] + dp[i-1][3] + dp[i-1][5]) % MOD;
        dp[i][5] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][3] + dp[i-1][4]) % MOD;
    }

    long long result = 0;
    for (int i = 0; i < 6; i++) {
        result = (result + dp[k][i]) % MOD;
    }

    cout << result << endl;

    return 0;
}