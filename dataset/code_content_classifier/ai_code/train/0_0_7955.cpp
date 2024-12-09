#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        
        vector<vector<pair<int, int>>> stones(n, vector<pair<int, int>>());
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++) {
                int x, d;
                cin >> x >> d;
                stones[i].push_back({x, d});
            }
        }
        
        vector<vector<int>> dp(n, vector<int>(m+1, INT_MAX));
        dp[0][0] = 0;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= min(m, i); j++) {
                for (int k = 0; k < stones[i].size(); k++) {
                    for (int l = 0; l < stones[i-1].size(); l++) {
                        int risk = (stones[i][k].second + stones[i-1][l].second) * abs(stones[i][k].first - stones[i-1][l].first);
                        if (j > 0) {
                            dp[i][j] = min(dp[i][j], dp[i-1][j-1] + risk);
                        }
                        dp[i][j] = min(dp[i][j], dp[i-1][j] + risk);
                    }
                }
            }
        }
        
        int minRisk = INT_MAX;
        for (int i = 0; i <= m; i++) {
            minRisk = min(minRisk, dp[n-1][i]);
        }
        
        cout << minRisk << endl;
    }
    
    return 0;
}