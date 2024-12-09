#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> dp(K+1, vector<int>(N+1, 0));
    for (int i = 1; i <= N; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= K; i++) {
        int sum = 0;
        for (int j = 1; j <= N; j++) {
            sum = (sum + dp[i-1][j]) % MOD;
            dp[i][j] = sum;
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = (ans + dp[K][i]) % MOD;
    }
    
    cout << ans << endl;

    return 0;
}