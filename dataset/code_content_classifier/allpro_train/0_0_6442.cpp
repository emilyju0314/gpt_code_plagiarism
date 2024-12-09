#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        dp[1][i] = 1;
    }

    for (int len = 2; len <= k; len++) {
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                dp[len][j] += dp[len - 1][i];
                dp[len][j] %= MOD;
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[k][i];
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}