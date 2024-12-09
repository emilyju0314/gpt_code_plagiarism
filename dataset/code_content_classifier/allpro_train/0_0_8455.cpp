#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to, weight;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({y, w});
        graph[y].push_back({x, w});
    }

    vector<int> dist(n + 1, INF);
    dist[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int u = pq.top().second;
        int xor_value = pq.top().first;
        pq.pop();

        if (xor_value > dist[u]) {
            continue;
        }

        for (Edge& edge : graph[u]) {
            int v = edge.to;
            int w = edge.weight;
            int new_xor = xor_value ^ w;

            if (new_xor < dist[v]) {
                dist[v] = new_xor;
                pq.push({new_xor, v});
            }
        }
    }

    cout << dist[n] << endl;

    return 0;
}