#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 998244353;
const int MAXN = 505;

int dp[MAXN][MAXN][MAXN]; // dp[i][j][k] represents the number of ways to choose the initial health points for heroes 1 to i, with total health j and k heroes alive

int main() {
    int n, x;
    cin >> n >> x;

    memset(dp, 0, sizeof(dp));

    dp[0][0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            for (int k = 1; k <= i; k++) {
                for (int l = 1; l <= x; l++) {
                    dp[i][j][k] = (dp[i][j][k] + 1LL * (i - 1) * dp[i - 1][j - l][k - 1] % MOD) % MOD;
                }
            }
        }
    }

    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = 1LL * ans * x % MOD;
    }

    ans = (ans - dp[n][x][n] + MOD) % MOD;

    cout << ans << endl;

    return 0;
}