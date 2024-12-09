#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findChainLength(vector<pair<int, int>>& strings) {
    int n = strings.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l < n - len + 1; l++) {
            int r = l + len - 1;
            for (int k = l + 1; k <= r - 1; k++) {
                dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r] + (strings[l].second == strings[r].first));
            }
        }
    }
    
    return dp[0][n - 1];
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<pair<int, int>> strings(n);
        for (int i = 0; i < n; i++) {
            cin >> strings[i].first >> strings[i].second;
        }
        
        cout << findChainLength(strings) << endl;
    }
    
    return 0;
}