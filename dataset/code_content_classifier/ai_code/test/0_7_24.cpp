#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to, weight;
};

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> w(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    vector<vector<Edge>> graph(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
    }

    vector<vector<int>> dist(2, vector<int>(n+1, INF));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[0][1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
        int d = top.first;
        int u = top.second;

        if (d > dist[1][u]) continue;

        for (Edge& e : graph[u]) {
            int v = e.to;
            int w_uv = e.weight + w[u];
            if (dist[0][v] > w_uv) {
                swap(dist[0][v], dist[1][v]);
                dist[0][v] = w_uv;
                pq.push({w_uv, v});
            } else if (dist[1][v] > w_uv && dist[0][v] < w_uv) {
                dist[1][v] = w_uv;
                pq.push({w_uv, v});
            }
        }
    }

    int total_cost = 0;
    for (int i = 1; i <= n; i++) {
        total_cost += dist[0][i];
    }
    cout << total_cost << endl;

    for (int i = 0; i < q; i++) {
        int k, x;
        cin >> k >> x;

        int min_diff = min(dist[0][k] - w[k], dist[1][k]);
        if (x > 0) min_diff = min(min_diff, dist[1][k] - w[k]);
        w[k] += x;

        int diff = min(w[k] - dist[0][k], min_diff);
        total_cost += diff;
        cout << total_cost << endl;
    }

    return 0;
}