#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MOD 998244353

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> lamps(n);
    for (int i = 0; i < n; i++) {
        cin >> lamps[i].first >> lamps[i].second;
    }

    sort(lamps.begin(), lamps.end());

    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        sum = (sum + dp[i]) % MOD;
        dp[i + 1] = (dp[i + 1] + sum) % MOD;
        int l = i, r = i;

        while (r < n && lamps[r].first == lamps[i].first) {
            r++;
        }

        while (r <= n) {
            if (r < n) {
                dp[r] = (dp[r] - dp[l] + MOD) % MOD;
            }

            while (l < r && lamps[l].second < lamps[r].second) {
                sum = (sum - dp[l] + MOD) % MOD;
                l++;
            }

            r++;
        }
    }

    long long result = (dp[n] - dp[n - 1] + MOD) % MOD;
    cout << result << endl;

    return 0;
}