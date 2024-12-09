#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k, x;
        cin >> n >> k >> x;

        int num_bits = min(20, k);
        vector<long long> dp(1 << num_bits, 0);

        dp[x] = 1;
        for (int i = 1; i < n; i++) {
            vector<long long> new_dp(1 << num_bits, 0);
            for (int j = 0; j < (1 << num_bits); j++) {
                for (int bit = 0; bit < num_bits; bit++) {
                    if ((j & (1 << bit)) == 0) {
                        new_dp[j ^ (1 << bit)] += dp[j];
                        new_dp[j ^ (1 << bit)] %= MOD;
                    }
                }
            }
            dp = new_dp;
        }

        long long answer = 1;
        for (int i = 0; i < n; i++) {
            answer *= 2;
            answer %= MOD;
        }

        for (int i = 0; i < (1 << num_bits); i++) {
            answer -= dp[i];
            if (answer < 0) {
                answer += MOD;
            }
        }

        cout << answer << endl;
    }

    return 0;
}