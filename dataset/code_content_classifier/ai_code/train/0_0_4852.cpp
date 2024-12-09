#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, x;
    cin >> n >> k >> x;

    vector<int> beauty(n);
    for(int i = 0; i < n; i++) {
        cin >> beauty[i];
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(x + 1, 0));

    for(int i = 1; i <= n; i++) {
        long long sum = 0;
        vector<long long> pref(n + 1, 0);
        for(int j = 1; j <= n; j++) {
            pref[j] = pref[j-1] + (j > i-k ? beauty[j-1] : 0);
        }

        for(int j = 1; j <= x; j++) {
            if(i < j * k) {
                break;
            }

            for(int l = max(0, i-k); l <= i-1; l++) {
                dp[i][j] = max(dp[i][j], dp[l][j-1] + pref[i] - pref[l]);
            }
        }
    }

    long long ans = -1;
    for(int i = 0; i < n; i++) {
        ans = max(ans, dp[i][x]);
    }

    if(ans == 0) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}