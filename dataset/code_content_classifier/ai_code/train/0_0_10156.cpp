#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to, weight;
};

void dijkstra(int start, vector<vector<Edge>>& adj, vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (dist[u] < cost) continue;

        for (const Edge& e : adj[u]) {
            int v = e.to;
            int new_cost = cost + e.weight;
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({new_cost, v});
            }
        }
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<Edge>> adj(n + 1);
    vector<pair<int, int>> roads;

    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
        roads.push_back({x, y});
    }

    vector<int> original_costs;
    for (int i = 0; i < m; i++) {
        original_costs.push_back(adj[roads[i].first][roads[i].second].weight);
        adj[roads[i].first][roads[i].second].weight = 0;
        adj[roads[i].second][roads[i].first].weight = 0;

        int min_total_cost = 0;
        for (pair<int, int>& road : roads) {
            vector<int> dist(n + 1, INF);
            dijkstra(road.first, adj, dist);
            min_total_cost += dist[road.second];
        }

        adj[roads[i].first][roads[i].second].weight = original_costs[i];
        adj[roads[i].second][roads[i].first].weight = original_costs[i];

        cout << min_total_cost << endl;
    }

    return 0;
}