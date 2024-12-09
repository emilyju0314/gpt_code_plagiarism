#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> dp(n + 1, 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        for (int j : adj[i]) {
            dp[j] = max(dp[j], dp[i] + 1);
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i] * (int)adj[i].size());
    }

    cout << ans << endl;

    return 0;
}