#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;

    vector<long long> dp(N + 1, 0);
    vector<long long> sum(N + 1, 0);

    for (int i = 2; i <= N; i++) {
        dp[i] = (dp[i-1] * 10 + 81) % MOD;
        sum[i] = (sum[i-1] + dp[i]) % MOD;
    }

    long long ans = dp[N];
    for (int i = 2; i < N; i++) {
        ans += (2 * (sum[N-i] * dp[i]) % MOD) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}