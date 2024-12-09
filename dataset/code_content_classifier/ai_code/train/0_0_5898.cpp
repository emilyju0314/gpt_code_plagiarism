#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> dp1, dp2;
int k;

void dfs(int u, int parent) {
    dp1[u] = 0;
    dp2[u] = 0;

    for (auto& edge : adj[u]) {
        int v = edge.first;
        int w = edge.second;
        if (v == parent) continue;

        dfs(v, u);

        dp1[u] += dp1[v];

        if (dp1[v] - dp2[v] + w >= 0) {
            dp1[u] += dp1[v] - dp2[v] + w;
        } else {
            dp2[u] += dp1[v] - dp2[v] + w;
        }
    }

    dp1[u] = min(dp1[u], k);
}

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n >> k;

        adj.clear();
        adj.resize(n + 1);
        dp1.assign(n + 1, 0);
        dp2.assign(n + 1, 0);

        for (int i = 1; i < n; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        dfs(1, -1);
        cout << dp1[1] << endl;
    }

    return 0;
}