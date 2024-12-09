#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> X(M + 2);
    X[0] = 0;
    for (int i = 1; i <= M; i++) {
        cin >> X[i];
    }
    X[M + 1] = N;

    vector<long long> dp(M + 2); // dp[i] stores the number of ways to form squares up to i-th mark
    dp[0] = 1;
    vector<long long> sum(M + 2); // sum[i] stores the sum of dp[i] up to i-th mark

    for (int i = 1; i <= M + 1; i++) {
        int diff = X[i] - X[i - 1];
        int prev_diff = X[i - 1] - X[i - 2];
        
        dp[i] = (sum[i - 2] + dp[i - 1]) % MOD;
        sum[i] = (sum[i - 1] + dp[i]) % MOD;
        if (i > 2 && diff <= prev_diff) {
            dp[i] = (dp[i] + sum[i - 2] - sum[i - 2 - diff] + MOD) % MOD;
            sum[i] = (sum[i] + dp[i]) % MOD;
        }
    }

    long long total_sum = 0;
    for (int i = 1; i <= M + 1; i++) {
        int diff = X[i] - X[i - 1];
        total_sum = (total_sum + dp[i] * diff % MOD * diff % MOD) % MOD;
    }

    cout << total_sum << endl;

    return 0;
}