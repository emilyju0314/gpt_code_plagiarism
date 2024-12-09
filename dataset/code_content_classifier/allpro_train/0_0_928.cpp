#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> dp(N+1, 0);
    dp[1] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            int l, r;
            cin >> l >> r;
            dp[i] = (dp[i] + (i-l >= 0 ? dp[i-l] : 0) - (i-r-1 >= 0 ? dp[i-r-1] : 0) + MOD) % MOD;
        }
        dp[i] = (dp[i] + dp[i-1]) % MOD;
    }

    cout << dp[N] << endl;

    return 0;
}