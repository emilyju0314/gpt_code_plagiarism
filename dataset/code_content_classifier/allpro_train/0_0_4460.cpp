#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i-1][j] + j * dp[i-1][j-1]) % MOD;
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + dp[n][i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}