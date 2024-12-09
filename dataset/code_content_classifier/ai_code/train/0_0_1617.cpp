#include <iostream>
#include <vector>
#include <cmath>

#define MOD 1000000007

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> direct(n, vector<int>(n));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> direct[i][j];
        }
    }
    
    vector<vector<long long>> dp(n, vector<long long>(n));
    
    for(int i = 1; i < n; i += 2) {
        dp[i][i - 1] = dp[i - 1][i] = 1;
    }
    
    for(int len = 2; len < n; len++) {
        for(int i = 0; i + len < n; i++) {
            int j = i + len;
            for(int k = i + 1; k < j; k++) {
                if(direct[i][j] == 0) {
                    dp[i][j] += dp[i][k] * dp[k][j];
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    
    cout << dp[0][n - 1] << endl;
    
    return 0;
}