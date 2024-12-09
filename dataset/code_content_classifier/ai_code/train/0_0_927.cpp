#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 500005;
vector<int> adj[MAXN];
int dist[MAXN], ans[MAXN], visited[MAXN];

int dfs(int u, int parent) {
    visited[u] = 1;
    int max_dist = 0;
    for (int v : adj[u]) {
        if (v == parent) continue;
        max_dist = max(max_dist, dfs(v, u) + 1);
    }
    return dist[u] = max_dist;
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] < dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            if (dist[u] == dist[v] + 1) {
                vector<int> subtree;
                int cur = u;
                while (dist[cur] > dist[v]) {
                    subtree.push_back(cur);
                    visited[cur] = 1;
                    cur = adj[cur][0];
                }
                for (int leaf : subtree) {
                    if (!visited[leaf]) {
                        bfs(leaf);
                        break;
                    }
                }
                for (int leaf : subtree) {
                    ans[u] = max(ans[u], dist[leaf]);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}