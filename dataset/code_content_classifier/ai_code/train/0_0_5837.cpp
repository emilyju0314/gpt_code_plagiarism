#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> shortestPath(n + 1, INF);
    vector<int> trainRoutes(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        adj[u].push_back({v, x});
        adj[v].push_back({u, x});
    }

    for (int i = 0; i < k; i++) {
        int s, y;
        cin >> s >> y;
        trainRoutes[s] = y;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    shortestPath[1] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if (dist > shortestPath[u]) continue;

        for (pair<int, int> edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (shortestPath[u] + weight < shortestPath[v]) {
                shortestPath[v] = shortestPath[u] + weight;
                pq.push({shortestPath[v], v});
            }
        }
    }

    int trainRoutesClosed = 0;
    for (int i = 2; i <= n; i++) {
        if (trainRoutes[i] < shortestPath[i]) {
            trainRoutesClosed++;
        }
    }

    cout << trainRoutesClosed << endl;

    return 0;
}