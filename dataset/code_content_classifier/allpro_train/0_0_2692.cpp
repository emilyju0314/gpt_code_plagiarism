#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, D;
    cin >> n >> m >> D;

    vector<pair<int, int>> edges;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (adj[1].size() < D || adj[1].size() > m) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;

        vector<int> ans;
        for (int i = 0; i < D; i++) {
            ans.push_back(adj[1][i]);
        }

        for (int i = D; i < n - 1; i++) {
            for (auto e : edges) {
                if (e.first != 1 && e.second != 1) {
                    ans.push_back(e.first);
                    ans.push_back(e.second);
                    break;
                }
            }
        }

        for (int i = 0; i < n - 1; i++) {
            cout << "1 " << ans[i] << endl;
        }
    }

    return 0;
}