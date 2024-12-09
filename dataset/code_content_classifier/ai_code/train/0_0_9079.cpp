#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to, cost;
    Edge(int to, int cost) : to(to), cost(cost) {}
};

int main() {
    int S, R;
    cin >> S >> R;

    vector<vector<Edge>> adj(S + 1);
    for (int i = 0; i < R; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(Edge(v, w));
        adj[v].push_back(Edge(u, w));
    }

    int a, b, Q;
    cin >> a >> b >> Q;

    while (Q--) {
        int c, d;
        cin >> c >> d;

        // Dijkstra's algorithm
        vector<int> dist(S + 1, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[a] = 0;
        pq.push({0, a});

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u]) continue;

            for (Edge& e : adj[u]) {
                int v = e.to;
                int w = e.cost;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        if (dist[c] + dist[d] <= dist[b]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}