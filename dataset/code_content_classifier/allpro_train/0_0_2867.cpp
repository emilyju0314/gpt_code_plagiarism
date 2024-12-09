#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> castles(n, vector<int>(3));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> castles[i][j];
        }
    }

    vector<vector<int>> portals(m, vector<int>(2));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> portals[i][j];
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(5001, -1e9));
    dp[0][k] = 0;

    for (int i = 0; i < n; i++) {
        for (int w = 0; w <= min(k + accumulate(castles[i].begin(), castles[i].end(), 0), 5000); w++) {
            if (dp[i][w] < 0) continue;

            if (w >= castles[i][0]) {
                dp[i + 1][w - castles[i][0] + castles[i][1]] = max(dp[i + 1][w - castles[i][0] + castles[i][1]], dp[i][w] + castles[i][2]);
            }

            dp[i + 1][w] = max(dp[i + 1][w], dp[i][w]);

            for (int j = 0; j < m; j++) {
                if (portals[j][0] == i + 1 && w >= 1) {
                    dp[portals[j][1]][w - 1] = max(dp[portals[j][1]][w - 1], dp[i][w]);
                }
            }
        }
    }

    int max_score = 0;
    for (int w = 0; w <= 5000; w++) {
        max_score = max(max_score, dp[n][w]);
    }

    if (max_score < 0) {
        cout << -1 << endl;
    } else {
        cout << max_score << endl;
    }

    return 0;
}