#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    int k;
    cin >> k;

    long long dp[k+1][6];
    dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = dp[1][5] = 1;
    for(int i = 2; i <= k; i++) {
        dp[i][0] = (3 * dp[i-1][0] + 2 * dp[i-1][1] + 2 * dp[i-1][2] + 2 * dp[i-1][3] + 2 * dp[i-1][4] + 2 * dp[i-1][5]) % MOD;
        dp[i][1] = (2 * dp[i-1][0] + 2 * dp[i-1][1] + dp[i-1][2] + dp[i-1][5]) % MOD;
        dp[i][2] = (2 * dp[i-1][0] + dp[i-1][1] + 2 * dp[i-1][2] + 2 * dp[i-1][4]) % MOD;
        dp[i][3] = (2 * dp[i-1][0] + dp[i-1][2] + 2 * dp[i-1][3] + 2 * dp[i-1][5]) % MOD;
        dp[i][4] = (2 * dp[i-1][0] + 2 * dp[i-1][3] + dp[i-1][4] + dp[i-1][5]) % MOD;
        dp[i][5] = (dp[i-1][1] + dp[i-1][3] + dp[i-1][4] + 3 * dp[i-1][5]) % MOD;
    }

    cout << (dp[k][0] + dp[k][1] + dp[k][2] + dp[k][3] + dp[k][4] + dp[k][5]) % MOD << endl;

    return 0;
}