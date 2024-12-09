#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
    int to;
    int weight;
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<Edge>> adj(n + 1);
    vector<int> shortest_path(n + 1, INT_MAX);
    shortest_path[1] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        adj[u].push_back({v, x});
        adj[v].push_back({u, x});
    }

    for (int i = 0; i < k; i++) {
        int s, y;
        cin >> s >> y;
        shortest_path[s] = min(shortest_path[s], y);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (cost > shortest_path[node]) {
            continue;
        }

        for (Edge& edge : adj[node]) {
            int new_cost = cost + edge.weight;
            if (new_cost < shortest_path[edge.to]) {
                shortest_path[edge.to] = new_cost;
                pq.push({new_cost, edge.to});
            }
        }
    }

    int num_routes = 0;
    for (int i = 2; i <= n; i++) {
        if (shortest_path[i] == shortest_path[1]) {
            num_routes++;
        }
    }

    cout << k - num_routes << endl;

    return 0;
}