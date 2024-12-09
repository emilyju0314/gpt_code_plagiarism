#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(M + 1, vector<int>(K + 1, 0)));

    dp[N][M][K] = 1;

    for (int i = N; i >= 0; i--) {
        for (int j = M; j >= 0 ; j--) {
            for (int k = K; k >= 0; k--) {
                if (i == 0 && j == 0 && k == 0) {
                    continue;
                }

                long long total_ways = 1LL*i*j % MOD * k % MOD + 1LL*j*k % MOD * i % MOD + 1LL*k*i % MOD * j % MOD;
                total_ways %= MOD;

                if (i > 0) {
                    dp[i - 1][j][k] = (dp[i - 1][j][k] + total_ways * dp[i][j][k] % MOD) % MOD;
                }
                if (j > 0) {
                    dp[i][j - 1][k] = (dp[i][j - 1][k] + total_ways * dp[i][j][k] % MOD) % MOD;
                }
                if (k > 0) {
                    dp[i][j][k - 1] = (dp[i][j][k - 1] + total_ways * dp[i][j][k] % MOD) % MOD;
                }
            }
        }
    }

    cout << dp[0][0][0] << endl;

    return 0;
}