#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m && n != 0 && m != 0) {
        vector<vector<int>> dp(n, vector<int>(n, numeric_limits<int>::max()));
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = 0;
        }
        
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            dp[a - 1][b - 1] = c;
        }
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
        
        cout << dp[0][n - 1] << endl;
    }
    
    return 0;
}