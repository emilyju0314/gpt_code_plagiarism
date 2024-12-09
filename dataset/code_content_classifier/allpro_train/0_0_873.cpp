#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 500005;
vector<pair<int, int>> adj[MAXN];
int depth[MAXN];
int up[MAXN][20];

void dfs(int v, int p, int d) {
    depth[v] = d;
    up[v][0] = p;
    for (int i = 1; i < 20; i++) {
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for (auto u : adj[v]) {
        if (u.first != p) {
            dfs(u.first, v, d + 1);
        }
    }
}

int lca(int a, int b) {
    if (depth[a] > depth[b]) swap(a, b);
    for (int i = 19; i >= 0; i--) {
        if (depth[b] - (1 << i) >= depth[a]) {
            b = up[b][i];
        }
    }
    if (a == b) return a;
    for (int i = 19; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int dist(int a, int b) {
    return depth[a] + depth[b] - 2 * depth[lca(a, b)];
}

int main() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i < n; i++) {
        int p, w;
        cin >> p >> w;
        adj[p].push_back({i + 1, w});
    }

    dfs(1, 0, 0);

    for (int i = 0; i < q; i++) {
        int v, l, r;
        cin >> v >> l >> r;
        int ans = 0;
        if (v <= r && v >= l) {
            ans = 0;
        } else {
            if (v < l) {
                ans = dist(v, l);
            } else {
                ans = dist(v, r);
            }
        }
        cout << ans << endl;
    }

    return 0;
}