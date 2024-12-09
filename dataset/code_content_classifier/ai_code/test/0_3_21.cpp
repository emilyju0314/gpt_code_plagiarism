#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 105;
const int MAXK = 105;

int dp[MAXN][MAXK][MAXN];
int n, m, k, p;

int main() {
    cin >> n >> m >> k >> p;

    // Initialize base cases
    for (int i = 1; i <= n; i++) {
        dp[1][i][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int l = 1; l <= n; l++) {
                for (int last = l; last <= n; last++) {
                    dp[i][j][last] = (dp[i][j][last] + dp[i - 1][j][l]) % p;
                    if (l != last && j - 1 >= 0) {
                        dp[i][j][last] = (dp[i][j][last] + dp[i - 1][j - 1][l]) % p;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + dp[n][k][i]) % p;
    }

    cout << ans << endl;

    return 0;
}