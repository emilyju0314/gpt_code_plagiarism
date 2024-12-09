#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    vector<vector<long long>> dp(a + 1, vector<long long>(b + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            if (i > 0) {
                dp[i][j] = (dp[i][j] + dp[i-1][j] * (c + j)) % MOD;
            }
            if (j > 0) {
                dp[i][j] = (dp[i][j] + dp[i][j-1] * (c + i)) % MOD;
            }
            if (i > 0 && j > 0) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-1] * (c + i-1) * (c + j-1)) % MOD;
            }
        }
    }

    cout << dp[a][b] << endl;

    return 0;
}