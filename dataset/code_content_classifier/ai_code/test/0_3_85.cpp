#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, M;
    cin >> n >> M;

    vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));
    dp[0][1] = 1;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            for (int j = i + 1; j > 0; j--) {
                dp[i][j] = (2 * dp[i][j + 2] + dp[i - 1][j]) % M;
            }
        } else {
            for (int j = 2; j <= i + 1; j++) {
                dp[i][j] = (dp[i][j - 2] + dp[i - 1][j - 1]) % M;
            }
        }
    }

    int ans = 0;
    for (int j = 1; j <= n + 1; j++) {
        ans = (ans + dp[n - 1][j]) % M;
    }

    cout << ans << endl;

    return 0;
}