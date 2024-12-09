#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<long long>> dp(n+1, vector<long long>(m+1));

    for (int i = 0; i <= m; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }

    long long ans = 0;
    for (int i = 2; i <= m; i++) {
        ans = (ans + dp[n][i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}