#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to;
    int weight;
};

const int INF = INT_MAX;

int main() {
    int n, m, s;
    cin >> n >> m >> s;

    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (Edge e : graph[u]) {
            int v = e.to;
            int w = e.weight;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    vector<int> unhappy_friends(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (i == s) {
            continue;
        }

        for (Edge e : graph[i]) {
            int v = e.to;
            int w = e.weight;
            if (dist[i] == dist[v] + w || dist[v] == dist[i] + w) {
                unhappy_friends[i]++;
            }
        }
    }

    int max_unhappy_friends = 0;
    for (int i = 1; i <= n; i++) {
        max_unhappy_friends = max(max_unhappy_friends, unhappy_friends[i]);
    }

    cout << max_unhappy_friends << endl;

    return 0;
}