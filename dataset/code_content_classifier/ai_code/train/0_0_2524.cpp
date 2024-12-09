#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to, weight;
};

void dijkstra(int start, vector<vector<Edge>>& adj, vector<int>& dist) {
    dist.assign(dist.size(), INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (Edge& e : adj[u]) {
            if (dist[u] + e.weight < dist[e.to]) {
                dist[e.to] = dist[u] + e.weight;
                pq.push({dist[e.to], e.to});
            }
        }
    }
}

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<vector<Edge>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    vector<int> dist(n);
    vector<int> min_dist(n, INF);

    for (int p = 0; p < n; p++) {
        vector<vector<Edge>> adj_copy(adj);
        for (int i = 0; i < adj_copy[p].size(); i++) {
            adj_copy[p][i].weight = INF;
        }

        dijkstra(0, adj_copy, dist);
        min_dist[p] = dist[p];
    }

    for (int d : min_dist) {
        cout << d << " ";
    }

    return 0;
}