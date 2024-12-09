#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m, k, s;
    cin >> n >> m >> k >> s;

    vector<vector<bool>> isAnomaly(n+1, vector<bool>(m+1, false));
    for(int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        isAnomaly[r][c] = true;
    }

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    dp[1][1] = s;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(i == 1 && j == 1) continue;
            if(isAnomaly[i][j]) {
                dp[i][j] = (dp[i-1][j] / 2 + dp[i][j-1] / 2) % MOD;
            } else {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])  % MOD;
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}