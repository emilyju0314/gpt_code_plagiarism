#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to;
    int cost;

    Edge(int to, int cost) : to(to), cost(cost) {}
};

int dijkstra(vector<vector<Edge>>& graph, int start, int end) {
    vector<int> dist(graph.size(), INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (u == end) {
            return dist[u];
        }

        if (dist[u] < d) {
            continue;
        }

        for (Edge& e : graph[u]) {
            int v = e.to;
            int cost = e.cost;

            if (dist[v] > dist[u] + cost) {
                dist[v] = dist[u] + cost;
                pq.push({dist[v], v});
            }
        }
    }

    return -1;
}

int main() {
    int n, m;
    while (cin >> n >> m && n != 0 && m != 0) {
        vector<vector<Edge>> graph(n);
        vector<int> d(n), e(n);

        for (int i = 1; i < n - 1; i++) {
            cin >> d[i] >> e[i];
        }

        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            graph[a].push_back(Edge(b, c));
        }

        int goCost = dijkstra(graph, 1, n);
        if (goCost == -1) {
            cout << -1 << endl;
            continue;
        }

        int returnCost = dijkstra(graph, n, 1);

        int minCost = goCost + returnCost;
        cout << minCost << endl;
    }

    return 0;
}