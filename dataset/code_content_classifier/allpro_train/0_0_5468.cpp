#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;

        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_set<int> a_neighbors(adj[a].begin(), adj[a].end());
        unordered_set<int> b_neighbors(adj[b].begin(), adj[b].end());

        long long common_neighbors = 0;
        for (int i = 1; i <= n; i++) {
            if (i == a || i == b) continue;
            if (a_neighbors.find(i) != a_neighbors.end() && b_neighbors.find(i) != b_neighbors.end()) {
                common_neighbors++;
            }
        }

        long long total_pairs = (n - 2) * (n - 3) / 2;
        cout << total_pairs - common_neighbors << endl;
    }

    return 0;
}