#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int to, weight, id;
};

void dijkstra(int start, vector<vector<Edge>>& graph, vector<int>& dist, vector<int>& prev) {
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int du = -pq.top().first;
        pq.pop();

        if (du > dist[u]) {
            continue;
        }

        for (Edge& e : graph[u]) {
            int v = e.to;
            int weight = e.weight;
            int id = e.id;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = id;
                pq.push({-dist[v], v});
            }
        }
    }
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<Edge>> graph(n + 1);
    vector<int> dist(n + 1, INT_MAX);
    vector<int> prev(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        graph[a].push_back({b, l, i});
    }

    dijkstra(s, graph, dist, prev);

    vector<bool> can_reach(m, false);
    vector<int> min_cost(m, INT_MAX);

    // Check if each road can be repaired
    for (int i = 1; i <= n; i++) {
        for (Edge& e : graph[i]) {
            int j = e.to;
            int weight = e.weight;
            int id = e.id;

            if (dist[i] + weight == dist[j]) { // President will definitely ride on this road
                can_reach[id] = true;
            } else {
                min_cost[id] = min(min_cost[id], dist[j] - dist[i] + 1); // Calculate minimum cost to repair
            }
        }
    }

    // Print the results
    for (int i = 0; i < m; i++) {
        if (can_reach[i]) {
            cout << "YES" << endl;
        } else if (min_cost[i] != INT_MAX) {
            cout << "CAN " << min_cost[i] << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}