#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    
    while (cin >> n && n != 0) {
        vector<pair<int, int>> islands(n);
        
        for (int i = 0; i < n; i++) {
            cin >> islands[i].first >> islands[i].second;
        }
        
        vector<vector<long long>> dp(n, vector<long long>(n, LLONG_MAX));
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = 0;
        }
        
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i+1; j < n; j++) {
                dp[i][j] = dp[i][j-1] + abs(islands[j].first - islands[j-1].first);
                cnt++;
                if (cnt == islands[i].second) {
                    break;
                }
            }
        }
        
        vector<long long> min_cost(n, LLONG_MAX);
        min_cost[0] = 0;
        
        for (int j = 1; j < n; j++) {
            for (int i = 0; i < j; i++) {
                if (dp[i][j] != LLONG_MAX) {
                    min_cost[j] = min(min_cost[j], min_cost[i] + dp[i][j]);
                }
            }
        }
        
        if (min_cost[n-1] == LLONG_MAX) {
            cout << -1 << endl;
        } else {
            cout << min_cost[n-1] << endl;
        }
    }
    
    return 0;
}