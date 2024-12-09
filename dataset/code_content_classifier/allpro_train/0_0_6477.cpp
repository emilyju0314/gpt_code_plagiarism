#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<long long>> dp(N + 1, vector<long long>(2, 0));
    dp[0][1] = 1;

    for (int i = 1; i <= N; i++) {
        dp[i][0] = (dp[i-1][1] + dp[i-1][0]) * (K-1) % MOD;
        dp[i][1] = dp[i-1][0];
    }

    cout << (dp[N][0] + dp[N][1]) % MOD;

    return 0;
}