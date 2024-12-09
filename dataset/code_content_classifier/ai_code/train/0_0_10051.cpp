#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to;
    int weight;
};

void dijkstra(int start, vector<vector<Edge>>& graph, vector<int>& distances) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distances[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if (dist > distances[u]) {
            continue;
        }

        for (Edge& e : graph[u]) {
            int v = e.to;
            int weight = e.weight;

            if (dist + weight < distances[v]) {
                distances[v] = dist + weight;
                pq.push({distances[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;

        vector<int> distances(n+1, INT_MAX);
        dijkstra(u, graph, distances);
        cout << distances[v] << endl;
    }

    return 0;
}