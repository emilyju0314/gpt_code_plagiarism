#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(105, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= a[i-1]; j++) {
            dp[i][j] = dp[i-1][j];
        }
        for (int j = 1; j <= a[i-1]; j++) {
            for (int k = 2*j; k <= a[i-1]; k += j) {
                dp[i][k] = (dp[i][k] + dp[i-1][j]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= a[n-1]; i++) {
        ans = (ans + dp[n][i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}