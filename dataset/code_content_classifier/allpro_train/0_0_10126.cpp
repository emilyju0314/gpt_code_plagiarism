#include <iostream>
using namespace std;

const int MOD = 1000000007;

int main() {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    int dp[101][1001][20001] = {0}; // Initialize dp table with 0
    dp[0][0][0] = 1;

    for (int i = 1; i <= c; i++) {
        for (int j = 0; j <= d; j++) {
            for (int k = 0; k <= e; k++) {
                for (int num = a; num <= b; num++) {
                    if (j >= 1 && num + k <= e) {
                        dp[i][j][k + num] = (dp[i][j][k + num] + dp[i - 1][j - 1][k]) % MOD;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = a; i <= b; i++) {
        ans = (ans + dp[c][d][e - i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}