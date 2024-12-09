#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> D(N);
    for (int i = 0; i < N; i++) {
        cin >> D[i];
    }

    vector<vector<int>> adj(N);
    vector<pair<int, int>> edges;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(i);
        adj[v].push_back(i);
        edges.push_back({u, v});
    }

    vector<int> color(N, -1);
    vector<int> weight(M, INF);

    vector<int> dist(N, INF);
    queue<int> q;

    q.push(0);
    dist[0] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int idx : adj[u]) {
            int v = (edges[idx].first == u) ? edges[idx].second : edges[idx].first;
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (dist[i] % 2 == 0) {
            color[i] = 0;
        } else {
            color[i] = 1;
        }
    }

    for (int i = 0; i < M; i++) {
        int u = edges[i].first, v = edges[i].second;
        weight[i] = abs(D[u] - D[v]);
    }

    for (int i = 0; i < N; i++) {
        if (D[i] % 2 == 0 && color[i] == 1) {
            cout << -1 << endl;
            return 0;
        }
        if (D[i] % 2 == 1 && color[i] == 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int c : color) {
        if (c == 0) {
            cout << "W";
        } else {
            cout << "B";
        }
    }
    cout << endl;

    for (int w : weight) {
        cout << w << endl;
    }

    return 0;
}