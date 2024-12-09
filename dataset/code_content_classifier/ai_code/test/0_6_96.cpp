#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int n, x;
    cin >> n >> x;

    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));

    dp[1][1] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            for (int k = 2; k <= x; k++) {
                dp[i][j] = (dp[i][j] + dp[i-1][j/k]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int j = 1; j <= x; j++) {
        ans = (ans + dp[n][j]) % MOD;
    }

    cout << ans << endl;

    return 0;
}