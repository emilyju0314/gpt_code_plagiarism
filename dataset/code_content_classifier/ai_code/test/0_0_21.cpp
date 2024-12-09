#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 105;
const int MOD = 1000000007;

int dp[MAXN][MAXN];

int solve(int n, int m, int k, int p) {
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = 0;
            for (int x = 1; x <= min(m, i); x++) {
                for (int y = 0; y <= j; y++) {
                    dp[i][j] = (dp[i][j] + dp[i - x][y]) % p;
                }
            }
        }
    }
    return (dp[n][k] - dp[n][k - 1] + p) % p;
}

int main() {
    int n, m, k, p;
    cin >> n >> m >> k >> p;

    cout << solve(n, m, k, p) << endl;

    return 0;
}