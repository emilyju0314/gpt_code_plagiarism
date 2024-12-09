#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a, n, m;
    cin >> a >> n >> m;

    vector<pair<int, int>> rain_segments;
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        rain_segments.push_back({l, r});
    }

    vector<pair<int, int>> umbrellas;
    for(int i = 0; i < m; i++) {
        int x, p;
        cin >> x >> p;
        umbrellas.push_back({x, p});
    }

    sort(umbrellas.begin(), umbrellas.end());

    vector<vector<int>> dp(a + 1, vector<int>(m + 1, 1e9));
    dp[0][0] = 0;

    for(int i = 1; i <= a; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = dp[i][j - 1];
            for(auto& segment : rain_segments) {
                if(segment.first <= i && i <= segment.second) {
                    dp[i][j] = min(dp[i][j], dp[segment.first][j - 1] + umbrellas[j - 1].second * (i - segment.first));
                }
            }
        }
    }

    int ans = 1e9;
    for(int j = 0; j <= m; j++) {
        ans = min(ans, dp[a][j]);
    }

    if(ans == 1e9) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}