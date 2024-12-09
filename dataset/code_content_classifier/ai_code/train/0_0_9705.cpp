#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
};

const int MAXN = 5e5 + 5;

int parent[MAXN];
int size[MAXN];
int profit[MAXN];
vector<Edge> edges;
vector<int> adj[MAXN];

int find(int u) {
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    if (size[u] < size[v])
        swap(u, v);
    parent[v] = u;
    size[u] += size[v];
    profit[u] += profit[v];
}

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 1;
    }

    for (int i = 1; i <= k; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        merge(u, v);
    }

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });

    long long total_profit = 0;

    for (Edge& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;

        if (find(u) == find(v))
            continue;

        if (adj[u].size() == 1 && adj[v].size() == 1)
            total_profit += w;
        else {
            merge(u, v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (find(i) == i && size[i] > 1) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << total_profit << endl;

    return 0;
}