#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> glasses(n); // pair of capacity and current water amount
    for (int i = 0; i < n; i++) {
        cin >> glasses[i].first >> glasses[i].second;
    }

    vector<vector<double>> dp(n+1, vector<double>(10001, -1));
    dp[0][0] = 0;

    for (int k = 1; k <= n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 10000; j++) {
                if (dp[k-1][j] >= 0) {
                    dp[k][j + glasses[i].second] = max(dp[k][j + glasses[i].second], dp[k-1][j] + (double)glasses[i].second);
                    dp[k][j] = max(dp[k][j], dp[k-1][j]);
                    dp[k][j + glasses[i].second / 2] = max(dp[k][j + glasses[i].second / 2], dp[k-1][j] + (double)glasses[i].second / 2);
                }
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        double res = 0;
        for (int j = 0; j <= 10000; j++) {
            res = max(res, min((double)j, dp[k][j]));
        }
        cout << fixed << setprecision(9) << res << " ";
    }

    return 0;
}