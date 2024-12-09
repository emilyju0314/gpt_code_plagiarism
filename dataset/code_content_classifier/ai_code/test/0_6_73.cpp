#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;
vector<int> group_size;
vector<int> vis;
vector<pair<int, int>> edges;

int find_root(int node) {
    if (parent[node] == node) {
        return node;
    }
    return parent[node] = find_root(parent[node]);
}

bool merge_groups(int a, int b) {
    a = find_root(a);
    b = find_root(b);

    if (a == b) {
        return false; // a and b already in the same group
    }

    if (group_size[a] < group_size[b]) {
        swap(a, b);
    }

    parent[b] = a;
    group_size[a] += group_size[b];
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    parent.resize(n+1);
    group_size.resize(n+1);
    vis.resize(n+1, false);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        group_size[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});

        if (find_root(u) == find_root(v)) {
            vis[find_root(u)] = true;
        } else {
            merge_groups(u, v);
        }
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ans += (long long)group_size[i] * (group_size[i] - 1) / 2;
        }
    }

    cout << ans + m << endl;

    return 0;
}