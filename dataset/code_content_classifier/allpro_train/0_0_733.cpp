#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> satisfaction(n);
    for (int i = 0; i < n; i++) {
        cin >> satisfaction[i];
    }

    vector<vector<int>> rules(n, vector<int>(n, 0));
    for (int i = 0; i < k; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        rules[x - 1][y - 1] = c;
    }

    vector<vector<int>> dp(1 << n, vector<int>(n, 0));

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) continue;

            if (__builtin_popcount(mask) == 1) {
                dp[mask][i] = satisfaction[i];
            } else {
                for (int j = 0; j < n; j++) {
                    if (mask & (1 << j) && j != i) {
                        dp[mask][i] = max(dp[mask][i], dp[mask ^ (1 << i)][j] + satisfaction[i] + rules[j][i]);
                    }
                }
            }
        }
    }

    int max_satisfaction = 0;
    for (int i = 0; i < n; i++) {
        max_satisfaction = max(max_satisfaction, dp[(1 << n) - 1][i]);
    }

    cout << max_satisfaction << endl;

    return 0;
}