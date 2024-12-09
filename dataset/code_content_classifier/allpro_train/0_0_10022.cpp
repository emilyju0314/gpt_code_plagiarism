#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> cards(3*N);
    for(int i = 0; i < 3*N; i++) {
        cin >> cards[i];
    }
    
    vector<int> prefixSum(3*N+1, 0);
    for(int i = 0; i < 3*N; i++) {
        prefixSum[i+1] = prefixSum[i] + cards[i];
    }
    
    vector<vector<int>> dp(3*N+1, vector<int>(3*N/2+1, 0));
    
    for(int i = 1; i <= 3*N; i++) {
        for(int j = 1; j <= min(i, 3*N/2); j++) {
            dp[i][j] = dp[i-1][j];
            for(int k = 1; k <= min(j, 3); k++) {
                dp[i][j] = max(dp[i][j], dp[i-k][j-k] + (prefixSum[i] - prefixSum[i-k]));
            }
        }
    }
    
    cout << dp[3*N][N] << endl;
    
    return 0;
}