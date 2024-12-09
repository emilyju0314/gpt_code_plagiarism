#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n;
    
    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    
    cin >> q;
    
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        
        int maxAmount = 0;
        for (int j = r; j >= l; j--) {
            for (int k = j; k <= r; k++) {
                maxAmount = max(maxAmount, dp[j][k]);
                dp[j][k] = max(dp[j][k], dp[j][k] ^ cost[j]);
            }
        }
        
        cout << maxAmount << endl;
    }
    
    return 0;
}