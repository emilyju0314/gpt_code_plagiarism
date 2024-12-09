#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int s, d, m;
    while (cin >> s >> d >> m) {
        vector<vector<int>> dp(d + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= d; i++) {
            int k;
            cin >> k;
            vector<int> weight(k), price(k);
            for (int j = 0; j < k; j++) {
                cin >> weight[j] >> price[j];
            }
            
            for (int j = 0; j <= m; j++) {
                for (int l = 0; l < (1 << k); l++) {
                    int total_weight = 0, total_price = 0;
                    for (int idx = 0; idx < k; idx++) {
                        if ((l & (1 << idx)) != 0) {
                            total_weight += weight[idx];
                            total_price += price[idx];
                        }
                    }
                    
                    if (j >= total_price) {
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - total_price] + total_weight);
                    }
                }
            }
        }
        
        int max_weight = 0, min_price = INT_MAX;
        for (int i = 0; i <= m; i++) {
            max_weight = max(max_weight, dp[d][i]);
        }
        
        for (int i = 0; i <= m; i++) {
            if (dp[d][i] == max_weight) {
                min_price = min(min_price, i);
            }
        }
        
        cout << max_weight << " " << min_price << endl;
    }
    
    return 0;
}