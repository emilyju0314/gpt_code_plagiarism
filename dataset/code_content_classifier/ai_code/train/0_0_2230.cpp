#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int countWays(int N, int M, int K) {
    vector<vector<long long>> dp(N + 1, vector<long long>(K + 1, 0));
    dp[0][0] = M;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            dp[i][j] = dp[i-1][j] % MOD;
            if (j > 0) {
                dp[i][j] = (dp[i][j] + ((M - 1) * dp[i-1][j-1]) % MOD) % MOD;
            }
        }
    }

    return dp[N][K];
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    int result = countWays(N, M, K);

    cout << result << endl;

    return 0;
}