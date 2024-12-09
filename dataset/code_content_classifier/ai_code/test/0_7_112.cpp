#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 100005;
int n, m, q;
vector<pair<int, char>> adj[MAXN];
char str[MAXN];
int tin[MAXN], tout[MAXN], timer = 0;
int up[MAXN][20];
int depth[MAXN];

void dfs(int v, int p, int d) {
    tin[v] = ++timer;
    up[v][0] = p;
    depth[v] = d;
    for (int i = 1; i < 20; i++) {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for (auto u : adj[v]) {
        if (u.first != p) {
            dfs(u.first, v, d + 1);
        }
    }
    tout[v] = ++timer;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = 19; i >= 0; i--) {
        if (!is_ancestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

int main() {
    cin >> n >> m >> q;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }
    dfs(1, 1, 0);
    
    for (int i = 0; i < m; i++) {
        cin >> str;
    }

    while (q--) {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        int ancestor = lca(u, v);
        int answer = 0;
        for (int i = 0; i < m; i++) {
            int u_depth = depth[u] - depth[ancestor];
            int v_depth = depth[v] - depth[ancestor];
            if (u_depth + v_depth < r) continue;
            if (u_depth + v_depth > r + 1) continue;
            int node = (u_depth > v_depth) ? u : v;
            int dist = depth[node] - depth[ancestor];
            if (dist >= l - 1 && dist <= r - 1) {
                for (int j = 0; j < dist - l + 2; j++) {
                    if (str[i + j] == adj[node][dist - j].second) {
                        answer++;
                    }
                }
            }
        }
        cout << answer << endl;
    }

    return 0;
}