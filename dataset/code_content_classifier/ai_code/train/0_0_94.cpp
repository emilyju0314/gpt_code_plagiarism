#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 1e9;

int main() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;

    vector<vector<pair<int, int>>> adj(n+1);
    vector<int> centrals(k);
    for (int i = 0; i < k; i++) {
        cin >> centrals[i];
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<vector<int>> dist(k, vector<int>(n+1, INF));
    for (int i = 0; i < k; i++) {
        int start = centrals[i];
        dist[i][start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});
        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if (d > dist[i][u]) continue;
            for (auto edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;
                if (dist[i][v] > dist[i][u] + w) {
                    dist[i][v] = dist[i][u] + w;
                    pq.push({dist[i][v], v});
                }
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        int min_capacity = INF;
        for (int j = 0; j < k; j++) {
            min_capacity = min(min_capacity, dist[j][a] + dist[j][b]);
        }
        cout << min_capacity << endl;
    }

    return 0;
}