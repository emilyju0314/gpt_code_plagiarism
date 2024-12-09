#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;

    vector<int> boss(N + 1);
    for (int i = 2; i <= N; i++) {
        cin >> boss[i];
    }

    vector<vector<long long>> dp(N + 1, vector<long long>(2, 0));
    // dp[i][0] represents the number of ways for member i to stand without their boss on the left
    // dp[i][1] represents the number of ways for member i to stand without their boss on the right

    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i = 2; i <= N; i++) {
        dp[i][0] = 1;
        dp[i][1] = 1;
        for (int j = 2; j < i; j++) {
            if (boss[i] == j) {
                dp[i][0] = (dp[i][0] * dp[j][1]) % MOD;
                dp[i][1] = (dp[i][1] * dp[j][0]) % MOD;
            } else {
                dp[i][0] = (dp[i][0] * (dp[j][0] + dp[j][1]) % MOD) % MOD;
                dp[i][1] = (dp[i][1] * (dp[j][0] + dp[j][1]) % MOD) % MOD;
            }
        }
    }

    long long ans = (dp[N][0] + dp[N][1]) % MOD;
    cout << ans << endl;

    return 0;
}