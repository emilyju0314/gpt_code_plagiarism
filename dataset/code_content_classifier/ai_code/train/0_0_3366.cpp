#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

struct Edge {
    int to, cost;
};

int dijkstra(int n, vector<vector<Edge>>& graph) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        int u = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (dist[u] < cost) continue;

        for (Edge& e : graph[u]) {
            int new_cost = cost + e.cost;

            if (new_cost < dist[e.to]) {
                dist[e.to] = new_cost;
                pq.push({new_cost, e.to});
            }
        }
    }

    return dist[n];
}

int main() {
    int n, m, c;

    while (cin >> n >> m >> c) {
        if (n == 0 && m == 0 && c == 0) break;

        vector<vector<Edge>> graph(n + 1);

        for (int i = 0; i < m; ++i) {
            int f, t, cost;
            cin >> f >> t >> cost;
            graph[f].push_back({t, cost});
        }

        int min_cost = dijkstra(n, graph);

        int num_changes = min_cost - c;

        cout << num_changes << endl;
    }

    return 0;
}