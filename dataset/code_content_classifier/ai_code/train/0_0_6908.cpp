#include <iostream>
#include <vector>
using namespace std;

const int MOD = 924844033;

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<long long>> dp(N + 1, vector<long long>(N + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k <= N; k++) {
                if (abs(k - i) <= K && j != k) {
                    dp[i][k] += dp[i - 1][j];
                    dp[i][k] %= MOD;
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += dp[N][i];
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}