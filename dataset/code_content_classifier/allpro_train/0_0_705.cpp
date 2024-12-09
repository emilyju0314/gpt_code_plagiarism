#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> l(n), s(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<int> c(n + m + 1);
    for (int i = 1; i <= n + m; i++) {
        cin >> c[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        dp[i][1] = c[l[i - 1]] - s[i - 1];
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + c[l[i - 1]] - s[i - 1];
            int max_diff = 0;
            for (int k = i - 1; k >= 1; k--) {
                if (l[i - 1] > l[k - 1]) {
                    max_diff = max(max_diff, dp[k][j - 1]);
                }
            }
            dp[i][j] = max(dp[i][j], max_diff + c[l[i - 1]] - s[i - 1]);
        }
    }

    int max_profit = 0;
    for (int i = 1; i <= n; i++) {
        max_profit = max(max_profit, dp[n][i]);
    }

    cout << max_profit << endl;

    return 0;
}