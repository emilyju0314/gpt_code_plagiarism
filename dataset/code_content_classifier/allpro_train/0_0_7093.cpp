#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(M+1, vector<int>(K+1, 0)));
    
    dp[0][0][0] = 1;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            for (int k = 0; k <= K; k++) {
                if (i + 1 <= N) {
                    dp[i+1][j][k] = (dp[i+1][j][k] + dp[i][j][k]) % MOD;
                    if (k + 1 <= K) {
                        dp[i+1][j][k+1] = (dp[i+1][j][k+1] + dp[i][j][k]) % MOD;
                    }
                }
                if (j + 1 <= M) {
                    dp[i][j+1][k] = (dp[i][j+1][k] + dp[i][j][k]) % MOD;
                    if (k + 1 <= K) {
                        dp[i][j+1][k+1] = (dp[i][j+1][k+1] + dp[i][j][k]) % MOD;
                    }
                }
            }
        }
    }

    cout << dp[N][M][K] << endl;

    return 0;
}