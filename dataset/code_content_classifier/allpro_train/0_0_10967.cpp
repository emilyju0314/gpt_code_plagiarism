#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
int parent[MAXN];
int depth[MAXN];
int dp[MAXN][20];
int dp_min[MAXN][20];
int n;

void dfs(int u, int p, int d) {
    parent[u] = p;
    depth[u] = d;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
}

void preprocess() {
    for (int u = 1; u <= n; u++) {
        dp[u][0] = parent[u];
        dp_min[u][0] = u;
    }

    for (int j = 1; (1 << j) < n; j++) {
        for (int u = 1; u <= n; u++) {
            dp[u][j] = dp[dp[u][j - 1]][j - 1];
            dp_min[u][j] = min(dp_min[u][j - 1], dp_min[dp[u][j - 1]][j - 1]);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }

    int log = 1;
    while ((1 << log) <= depth[u]) {
        log++;
    }

    for (int i = log; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = dp[u][i];
        }
    }

    if (u == v) {
        return u;
    }

    for (int i = log; i >= 0; i--) {
        if (dp[u][i] != dp[v][i]) {
            u = dp[u][i];
            v = dp[v][i];
        }
    }

    return parent[u];
}

int query(int x, int k) {
    int ans = n + 1;
    for (int j = 0; j < 20; j++) {
        if ((k >> j) & 1) {
            ans = min(ans, dp_min[x][j]);
            x = dp[x][j];
        }
    }

    return ans;
}

int main() {
    int r;
    cin >> n >> r;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
    }

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(r, 0, 1);
    preprocess();

    int m;
    cin >> m;

    int last = 0;
    for (int i = 0; i < m; i++) {
        int p, q;
        cin >> p >> q;
        int xi = ((p + last) % n) + 1;
        int ki = (q + last) % n;

        int ans = query(xi, ki);
        cout << ans << endl;
        last = ans;
    }

    return 0;
}