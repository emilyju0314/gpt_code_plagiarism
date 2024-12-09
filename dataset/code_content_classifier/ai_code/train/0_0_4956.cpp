#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }

    vector<vector<double>> dp(n + 1, vector<double>(k + 1, 0.0));
    dp[0][0] = 1.0;

    for (int i = 0; i < n; i++) {
        vector<vector<double>> new_dp(n + 1, vector<double>(k + 1, 0.0));
        for (int j = 0; j <= n; j++) {
            for (int s = 0; s <= k; s++) {
                if (dp[j][s] == 0) continue;
                for (int x = 0; x < l[i]; x++) {
                    int r = rand() % l[i] + 1;
                    double prob = double(r) / double(l[i]);
                    new_dp[j + 1][min(s + r, k)] += dp[j][s] * prob;
                    new_dp[j + 1][s] += dp[j][s] * (1.0 - prob);
                }
            }
        }

        swap(dp, new_dp);
    }

    double result = 0.0;
    for (int j = 1; j <= n; j++) {
        for (int s = 0; s <= k; s++) {
            result += dp[j][s] * j;
        }
    }

    long long ans = (long long) (result + 0.5) % MOD;
    cout << ans << endl;

    return 0;
}