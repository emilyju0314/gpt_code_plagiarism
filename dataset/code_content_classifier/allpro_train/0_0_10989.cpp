#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    
    while (cin >> n && n != 0) {
        vector<int> prices(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> prices[i];
        }
        
        vector<vector<int>> dp(n+1, vector<int>(5001, INT_MAX));
        dp[0][0] = 0;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 5000; j++) {
                dp[i][j] = dp[i-1][j];
                
                int cnt_500 = prices[i] / 500;
                int rem = prices[i] % 500;
                
                for (int k = 0; k <= cnt_500; k++) {
                    if (j >= k*500) {
                        dp[i][j] = min(dp[i][j], dp[i-1][j-k*500] + (cnt_500 - k + 1) * 500);
                    }
                }
                if (rem != 0 && j >= rem) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-rem] + rem);
                }
            }
        }
        
        int max_coins = 0;
        int min_expenses = INT_MAX;
        for (int j = 0; j <= 5000; j++) {
            if (dp[n][j] < min_expenses) {
                min_expenses = dp[n][j];
                max_coins = j / 500;
            }
        }
        
        cout << max_coins << " " << min_expenses << endl;
    }
    
    return 0;
}