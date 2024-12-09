#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> initialColors(n);
    for (int i = 0; i < n; i++) {
        cin >> initialColors[i];
    }

    vector<vector<int>> paintRequired(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> paintRequired[i][j];
        }
    }

    vector<vector<int>> dp(n+1, vector<int>(k+1, INT_MAX));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int color = 1; color <= m; color++) {
                int paint = paintRequired[i-1][color-1];
                if (initialColors[i-1] != 0 && initialColors[i-1] != color) {
                    continue;
                }
                if (j > 0) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + paint);
                }
            }
        }
    }

    int result = INT_MAX;
    for (int i = 0; i <= k; i++) {
        result = min(result, dp[n][i]);
    }

    if (result == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}