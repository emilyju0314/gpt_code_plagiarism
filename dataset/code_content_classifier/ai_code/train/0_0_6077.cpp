#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<long long>> grid(n, vector<long long>(m));
        vector<vector<long long>> dp(n, vector<long long>(m, LLONG_MAX));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        dp[0][0] = grid[0][0];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i + 1 < n && grid[i+1][j] >= grid[i][j]) {
                    dp[i+1][j] = min(dp[i+1][j], dp[i][j] + grid[i+1][j]);
                }
                if(j + 1 < m && grid[i][j+1] >= grid[i][j]) {
                    dp[i][j+1] = min(dp[i][j+1], dp[i][j] + grid[i][j+1]);
                }
            }
        }

        cout << dp[n-1][m-1] << endl;
    }

    return 0;
}