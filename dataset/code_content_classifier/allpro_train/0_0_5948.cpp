#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, T;
    cin >> N >> T;
    
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    
    vector<vector<int>> dp(N+1, vector<int>(T+1, 0));
    
    for (int i = 0; i < N; i++) {
        for (int t = 0; t <= T; t++) {
            dp[i+1][t] = max(dp[i+1][t], dp[i][t]);
            if (t + A[i] <= T) {
                dp[i+1][t+A[i]] = max(dp[i+1][t+A[i]], dp[i][t] + B[i]);
            }
        }
    }
    
    int max_happiness = 0;
    for (int t = 0; t <= T; t++) {
        max_happiness = max(max_happiness, dp[N][t]);
    }
    
    cout << max_happiness << endl;
    
    return 0;
}