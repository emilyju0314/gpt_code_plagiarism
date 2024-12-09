#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int K, N;
    cin >> K >> N;

    vector<vector<int>> dp(2, vector<int>(N * K + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= K; i++) {
        int curr = i % 2;
        int prev = 1 - curr;
        
        for (int j = 0; j <= N * K; j++) {
            dp[curr][j] = dp[prev][j];
            
            if (j >= i) {
                dp[curr][j] += dp[curr][j - i];
                dp[curr][j] %= MOD;
            }
        }
    }

    vector<int> ans(2*K - 1);
    
    for (int i = 2; i <= 2*K; i++) {
        for (int j = 1; j <= N; j++) {
            ans[i - 2] += dp[K % 2][i * j];
            ans[i - 2] %= MOD;
        }
    }

    for (int i = 0; i < 2*K - 1; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}