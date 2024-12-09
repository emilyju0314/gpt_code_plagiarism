#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, k, p;
    cin >> N >> k >> p;
    
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    vector<vector<int>> dp(k + 1, vector<int>(N + 1, 0));
    vector<int> prefix_sum(N + 1, 0);
    
    for (int i = 1; i <= N; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + A[i - 1];
    }
    
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = 1e9;
            for (int x = 0; x < j; x++) {
                dp[i][j] = min(dp[i][j], max(dp[i - 1][x], prefix_sum[j] - prefix_sum[x]) % p);
            }
        }
    }
    
    cout << dp[k][N] << endl;
    
    return 0;
}