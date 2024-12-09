#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> grass(n);
    for(int i = 0; i < n; i++) {
        cin >> grass[i];
    }
    
    vector<pair<int, int>> cows(m);
    for(int i = 0; i < m; i++) {
        cin >> cows[i].first >> cows[i].second;
    }
    
    int maxSleeping = 0;
    int ways = 1;
    
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    dp[0][0] = 1;
    
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            dp[i][j] = dp[i-1][j];
            if(j >= cows[i-1].first) {
                dp[i][j] += dp[i-1][j - cows[i-1].first];
                dp[i][j] %= MOD;
            }
        }
    }
    
    for(int i = 0; i <= n; i++) {
        int currSleeping = 0;
        for(int j = 1; j <= m; j++) {
            if(i + cows[j-1].second <= grass.size() && grass[i + cows[j-1].second - 1] == cows[j-1].first) {
                currSleeping++;
            }
        }
        if(currSleeping > maxSleeping) {
            maxSleeping = currSleeping;
            ways = dp[m][i];
        } else if(currSleeping == maxSleeping) {
            ways += dp[m][i];
            ways %= MOD;
        }
    }
    
    cout << maxSleeping << " " << ways << endl;
    
    return 0;
}