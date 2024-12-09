#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int to, cost;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--;

        graph[a].push_back({b, c});
        graph[b].push_back({a, d});
    }

    int s, g, V, P;
    cin >> s >> g >> V >> P;
    s--; g--;

    priority_queue<pair<int, int>> pq;
    vector<int> dist(n, -1);
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (u == g) break;

        for (const Edge& e : graph[u]) {
            if (dist[e.to] == -1 || dist[u] + e.cost < dist[e.to]) {
                dist[e.to] = dist[u] + e.cost;
                pq.push({-dist[e.to], e.to});
            }
        }
    }

    int maxReward = V - P - dist[g];
    cout << maxReward << endl;

    return 0;
}