#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to;
    int type;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({v, t});
    }

    vector<int> dist(n + 1, INT_MAX);
    vector<int> color(n + 1, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    color[1] = 0;

    while (!pq.empty()) {
        pair<int, int> curr = pq.top();
        pq.pop();

        int u = curr.second;
        int d = curr.first;

        if (d > dist[u]) {
            continue;
        }

        for (Edge e : adj[u]) {
            int v = e.to;
            int w = e.type;

            if (dist[u] + 1 < dist[v] && (color[u] == w || color[v] == -1)) {
                dist[v] = dist[u] + 1;
                color[v] = w;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[n] == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << dist[n] << endl;
        for (int i = 1; i <= n; i++) {
            cout << color[i];
        }
        cout << endl;
    }

    return 0;
}