#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    dp[1][1] = m;

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % MOD;
        }
    }

    int ans = dp[n][m];
    for(int i = 0; i < k; i++) {
        ans = (ans * 1LL * (m-1)) % MOD;
    }

    cout << ans << endl;

    return 0;
}