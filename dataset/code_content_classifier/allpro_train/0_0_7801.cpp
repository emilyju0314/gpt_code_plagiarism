#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to;
    long long weight;
};

vector<vector<Edge>> graph;
vector<long long> dist;

void dijkstra(int start) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        long long d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (const Edge& e : graph[u]) {
            int v = e.to;
            long long w = e.weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<long long> odd_even_weights(2*n);
    for (int i = 1; i < 2*n; i += 2) {
        cin >> odd_even_weights[i];
    }

    graph.resize(2*n);
    for (int i = 0; i < n-1; i++) {
        int x, y;
        long long w1, w2;
        cin >> x >> y >> w1 >> w2;

        graph[2*x-1].push_back({2*y-1, w1});
        graph[2*y-1].push_back({2*x-1, w1});

        graph[2*x].push_back({2*y, w2});
        graph[2*y].push_back({2*x, w2});
    }

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;

        dist.assign(2*n, LLONG_MAX);
        dijkstra(u);

        cout << dist[v] << endl;
    }

    return 0;
}