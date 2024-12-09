#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 998244353;
const int MAXN = 1000005;

int dp[MAXN][2];

int main() {
    int n;
    cin >> n;

    memset(dp, 0, sizeof(dp));

    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % MOD;
        dp[i][1] = dp[i-1][0];
    }

    cout << dp[n][0] << endl;

    return 0;
}