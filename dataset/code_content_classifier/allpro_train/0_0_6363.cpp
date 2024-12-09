#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minBreakCost(int n, int m, int k) {
    // Initialize dp table to store minimum cost to eat k squares
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, 0)));
    
    // Fill dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int s = 1; s <= k; s++) {
                // Initialize minimum cost to a large value
                dp[i][j][s] = 1e9;
                
                // Base case: If k equals the number of squares in the chocolate bar, cost is 0
                if (s == i * j) {
                    dp[i][j][s] = 0;
                    continue;
                }
                
                // Iterate over all possible positions to split the chocolate bar
                for (int x = 1; x < i; x++) {
                    for (int s1 = 0; s1 <= s; s1++) {
                        dp[i][j][s] = min(dp[i][j][s], x * x + dp[x][j][s1] + dp[i - x][j][s - s1]);
                    }
                }
                
                for (int y = 1; y < j; y++) {
                    for (int s1 = 0; s1 <= s; s1++) {
                        dp[i][j][s] = min(dp[i][j][s], y * y + dp[i][y][s1] + dp[i][j - y][s - s1]);
                    }
                }
            }
        }
    }
    
    return dp[n][m][k];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        cout << minBreakCost(n, m, k) << endl;
    }

    return 0;
}