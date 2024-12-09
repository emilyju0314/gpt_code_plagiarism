#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m, n;

    while (cin >> m >> n) {
        if (m == 0 && n == 0) {
            break;
        }

        vector<int> volumes(n);
        for (int i = 0; i < n; i++) {
            cin >> volumes[i];
        }

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++) {
            dp[i + 1][1] = dp[i][1] + volumes[i];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 2; j <= m; j++) {
                int width = 0;
                int min_width = 1500000;
                for (int k = i; k >= 1; k--) {
                    width += volumes[k - 1];
                    min_width = min(min_width, max(dp[k][j - 1], width));
                }
                dp[i][j] = min_width;
            }
        }

        cout << dp[n][m] << endl;
    }

    return 0;
}