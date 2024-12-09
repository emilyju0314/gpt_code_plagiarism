#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> aggressiveness(n);
    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        cin >> aggressiveness[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    vector<int> profitability(n + m + 1);
    for (int i = 1; i <= n + m; i++) {
        cin >> profitability[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            int total_profit = 0;
            int max_agg = 0;
            for (int k = i - 1; k >= 0; k--) {
                if (aggressiveness[k] <= j) {
                    total_profit += profitability[aggressiveness[k]];
                    if (max_agg >= aggressiveness[k]) {
                        total_profit -= profitability[max_agg];
                        max_agg++;
                    } else {
                        max_agg = aggressiveness[k] + 1;
                    }
                    dp[i][j] = max(dp[i][j], dp[k][j - aggressiveness[k]] + total_profit - cost[k]);
                }
            }
        }
    }

    int max_profit = 0;
    for (int j = 0; j <= m; j++) {
        max_profit = max(max_profit, dp[n][j]);
    }

    cout << max_profit << endl;

    return 0;
}