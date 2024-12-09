#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to, dist;
};

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> w(n);
    vector<vector<Edge>> adj(n);

    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        u--; v--;

        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    vector<int> dist(n, INF);
    dist[0] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (dist[u] < d) continue;

        for (Edge& e : adj[u]) {
            int v = e.to;
            int new_dist = d + e.dist + w[v];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }

    vector<pair<int, int>> incidents;
    for (int i = 0; i < q; i++) {
        int k, x;
        cin >> k >> x;
        k--;

        incidents.push_back({k, x});

        int min_cost = dist[n - 1];
        for (int j = 0; j < n; j++) {
            if (dist[j] < min_cost) {
                for (Edge& e : adj[j]) {
                    if (e.to != k) {
                        min_cost = min(min_cost, dist[j] + e.dist + w[e.to] + x);
                    }
                }
            }
        }

        cout << min_cost << endl;
    }

    return 0;
}