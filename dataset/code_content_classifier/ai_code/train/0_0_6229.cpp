#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to, departure, travel_time;
};

int main() {
    int N, M, S, G;
    cin >> N >> M >> S >> G;

    vector<vector<Edge>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v, t, c;
        cin >> u >> v >> t >> c;
        adj[u].push_back({v, t, c});
    }

    vector<int> dist(N + 1, INF);
    dist[S] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (Edge& e : adj[u]) {
            int v = e.to;
            int departure = e.departure;
            int travel_time = e.travel_time;

            if (departure >= dist[u] && dist[u] + travel_time < dist[v]) {
                dist[v] = dist[u] + travel_time;
                pq.push({dist[v], v});
            }
        }
    }

    cout << dist[G] << endl;

    return 0;
}