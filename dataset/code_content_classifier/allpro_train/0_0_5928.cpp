#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    vector<pair<int, int>> edges;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges.push_back({a, b});
    }

    int max_chain = 0;

    for (auto edge : edges) {
        int u = edge.first, v = edge.second;
        int cnt = 0;
        vector<bool> visited(n+1, false);
        vector<int> degree(n+1, 0);

        visited[v] = true;

        for (int child : adj[u]) {
            if (child != v) {
                visited[child] = true;
                degree[v]++;
            }
        }

        for (int child : adj[v]) {
            if (child != u) {
                visited[child] = true;
                degree[u]++;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                cnt++;
                if (degree[i] > 1) {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }

        if (degree[u] == 1) cnt++;
        if (degree[v] == 1) cnt++;

        max_chain = max(max_chain, cnt);
    }

    cout << max_chain << endl;

    return 0;
}