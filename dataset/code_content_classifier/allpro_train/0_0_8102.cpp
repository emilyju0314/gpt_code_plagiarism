#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    vector<int> sum(n+1, 0);
    for(int i = 1; i <= n; i++) {
        sum[i] = sum[i-1] + arr[i-1];
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            dp[i][j] = dp[i-1][j];
            for(int l = 1; l <= i; l++) {
                dp[i][j] = max(dp[i][j], dp[i-l][j-1] + sum[i] - sum[i-l]);
            }
        }
    }
    
    cout << dp[n][k] << endl;
    
    return 0;
}