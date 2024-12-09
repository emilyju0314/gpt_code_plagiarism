#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<vector<int>> adj(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> subtree_sizes(n, 1);
    vector<bool> visited(n, false);

    // DFS to calculate sizes of subtrees
    function<void(int, int)> dfs = [&](int u, int p) {
        subtree_sizes[u] = 1;
        for (int v : adj[u]) {
            if (v != p && !visited[v]) {
                dfs(v, u);
                subtree_sizes[u] += subtree_sizes[v];
            }
        }
    };

    long long total_cost = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1);
            visited[i] = true;

            long long cost_for_subtree = min(x * (subtree_sizes[i] - 1), y * (subtree_sizes[i] - 2));
            total_cost += cost_for_subtree;

            for (int v : adj[i]) {
                long long subtree_size = subtree_sizes[v];
                if (subtree_size > 0) {
                    long long cost_for_other_subtree = min(x * subtree_size, y * (subtree_size - 1));
                    total_cost += cost_for_other_subtree;
                    subtree_sizes[v] = 0;
                    visited[v] = true;
                }
            }
        }
    }

    cout << total_cost << endl;

    return 0;
}