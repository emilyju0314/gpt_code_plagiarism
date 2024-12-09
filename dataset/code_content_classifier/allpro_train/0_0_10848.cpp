#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
vector<int> graph[MAXN];
int parent[MAXN];
int depth[MAXN];
int dp[MAXN][18];

void dfs(int u, int p, int d) {
    parent[u] = p;
    depth[u] = d;
    dp[u][0] = p;
    for (int i = 1; i < 18; i++) {
        dp[u][i] = dp[dp[u][i-1]][i-1];
    }
    for (int v : graph[u]) {
        if (v != p) {
            dfs(v, u, d+1);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = 17; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = dp[u][i];
        }
    }
    if (u == v) return u;
    for (int i = 17; i >= 0; i--) {
        if (dp[u][i] != dp[v][i]) {
            u = dp[u][i];
            v = dp[v][i];
        }
    }
    return parent[u];
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        graph[a].push_back(i);
    }

    dfs(1, 0, 0);

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            for (int i = l; i <= r; i++) {
                parent[i] = max(parent[i] - x, 1);
            }
        } else {
            int u, v;
            cin >> u >> v;
            cout << lca(u, v) << endl;
        }
    }

    return 0;
}