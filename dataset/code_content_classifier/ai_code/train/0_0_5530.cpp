#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<int>> dp(H, vector<int>(W, INF));
    vector<string> grid(H);
    for (int i = 0; i < H; i++) {
        cin >> grid[i];
    }

    dp[0][0] = 0;
    int ans = INF;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i > 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            }
            if (j > 0) {
                dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            }

            if (grid[i][j] == '.') continue;
            int cost = grid[i][j] - '0';
            for (int s = i + 1; s < H; s++) {
                if (grid[s][j] == '.') continue;
                for (int t = j + 1; t < W; t++) {
                    if (grid[i][t] == '.' or grid[s][t] == '.') continue;
                    int new_cost = cost + grid[s][j] + grid[i][t] + grid[s][t] - 4*'0';
                    dp[s][t] = min(dp[s][t], dp[i][j] + new_cost);
                    if (s == H - 1 && t == W - 1) {
                        ans = min(ans, dp[s][t]);
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}