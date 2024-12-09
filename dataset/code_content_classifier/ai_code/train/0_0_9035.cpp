#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    vector<vector<int>> dp(n, vector<int>(n, 2));
    int ans = 2;
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            dp[i][j] = 2;
            for(int k = 0; k < i; k++) {
                if(b[k] == b[i] + (b[j] - b[i]) * (i - k)) {
                    dp[i][j] = max(dp[i][j], dp[k][i] + 1);
                }
            }
            ans = max(ans, dp[i][j]);
        }
    }
    
    cout << ans << endl;
    
    return 0;
}