#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int r, b;
    cin >> r >> b;

    // Store shields' coordinates
    vector<pair<int, int>> shields(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        shields[i] = make_pair(x, y);
    }

    // Store shields counts for each x and y coordinate
    map<int, map<int, int>> x_counts, y_counts;
    for (auto& shield : shields) {
        x_counts[shield.first][shield.second]++;
        y_counts[shield.second][shield.first]++;
    }

    // Dynamic programming to iterate through all possible ways of assigning reds and blues
    vector<vector<long long>> dp(n + 1, vector<long long>(2, 1e18));
    dp[0][0] = dp[0][1] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            int x = shields[i].first, y = shields[i].second;
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + r + j * b);
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + b + j * r);

            if (j == 0) {
                dp[i + 1][0] += x_counts[x][y] * 1LL * b;
                dp[i + 1][1] += x_counts[x][y] * 1LL * r;
                dp[i + 1][0] += y_counts[y][x] * 1LL * b;
                dp[i + 1][1] += y_counts[y][x] * 1LL * r;
            }
        }
    }

    // Output the result
    long long ans = min(dp[n][0], dp[n][1]);
    if (ans >= 1e18) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
        string result;
        for(int i=n; i>0; i--){
            int flag = 0;
            if(dp[i][1] + r + b == dp[i+1][1]) flag = 1;
            result = (flag == 1 ? 'r' : 'b' ) + result;
        }

        cout << result << endl;
    }

    return 0;
}