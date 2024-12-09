#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
vector<vector<int>> adj;
vector<int> dist;

void bfs(int start, int q) {
    dist.assign(adj.size(), INF);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> volunteers(k);
    for (int i = 0; i < k; i++) {
        cin >> volunteers[i];
        volunteers[i]--;
    }

    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int s, t;
    cin >> s >> t;
    s--; t;

    int ans = -1;

    for (int volunteer : volunteers) {
        bfs(volunteer, -1);
        if (dist[s] == INF) continue;

        bfs(s, dist[t]);

        if (dist[t] != INF) {
            if (ans == -1 || ans < dist[t]) {
                ans = dist[t];
            }
        }
    }

    cout << ans << endl;

    return 0;
}