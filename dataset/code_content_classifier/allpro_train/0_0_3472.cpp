#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to, cost;
};

void dijkstra(vector<vector<Edge>>& graph, int start, vector<int>& dist) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (Edge& edge : graph[u]) {
            int v = edge.to;
            int c = edge.cost;

            if (dist[u] + c < dist[v]) {
                dist[v] = dist[u] + c;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<int> originalPrices(m + 1);
    for (int i = 1; i <= m; i++) {
        originalPrices[i] = graph[i][0].cost;
    }

    vector<int> distFromStart(n + 1, INF);
    dijkstra(graph, 1, distFromStart);

    while (q--) {
        int t, x;
        cin >> t >> x;
        
        int u = graph[t][0].to;
        int v = graph[t][1].to;
        int dist1 = min(distFromStart[u] + originalPrices[t], distFromStart[v]);
        int dist2 = min(distFromStart[u], distFromStart[v] + originalPrices[t]);

        int newDist1 = min(distFromStart[u] + x, distFromStart[v]);
        int newDist2 = min(distFromStart[u], distFromStart[v] + x);
        
        cout << min({dist1, dist2, newDist1, newDist2}) << endl;
    }

    return 0;
}