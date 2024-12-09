#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, M;
    cin >> n >> M;
    
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 1;
    }
    
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            for (int k = i; k <= j; k++) {
                if (k == i) {
                    dp[i][j] = (dp[i][j] + dp[k+1][j]) % M;
                } else if (k == j) {
                    dp[i][j] = (dp[i][j] + dp[i][k-1]) % M;
                } else {
                    dp[i][j] = (dp[i][j] + 1LL * dp[i][k-1] * dp[k+1][j] % M) % M;
                }
            }
        }
    }
    
    cout << dp[1][n] << endl;
    
    return 0;
}