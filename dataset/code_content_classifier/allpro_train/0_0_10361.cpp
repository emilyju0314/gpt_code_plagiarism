#include <iostream>
#include <vector>
#include <cstring>

#define MOD 1000000007

using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    vector<vector<long long>> dp(n, vector<long long>(16, 0));
    vector<vector<long long>> new_dp(n, vector<long long>(16, 0));

    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = a[i]; j <= b[i]; j++) {
            for (int t = 0; t < 16; t++) {
                for (int nt = 0; nt < 16; nt++) {
                    int dy = (j == b[i] ? 0 : c[i]);
                    int add = 0;
                    if (t / 4 + (t % 4 != 0) + (nt % 4 != 0) <= dy) {
                        add = dp[i][t];
                    }
                    new_dp[i][t % 4 * 4 + nt % 4] = (new_dp[i][t % 4 * 4 + nt % 4] + add) % MOD;
                }
            }
        }

        if (i == n - 1) {
            cout << dp[n - 1][0];
        } else {
            for (int j = 0; j < 16; j++) {
                dp[i + 1][j] = new_dp[i][j];
            }
        }
    }

    return 0;
}