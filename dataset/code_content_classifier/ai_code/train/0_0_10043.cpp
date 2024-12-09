#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to, weight;
};

int INF = INT_MAX;

int dijkstra(vector<vector<Edge>>& graph, int start, int end) {
    vector<int> dist(graph.size(), INF);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (const Edge& e : graph[u]) {
            int v = e.to;
            int w = e.weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[end];
}

int main() {
    int N, M, S1, S2, T;
    while (cin >> N >> M >> S1 >> S2 >> T) {
        if (N == 0 && M == 0 && S1 == 0 && S2 == 0 && T == 0) break;

        vector<vector<Edge>> graph(N + 1);

        for (int i = 0; i < M; i++) {
            int a, b;
            string weight;
            cin >> a >> b >> weight;
            if (weight == "x") {
                graph[a].push_back({b, 0});
                graph[b].push_back({a, 0});
            } else {
                int w = stoi(weight);
                graph[a].push_back({b, w});
                graph[b].push_back({a, w});
            }
        }

        int distS1 = dijkstra(graph, S1, T);
        int distS2 = dijkstra(graph, S2, T);

        int minGap = abs(distS1 - distS2);
        cout << minGap << endl;
    }

    return 0;
}