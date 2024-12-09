#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n+1, vector<int>(m, 0));
    for(int j = 0; j < m; j++) {
        dp[1][j] = 1;
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < m; k++) {
                if((k + j) % m < j) {
                    dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
                }
            }
        }
    }

    int ans = 0;
    for(int j = 0; j < m; j++) {
        ans = (ans + dp[n][j]) % MOD;
    }

    cout << ans << endl;

    return 0;
}