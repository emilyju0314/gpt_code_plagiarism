#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, k, p;
    cin >> n >> m >> k >> p;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, 0)));
    dp[0][0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int l = 0; l <= k; l++) {
                for (int x = 0; x <= min(j, l); x++) {
                    dp[i][j][l] = (dp[i][j][l] + dp[i-1][j-x][l]) % p;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= k; i++) {
        ans = (ans + dp[n][m][i]) % p;
    }

    cout << ans << endl;

    return 0;
}