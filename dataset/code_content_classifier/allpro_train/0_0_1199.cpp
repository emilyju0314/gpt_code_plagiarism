#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int H, W, K;
    cin >> H >> W >> K;

    vector<vector<long long>> dp(W + 1, vector<long long>(H, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= H; i++) {
        vector<long long> sum(W + 1, 0);

        for (int j = 0; j < (1 << (W - 1)); j++) {
            bool valid = true;
            for (int k = 0; k < W - 2; k++) {
                if ((j & (1 << k)) && (j & (1 << (k + 1)))) {
                    valid = false;
                    break;
                }
            }

            if (!valid) continue;

            for (int l = 0; l < W; l++) {
                if (l > 0 && (j & (1 << (l - 1)))) {
                    dp[l][i] = (dp[l][i] + sum[l - 1]) % MOD;
                } else if (l < W - 1 && (j & (1 << l))) {
                    dp[l][i] = (dp[l][i] + sum[l + 1]) % MOD;
                } else {
                    dp[l][i] = (dp[l][i] + sum[l]) % MOD;
                }

                sum[l] = (sum[l] + dp[l][i - 1]) % MOD;
            }
        }
    }

    cout << dp[K - 1][H] << endl;

    return 0;
}