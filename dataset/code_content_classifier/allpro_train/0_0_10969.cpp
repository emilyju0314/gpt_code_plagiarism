#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int v, u;
        ll w;
        cin >> v >> u >> w;
        adj[v].push_back({u, w});
        adj[u].push_back({v, w});
    }

    vector<ll> cost(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }

    vector<ll> dist(n+1, LLONG_MAX);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    vector<bool> visited(n+1, false);

    for (int i = 1; i <= n; i++) {
        pq.push({cost[i], i});
        dist[i] = cost[i];
    }

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) {
            continue;
        }
        visited[u] = true;

        for (auto edge : adj[u]) {
            int v = edge.first;
            ll w = edge.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }
    
    return 0;
}