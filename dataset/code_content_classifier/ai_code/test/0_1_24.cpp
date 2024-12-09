#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define MAXN 200005

struct Edge {
    int to, weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

int n, m, q;
vector<int> w(MAXN);
vector<vector<Edge>> graph(MAXN);
vector<vector<int>> dist(MAXN, vector<int>(MAXN, INT_MAX));
vector<vector<int>> cost(MAXN, vector<int>(MAXN, INT_MAX));

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start][start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (dist[start][u] < d) continue;

        for (Edge& e : graph[u]) {
            if (dist[start][e.to] > d + e.weight) {
                dist[start][e.to] = d + e.weight;
                pq.push({dist[start][e.to], e.to});
            }
        }
    }
}

int main() {
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        graph[u].push_back(Edge(v, d));
        graph[v].push_back(Edge(u, d));
    }

    for (int i = 1; i <= n; i++) {
        dijkstra(i);
    }

    for (int i = 0; i <= q; i++) {
        if (i > 0) {
            int k, x;
            cin >> k >> x;
            for (int j = 1; j <= n; j++) {
                if (j == 1 || j == k) continue;
                cost[j][k] = min(cost[j][k], w[j] + x);
            }
        }

        long long totalCost = 0;
        for (int j = 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                int minDist = min({dist[1][j] + dist[j][k], dist[1][k] + dist[k][j]});
                totalCost += min(minDist, dist[1][k] + dist[k][j]) * cost[j][k];
            }
        }
        cout << totalCost << endl;
    }

    return 0;
}