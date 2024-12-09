#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<int> bonus(4, 0); // Array to store the bonus values for each color
    bonus[1] = x;
    bonus[2] = x;
    bonus[3] = x;

    vector<int> penalty(4, 0); // Array to store the penalty values for each color
    penalty[1] = -y;
    penalty[2] = -y;
    penalty[3] = -y;

    vector<vector<pair<int, pair<int, int>>>> robots(4); // Array to store the robots and their targets

    for (int i = 0; i < m; i++) {
        int c, l, r;
        cin >> c >> l >> r;
        robots[c].push_back({l, {r, r-l+1}});
    }

    for (int i = 1; i <= 3; i++) {
        sort(robots[i].begin(), robots[i].end());
    }

    vector<vector<long long>> dp(4, vector<long long>(n+1, 0)); // Array to store the maximum aesthetic value

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

            for (auto robot : robots[i]) {
                int l = robot.first;
                int r = robot.second.first;
                int target = robot.second.second;
                if (j >= l && j <= r) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-target] + target*b[i] + pb[i]);
                } else if (j > r) {
                    dp[i][j] = max(dp[i][j], dp[i][j-1]);
                }
            }
        }
    }

    cout << max({dp[1][n], dp[2][n], dp[3][n]}) << endl;

    return 0;
}