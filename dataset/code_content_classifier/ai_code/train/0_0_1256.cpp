#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<int> w(n);
    for(int i = 0; i < n; i++) {
        cin >> w[i];
    }
    
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for(int len = 2; len <= n; len++) {
        for(int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            for(int k = i + 1; k < j; k++) {
                if(w[k] == w[i] + 1 && w[k] == w[j] - 1) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + v[k]);
                }
            }
        }
    }
    
    int maxScore = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            maxScore = max(maxScore, dp[i][j]);
        }
    }
    
    cout << maxScore << endl;
    
    return 0;
}