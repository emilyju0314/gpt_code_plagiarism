#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N, A, B, C;
    cin >> N >> A >> B >> C;

    vector<vector<vector<long long>>>
            dp(N + 1, vector<vector<long long>>(N + 1, vector<long long>(N + 1)));

    dp[0][0][0] = 1;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k <= N; k++) {
                if (i < N) {
                    dp[i + 1][j][k] += dp[i][j][k];
                    dp[i + 1][j][k] %= MOD;
                }
                if (j < N && i - j >= 1) {
                    dp[i][j + 1][k] += dp[i][j][k];
                    dp[i][j + 1][k] %= MOD;
                }
                if (k < N && i - k >= 2) {
                    dp[i][j][k + 1] += dp[i][j][k];
                    dp[i][j][k + 1] %= MOD;
                }
            }
        }
    }

    cout << dp[N][A][B] << endl;

    return 0;
}