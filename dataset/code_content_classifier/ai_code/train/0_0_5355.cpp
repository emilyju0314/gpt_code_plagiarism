#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        
        vector<vector<double>> growth(n, vector<double>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> growth[i][j];
            }
        }
        
        vector<vector<double>> dp(m + 1, vector<double>(n, 0.0));
        dp[0][0] = 1.0; // Initial size is 1
        
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    dp[i][j] = max(dp[i][j], dp[i-1][k] * growth[k][j]);
                }
            }
        }
        
        double max_size = 0.0;
        for (int i = 0; i < n; i++) {
            max_size = max(max_size, dp[m][i]);
        }
        
        cout << fixed << setprecision(2) << max_size << endl;
    }
    
    return 0;
}