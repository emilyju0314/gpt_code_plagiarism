#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N, K, M;
    cin >> N >> K >> M;

    vector<vector<int>> dp(N+1, vector<int>(K+1, 0));
    for (int j = 1; j <= K; j++) {
        dp[1][j] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            for (int k = 1; k < j; k++) {
                dp[i][j] += dp[i-1][k];
                dp[i][j] %= M;
            }
        }
    }

    int ans = 0;
    for (int j = 1; j <= K; j++) {
        ans += dp[N][j];
        ans %= M;
    }

    cout << ans << endl;

    return 0;
}