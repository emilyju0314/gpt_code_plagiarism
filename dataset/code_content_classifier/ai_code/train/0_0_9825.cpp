#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> probabilities(n);
    
    for (int i = 0; i < n; i++) {
        cin >> probabilities[i];
    }
    
    vector<vector<double>> dp(n+1, vector<double>(k+1, 0));
    dp[0][0] = 1.0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            double p = probabilities[i-1] / 100.0;
            dp[i][j] += dp[i-1][j] * (1.0 - p);
            if (j > 0) {
                dp[i][j] += dp[i-1][j-1] * p;
            }
        }
    }
    
    int result = 0;
    for (int i = 0; i <= k; i++) {
        if (dp[n][i] > 0) {
            result++;
        }
    }
    
    cout << result << endl;
    
    return 0;
}