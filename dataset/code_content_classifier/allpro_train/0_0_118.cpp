#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 3e5 + 5;

int n, m, q;
int parent[MAXN], sz[MAXN], depth[MAXN], max_depth[MAXN];

int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (sz[x] < sz[y]) swap(x, y);

    parent[y] = x;
    sz[x] += sz[y];
    max_depth[x] = max(max_depth[x], max(max_depth[y], (max_depth[x] + 1) / 2 + (max_depth[y] + 1) / 2 + 1));
}

void dfs(int x, int p) {
    depth[x] = depth[p] + 1;
    max_depth[x] = max(max_depth[x], depth[x]);

    for (int v = 1; v <= n; ++v) {
        if (find(v) == find(x)) {
            dfs(v, x);
        }
    }
}

int main() {
    cin >> n >> m >> q;

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        sz[i] = 1;
        depth[i] = 0;
        max_depth[i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }

    for (int i = 1; i <= n; ++i) {
        if (find(i) == i) {
            dfs(i, 0);
        }
    }

    for (int i = 0; i < q; ++i) {
        int type, x, y;
        cin >> type;

        if (type == 1) {
            cin >> x;
            cout << max_depth[find(x)] << endl;
        } else {
            cin >> x >> y;
            unite(x, y);
        }
    }

    return 0;
}