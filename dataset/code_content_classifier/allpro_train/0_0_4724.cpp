#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 1005;
const int MAXM = 200005;

int n, m, q;
vector<int> adj[MAXN];
int start[MAXN], end[MAXN];
int dist[MAXN][MAXN];
bool visited[MAXN][MAXN];

void bfs(int s) {
    queue<int> que;
    que.push(s);
    visited[s][s] = true;
    dist[s][s] = 0;

    while (!que.empty()) {
        int u = que.front();
        que.pop();

        for (int v : adj[u]) {
            if (!visited[s][v]) {
                visited[s][v] = true;
                dist[s][v] = dist[s][u] + 1;
                que.push(v);
            }
        }
    }
}

int main() {
    cin >> n >> m >> q;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        memset(visited[i], false, sizeof(visited[i]));
        bfs(i);
    }

    for (int i = 0; i < q; i++) {
        int l, r, s, t;
        cin >> l >> r >> s >> t;

        if (dist[s][t] <= r && dist[s][t] <= r - l) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}