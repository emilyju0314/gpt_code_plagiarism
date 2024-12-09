#include <iostream>
#include <vector>

#define MOD 998244353

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<vector<long long>> dp(N + 1, vector<long long>(N + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
            if (j < h[i]) {
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i <= N; i++) {
        ans = (ans + dp[N][i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}