#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N, M;
    cin >> N >> M;

    vector<long long> dp(N + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i-1];
        if (i >= M) {
            dp[i] += dp[i-M];
        }
        dp[i] %= MOD;
    }

    cout << dp[N] << endl;

    return 0;
}