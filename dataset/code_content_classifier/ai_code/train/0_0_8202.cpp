#include <iostream>
#include <vector>
#define MOD 998244353

using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    vector<vector<long long>> dp(C + 1, vector<long long>(D + 1, 0));
    dp[A][B] = 1;

    for (int i = A; i <= C; i++) {
        for (int j = B; j <= D; j++) {
            dp[i][j] += dp[i - 1][j] * j;
            dp[i][j] %= MOD;
            dp[i][j] += dp[i][j - 1] * i;
            dp[i][j] %= MOD;
            dp[i][j] += MOD - ((i * j) % MOD) * dp[i - 1][j - 1] % MOD;
            dp[i][j] %= MOD;
        }
    }

    cout << dp[C][D] << endl;

    return 0;
}