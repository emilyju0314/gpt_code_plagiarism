#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> lengths(n);
    vector<int> costs(n);

    for (int i = 0; i < n; i++) {
        cin >> lengths[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    int INF = 1e9;
    int dp[601] = {0};

    for (int i = 1; i <= 600; i++) {
        dp[i] = INF;
        for (int j = 0; j < n; j++) {
            if (i >= lengths[j]) {
                dp[i] = min(dp[i], dp[i - lengths[j]] + costs[j]);
            }
        }
    }

    int ans = INF;
    for (int i = 1; i <= 300; i++) {
        ans = min(ans, dp[i]);
    }

    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}