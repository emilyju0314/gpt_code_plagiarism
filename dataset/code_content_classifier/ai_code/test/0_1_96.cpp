#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int n, x;
    cin >> n >> x;

    vector<vector<long long>> dp(n + 1, vector<long long>(x + 1));
    dp[1][1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            for (int k = 1; k < j; k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }

    long long ans = 0;
    for (int j = 1; j <= x; j++) {
        ans = (ans + dp[n][j]) % MOD;
    }

    cout << ans << endl;

    return 0;
}