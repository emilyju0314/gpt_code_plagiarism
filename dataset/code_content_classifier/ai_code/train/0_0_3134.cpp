#include <iostream>
#include <vector>
#include <cmath>

#define MOD 998244353

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> mercenaries(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        mercenaries[i] = make_pair(l, r);
    }

    vector<vector<bool>> hates(n, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        hates[a-1][b-1] = true;
        hates[b-1][a-1] = true;
    }

    vector<long long> dp(1 << n, 0);
    dp[0] = 1;

    for (int mask = 1; mask < (1 << n); mask++) {
        int mercenaries_in_subset = __builtin_popcount(mask);
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i) && mercenaries_in_subset >= mercenaries[i].first && mercenaries_in_subset <= mercenaries[i].second) {
                bool valid = true;
                for (int j = 0; j < n; j++) {
                    if (mask & (1 << j) && hates[i][j]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    int prev_mask = mask ^ (1 << i);
                    dp[mask] = (dp[mask] + dp[prev_mask]) % MOD;
                }
            }
        }
    }

    long long result = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        result = (result + dp[mask]) % MOD;
    }

    cout << result << endl;

    return 0;
}