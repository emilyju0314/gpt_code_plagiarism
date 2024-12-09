#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;

int n, q;
vector<int> adj[MAXN];
int color[MAXN];
int par[MAXN];
int depth[MAXN];
int up[MAXN][21]; // 2^j-th ancestor
int ans;

void dfs(int u, int p) {
    par[u] = p;
    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

void preprocess() {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 20; j++) {
            up[i][j] = -1;
        }
    }

    for (int i = 1; i <= n; i++) {
        up[i][0] = par[i];
    }

    for (int j = 1; j <= 20; j++) {
        for (int i = 1; i <= n; i++) {
            if (up[i][j - 1] != -1) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);

    for (int i = 20; i >= 0; i--) {
        if (depth[a] - (1 << i) >= depth[b]) {
            a = up[a][i];
        }
    }

    if (a == b) return a;

    for (int i = 20; i >= 0; i--) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }

    return par[a];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, -1);
    preprocess();

    int last = 0;

    for (int i = 0; i < q; i++) {
        int t, z;
        cin >> t >> z;
        int x = (z + last) % n + 1;

        if (t == 1) {
            color[x] = 1;
        } else {
            int res = depth[x] + depth[last] - 2 * depth[lca(x, last)];
            cout << res << endl;
            last = x;
        }
    }

    return 0;
}