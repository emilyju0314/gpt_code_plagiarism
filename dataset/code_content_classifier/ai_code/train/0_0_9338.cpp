#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

vector<vector<int>> dp(2002, vector<int>(2002, 0)); // Initialize DP table

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    dp[0][0] = 1;
    for (int i = 1; i <= N + M - 1; i++) {
        for (int j = 1; j <= min(i, N); j++) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
        }
    }

    int ans = 0;
    for (int i = 0; i <= N; i++) {
        if ((N - i) % (K - 1) == 0) {
            ans = (ans + dp[N + M - 1 - i][i]) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}