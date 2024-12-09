#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, s, e;
    cin >> n >> s >> e;

    vector<int> x(n), a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    dp[s-1][e-1] = 0;

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((mask & (1 << j)) == 0) continue; // j-th chair not visited yet
                for (int k = 0; k < n; k++) {
                    if (i == k || j == k) continue;
                    int cost = abs(x[i]-x[k]);
                    if (j < k) {
                        cost += d[j] + a[k];
                    } else {
                        cost += c[j] + b[k];
                    }
                    dp[i][k] = min(dp[i][k], dp[i][j] + cost);
                }
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                ans = min(ans, dp[i][j] + abs(x[j]-x[e-1]));
            }
        }
    }

    cout << ans << endl;

    return 0;
}