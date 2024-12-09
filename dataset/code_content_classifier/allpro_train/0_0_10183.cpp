#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, s, e;
    cin >> n >> s >> e;

    vector<int> x(n), a(n), b(n), c(n), d(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }

    for(int i = 0; i < n; i++) {
        cin >> d[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

    dp[s-1][s-1] = 0;

    for(int mask = 1; mask < (1 << n); mask++) {
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                for(int j = 0; j < n; j++) {
                    if(!(mask & (1 << j))) {
                        int time = abs(x[i] - x[j]);
                        if(j < i) {
                            time += c[i] + b[j];
                        } else {
                            time += d[i] + a[j];
                        }
                        dp[i][j] = min(dp[i][j], dp[i][j ^ (1 << j)] + time);
                    }
                }
            }
        }
    }

    int ans = INT_MAX;
    for(int i = 0; i < n; i++) {
        ans = min(ans, dp[i][e-1]);
    }

    cout << ans << endl;

    return 0;
}