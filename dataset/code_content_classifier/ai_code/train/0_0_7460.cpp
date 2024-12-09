#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<int> dist;
vector<bool> visited;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int k;
    cin >> k;

    vector<int> path(k);
    for (int i = 0; i < k; i++) {
        cin >> path[i];
    }

    dist.assign(n + 1, 0);
    visited.assign(n + 1, false);
    bfs(path[0]);

    int min_rebuilds = 0, max_rebuilds = 0;
    for (int i = 1; i < k - 1; i++) {
        if (dist[path[i + 1]] != dist[path[i]] + 1) {
            min_rebuilds++;
            max_rebuilds++;
        }
    }

    cout << min_rebuilds << " " << max_rebuilds << endl;

    return 0;
}