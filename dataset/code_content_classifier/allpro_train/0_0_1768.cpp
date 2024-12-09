#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> t(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> t[i][j];
        }
    }

    int n;
    cin >> n;

    vector<vector<long long>> dp(3, vector<long long>(n + 1, LLONG_MAX));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            int from = (j + 1) % 3;
            int to = (j + 2) % 3;
            dp[j][i] = min(dp[j][i], dp[from][i - 1] + t[from][to] + dp[to][i - 1]);
            dp[j][i] = min(dp[j][i], dp[from][i - 1] + t[from][to] + dp[j][i - 1] + t[from][j] + dp[to][i - 1]);
            dp[j][i] = min(dp[j][i], dp[to][i - 1] + t[to][from] + dp[j][i - 1] + t[to][j] + dp[from][i - 1]);
        }
    }

    cout << dp[2][n] << endl;

    return 0;
}