#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<vector<int>> dp(n, vector<int>(n+1, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
            for (auto& neighbor : adj[i]) {
                int v = neighbor.first;
                int c = neighbor.second;
                dp[v][j+1] = max(dp[v][j+1], dp[i][j] + (x[v] == j+1 ? 0 : c));
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, dp[n-1][i]);
    }

    cout << ans << endl;

    return 0;
}