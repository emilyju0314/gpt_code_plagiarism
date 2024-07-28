#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 1e9;

int main() {
    int n;
    while (cin >> n) {
        vector<pair<int, int>> intervals(n);
        vector<int> sorted_endpoints;
        for (int i = 0; i < n; i++) {
            cin >> intervals[i].first >> intervals[i].second;
            sorted_endpoints.push_back(intervals[i].first);
            sorted_endpoints.push_back(intervals[i].second);
        }

        sort(sorted_endpoints.begin(), sorted_endpoints.end());
        sorted_endpoints.erase(unique(sorted_endpoints.begin(), sorted_endpoints.end()), sorted_endpoints.end());

        int m = sorted_endpoints.size();
        vector<vector<int>> dp(2, vector<int>(m, INF));
        dp[0][0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[1][j] = min(dp[1][j], dp[0][j] + abs(intervals[i].second - sorted_endpoints[j]));
                if (j > 0) {
                    dp[1][j] = min(dp[1][j], dp[1][j - 1]);
                }
                if (j + 1 < m) {
                    dp[1][j] = min(dp[1][j], dp[0][j + 1]);
                }
            }
            dp[0] = dp[1];
        }

        cout << dp[0][0] << endl;
    }

    return 0;
}