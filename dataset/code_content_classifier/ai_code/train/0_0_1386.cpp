#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> satisfaction(n);
    vector<int> satisfactionLevel2(n);
    vector<int> satisfactionLevel1(n);

    for (int i = 0; i < n; i++) {
        cin >> satisfactionLevel2[i] >> satisfactionLevel1[i] >> satisfaction[i];
    }

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(9, -1)));

    dp[0][m][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= 8; k++) {
                if (dp[i][j][k] == -1) continue;

                // Do not shake any psyllium
                dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j][k] + satisfaction[i]);

                // Shake one level 1 psyllium
                if (j > 0) {
                    dp[i+1][j-1][1] = max(dp[i+1][j-1][1], dp[i][j][k] + satisfaction[i] + satisfactionLevel1[i]);
                }

                // Shake one level 2 psyllium
                if (k < 8) {
                    dp[i+1][j][k+1] = max(dp[i+1][j][k+1], dp[i][j][k] + satisfaction[i] + satisfactionLevel2[i]);
                }
            }
        }
    }

    int maxSatisfaction = 0;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= 8; j++) {
            maxSatisfaction = max(maxSatisfaction, dp[n][i][j]);
        }
    }

    cout << maxSatisfaction << endl;

    return 0;
}