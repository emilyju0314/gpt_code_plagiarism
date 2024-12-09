#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n+1);
    vector<int> dp(n+1, 0);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }

    for (int i = 1; i <= n; i++) {
        for (auto edge : adj[i]) {
            dp[edge.first] = max(dp[edge.first], dp[i]+1);
        }
    }

    int max_edges = 0;
    for (int i = 1; i <= n; i++) {
        max_edges = max(max_edges, dp[i]);
    }

    cout << max_edges << endl;

    return 0;
}