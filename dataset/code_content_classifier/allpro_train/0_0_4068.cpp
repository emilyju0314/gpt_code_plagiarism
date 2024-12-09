#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1000000000

struct edge {
    int to, cost;
};

int N, M, s, t;
vector<vector<edge>> graph;

int dijkstra(int s, int t) {
    vector<int> dist(N, INF);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {distance, vertex}
    pq.push({0, s});

    while (!pq.empty()) {
        int d = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (dist[v] < d) continue;

        for (edge& e : graph[v]) {
            if (dist[e.to] > dist[v] + e.cost) {
                dist[e.to] = dist[v] + e.cost;
                pq.push({dist[e.to], e.to});
            }
        }
    }

    return dist[t];
}

int main() {
    cin >> N >> M >> s >> t;

    graph.resize(N);

    for (int i = 0; i < M; i++) {
        int u, v, d, c;
        cin >> u >> v >> d >> c;
        u--; v--;
        graph[u].push_back({v, c});
    }

    int shortest_path_length = dijkstra(s-1, t-1);

    cout << shortest_path_length << endl;

    return 0;
}