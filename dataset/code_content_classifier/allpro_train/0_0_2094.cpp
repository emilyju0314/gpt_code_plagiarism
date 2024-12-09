#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int dp[1001][1001][1001];

int countWays(int n, int m, int k) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j][0] = 1;
        }
    }

    for(int move = 1; move <= k; move++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                dp[i][j][move] = 0;
                for(int x = 1; x < i; x++) {
                    dp[i][j][move] = (dp[i][j][move] + dp[x][j][move-1]) % MOD;
                }
                for(int y = 1; y < j; y++) {
                    dp[i][j][move] = (dp[i][j][move] + dp[i][y][move-1]) % MOD;
                }
            }
        }
    }

    return dp[n][m][k];
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    cout << countWays(n, m, k) << endl;

    return 0;
}