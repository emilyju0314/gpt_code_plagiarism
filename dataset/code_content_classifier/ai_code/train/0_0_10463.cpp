#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int N, C;
        cin >> N >> C;

        vector<long long> dp(N+1);
        dp[0] = 0;
        dp[1] = 1;

        for (int j = 2; j <= N; j++) {
            dp[j] = dp[j-1] + 1;
            for (int k = 1; k <= j-1; k++) {
                dp[j] = max(dp[j], dp[k] + (long long)(j-k-1)*C);
            }
            dp[j] %= MOD;
        }

        cout << dp[N] << endl;
    }

    return 0;
}