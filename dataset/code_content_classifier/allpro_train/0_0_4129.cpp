#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 200001;
const int LOGN = 20;

int n, m, q;
vector<pair<int, pair<int, int>>> edges;
vector<pair<int, int>> queries;

int parent[MAXN], depth[MAXN], dist[MAXN];
int dp[MAXN][LOGN];

int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }
        parent[v] = u;
        depth[u] = max(depth[u], depth[v] + 1);
    }
}

void dfs(int u, int p, int d) {
    dist[u] = d;
    dp[u][0] = p;
    for (int v : edges[u]) {
        if (v != p) {
            dfs(v, u, d ^ weights[{u, v}]);
        }
    }
}

void preprocess() {
    for (int j = 1; j < LOGN; j++) {
        for (int i = 1; i <= n; i++) {
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    for (int j = LOGN - 1; j >= 0; j--) {
        if (depth[u] - (1 << j) >= depth[v]) {
            u = dp[u][j];
        }
    }
    if (u == v) {
        return u;
    }
    for (int j = LOGN - 1; j >= 0; j--) {
        if (dp[u][j] != dp[v][j]) {
            u = dp[u][j];
            v = dp[v][j];
        }
    }
    return dp[u][0];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        edges.push_back({x, y, d});
        unite(x, y);
    }

    dfs(1, 1, 0);
    preprocess();

    cin >> q;
    for (int i = 0; i < q; i++) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) {
            int d;
            cin >> d;
            edges.push_back({x, y, d});
            unite(x, y);
        } else if (type == 2) {
            // Remove edge
        } else if (type == 3) {
            int l = lca(x, y);
            int ans = dist[x] ^ dist[y] ^ dist[l];
            cout << ans << endl;
        }
    }

    return 0;
}