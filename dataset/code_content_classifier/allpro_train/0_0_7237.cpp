#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(2, vector<int>(n));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(2, vector<int>(n + 1));

    for (int i = 1; i <= n; ++i) {
        if (grid[0][i - 1] == 0) dp[0][i] = dp[0][i - 1] + 1;
        else dp[0][i] = dp[0][i - 1];
    }

    for (int i = 1; i <= n; ++i) {
        if (grid[1][i - 1] == 0) dp[1][i] = dp[1][i - 1] + 1;
        else dp[1][i] = dp[1][i - 1];
    }

    for (int i = 1; i <= n; ++i) {
        dp[0][i] = max(dp[0][i], dp[1][i - 1] + 1);
        dp[1][i] = max(dp[1][i], dp[0][i - 1] + 1);
    }

    cout << dp[0][n] << endl;

    return 0;
}