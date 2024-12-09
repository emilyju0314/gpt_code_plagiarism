#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
    
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            if (row[j] >= '0' && row[j] <= '9') {
                grid[i][j] = row[j] - '0';
            }
        }
    }

    dp[0][0] = grid[0][0]; // Initialisation

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i > 0) { // Move up
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            }
            if (j > 0) { // Move left
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
            }
            
            if (grid[i][j] != 0 && dp[i][j] != INT_MIN) {
                dp[i][j] += grid[i][j];
            }
        }
    }

    cout << dp[n-1][m-1] << endl;

    return 0;
}