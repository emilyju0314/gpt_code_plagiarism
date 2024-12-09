#include <iostream>
#include <vector>

using namespace std;

int maxProfit(int n, int k, vector<int>& prices) {
    if(n <= 1) {
        return 0;
    }
    
    vector<vector<int>> dp(k+1, vector<int>(n, 0));
    
    for(int i = 1; i <= k; i++) {
        int maxDiff = -prices[0];
        
        for(int j = 1; j < n; j++) {
            dp[i][j] = max(dp[i][j-1], prices[j] + maxDiff);
            maxDiff = max(maxDiff, dp[i-1][j] - prices[j]);
        }
    }
    
    return dp[k][n-1];
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> prices(n);

    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    int result = maxProfit(n, k, prices);
    cout << result << endl;

    return 0;
}