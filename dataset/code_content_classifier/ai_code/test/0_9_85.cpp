#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, M;
    cin >> n >> M;

    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = 1; k <= j; k++) {
                dp[i][j] += dp[i - j][k];
                dp[i][j] %= M;
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[n][i];
        ans %= M;
    }

    cout << ans << endl;

    return 0;
}