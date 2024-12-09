#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    int n, m, L, s, t;
    cin >> n >> m >> L >> s >> t;

    vector<vector<pii>> graph(n);
    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
        edges.push_back({u, v, w});
    }

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    vector<vector<int>> parent(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, i});
        dist[i][i] = 0;

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[i][u]) continue;

            for (auto neighbor : graph[u]) {
                int v = neighbor.first;
                int w = neighbor.second;
                
                if (dist[i][u] + w < dist[i][v]) {
                    dist[i][v] = dist[i][u] + w;
                    parent[i][v] = u;
                    pq.push({dist[i][v], v});
                }
            }
        }
    }

    if (dist[s][t] < L) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        for (auto edge : edges) {
            int u, v, w;
            tie(u, v, w) = edge;

            if (w == 0) {
                w = 1;
                while (dist[s][u] + w + dist[v][t] > L) {
                    w++;
                }
            }
            cout << u << " " << v << " " << w << endl;
        }
    }

    return 0;
}