#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const long long INF = 1e18;

int n, m, L, s, t;
vector<pair<int, int>> edges[1005];
vector<pair<int, int, int>> newEdges;
long long dist[1005];

void dijkstra() {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, s});
    fill(dist, dist + n, INF);
    dist[s] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        long long d = pq.top().first;
        pq.pop();

        if (d != dist[u]) {
            continue;
        }

        for (auto edge : edges[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    cin >> n >> m >> L >> s >> t;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w == 0) {
            newEdges.push_back({u, v, 1});
            edges[u].push_back({v, 1});
            edges[v].push_back({u, 1});
        } else {
            edges[u].push_back({v, w});
            edges[v].push_back({u, w});
        }
    }

    dijkstra();

    if (dist[t] == L) {
        cout << "YES" << endl;
        for (auto e : newEdges) {
            cout << e.first << " " << e.second << " " << e.third << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}