#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge {
    int to, cost;
    Edge(int t, int c) : to(t), cost(c) {}
};

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    // Constructing the graph
    vector<vector<Edge>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        u--; v--;
        adj[u].push_back(Edge(v, d));
        adj[v].push_back(Edge(u, d));
    }

    // Dijkstra's algorithm to find the minimum cost
    auto dijkstra = [&](int src) {
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (Edge& e : adj[u]) {
                int v = e.to;
                int cost = e.cost + w[v];
                if (dist[v] > dist[u] + cost) {
                    dist[v] = dist[u] + cost;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    };

    vector<int> initCost = dijkstra(0);
    for (int i = 0; i <= q; i++) {
        if (i > 0) {
            int k, x;
            cin >> k >> x;
            w[k-1] += x;
        }

        vector<int> updatedCost = dijkstra(0);
        int result = *min_element(updatedCost.begin(), updatedCost.end());
        cout << result << endl;
    }

    return 0;
}