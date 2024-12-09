#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    vector<long long> dp(N+1, 0);
    dp[0] = 1;

    for(int i = 1; i <= N; i++) {
        dp[i] += dp[i-1]; // Move one piece to the right
        dp[i] %= MOD;

        if(i >= A) {
            dp[i] += dp[i-A]; // Move one piece to position A
            dp[i] %= MOD;
        }
        if(i >= B) {
            dp[i] += dp[i-B]; // Move one piece to position B
            dp[i] %= MOD;
        }
    }

    long long ans = (dp[N] - dp[N-1] + MOD) % MOD; // Subtract the ways where both pieces are at the same position
    cout << ans << endl;

    return 0;
}