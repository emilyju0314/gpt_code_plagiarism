#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int N, M;
int parent[MAXN], size[MAXN], cycle[MAXN];

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v) {
        cycle[u] = 1;
        return;
    }

    if (size[u] < size[v]) swap(u, v);
    parent[v] = u;
    size[u] += size[v];
    cycle[u] |= cycle[v];
}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        size[i] = 1;
        cycle[i] = 0;
    }

    long long ans = 0;
    int components = N;

    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;

        if (find(u) != find(v)) {
            unite(u, v);
            components--;
        }

        if (components == 1) {
            ans += i;
        }
    }

    cout << ans << endl;

    return 0;
}