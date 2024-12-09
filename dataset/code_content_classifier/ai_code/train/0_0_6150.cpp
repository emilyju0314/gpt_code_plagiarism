#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> deg(n, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    queue<int> q;

    // Initialize the queue with leaf nodes
    for (int i = 0; i < n; i++) {
        if (deg[i] == 1) {
            q.push(i);
        }
    }

    int diameter = 0;
    vector<pair<int, int>> edges;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        
        for (int v : adj[u]) {
            if (--deg[v] == 1) {
                q.push(v);
                edges.push_back({u, v});
                diameter++;
            }
        }
    }

    cout << diameter << endl;
    for (int i = 0; i < n-1-m; i++) {
        cout << edges[i].first + 1 << " " << edges[i].second + 1 << endl;
    }

    return 0;
}