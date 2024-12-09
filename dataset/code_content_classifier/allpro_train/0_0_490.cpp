#include<bits/stdc++.h>
using namespace std;
#define INF 1000000007

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> adj(N+1);
    for (int i = 0; i < M; i++) {
        int L, R, C;
        cin >> L >> R >> C;
        adj[L].push_back({R, C});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(N+1, INF);
    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[N] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[N] << endl;
    }

    return 0;
}