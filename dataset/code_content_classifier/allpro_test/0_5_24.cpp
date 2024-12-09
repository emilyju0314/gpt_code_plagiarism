#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF LLONG_MAX

vector<vector<pair<int, int>>> adj;
vector<int> w;
vector<int> dist;

void dijkstra(int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist.assign(adj.size(), INF);
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int w_uv = edge.second;

            if (dist[u] + w_uv < dist[v]) {
                dist[v] = dist[u] + w_uv;
                pq.push({dist[v], v});
            }
        }
    }
}

int solve(int n) {
    vector<int> shortest_paths(n, 0);
    int total_cost = 0;

    for (int i = 0; i < n; i++) {
        shortest_paths[i] = dist[i];
    }

    sort(shortest_paths.begin(), shortest_paths.end());

    for (int i = 1; i < n; i++) {
        total_cost += shortest_paths[i] * 2;
    }

    return total_cost;
}

signed main() {
    int n, m, q;
    cin >> n >> m >> q;

    adj.resize(n);
    w.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        u--; v--;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }

    dijkstra(0);

    cout << solve(n) << endl;

    for (int i = 0; i < q; i++) {
        int k, x;
        cin >> k >> x;
        k--;

        w[k] += x;

        cout << solve(n) << endl;
    }

    return 0;
}