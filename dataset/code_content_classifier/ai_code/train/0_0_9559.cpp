#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> heights(n);
    
    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int len = 2; len <= n; len++) {
        for(int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            dp[i][j] = min(dp[i+1][j] + (heights[i] > heights[i+1] ? 1 : 0), dp[i][j-1] + (heights[j] < heights[j-1] ? 1 : 0));
            
            if(heights[i] < heights[j]) {
                dp[i][j] = min(dp[i][j], dp[i+1][j-1] + (heights[i] > heights[j-1] ? 1 : 0));
            }
        }
    }
    
    cout << dp[0][n-1] << endl;
    
    return 0;
}