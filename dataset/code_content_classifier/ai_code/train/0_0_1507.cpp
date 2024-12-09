#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }
    
    int m;
    cin >> m;
    
    vector<int> dp(21, 0);
    
    for (int i = 0; i < m; i++) {
        int type, l, r, k;
        cin >> type >> l >> r >> k;
        
        if (type == 0) {
            sequence[l-1] = r;
        } else {
            vector<vector<int>> dp2(k+1, vector<int>(r-l+1, 0));
            
            for (int i = 1; i <= k; i++) {
                int maxDP = 0;
                for (int j = 0; j <= r-l; j++) {
                    maxDP = max(maxDP, dp[i-1] + max(0, sequence[l+j]));
                    dp2[i][j] = max(dp2[i][j], max(dp2[i][j], maxDP));
                    if (j > 0) {
                        dp2[i][j] = max(dp2[i][j], dp2[i][j-1]);
                    }
                }
            }
            
            dp.swap(dp2[k]);
            
            cout << dp[k] << endl;
        }
    }
    
    return 0;
}