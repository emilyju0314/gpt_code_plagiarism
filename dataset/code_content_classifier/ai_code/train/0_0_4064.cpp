#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<double>> prob(m, vector<double>(n));
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> prob[i][j];
        }
    }

    vector<double> dp(1 << m, 0.0);
    dp[0] = 1.0;

    for(int mask = 0; mask < (1 << m); mask++) {
        int cnt = __builtin_popcount(mask);
        
        for(int i = 0; i < m; i++) {
            if((mask & (1 << i)) == 0) {
                double prob_i = 1.0; // Probability of cat i defeating enemies
                
                for(int j = 0; j < n; j++) {
                    if(mask & (1 << j)) {
                        prob_i *= prob[i][j];
                    }
                }

                dp[mask | (1 << i)] = max(dp[mask | (1 << i)], dp[mask] * prob_i);
            }
        }
    }

    cout << fixed << setprecision(10) << dp[(1 << m) - 1] << endl;

    return 0;
}