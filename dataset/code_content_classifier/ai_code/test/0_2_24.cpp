#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

struct Edge {
    int u, v, d;
};

int n, m, q;
int w[MAXN];
vector<Edge> edges;
vector<int> incident[MAXN];
int parent[MAXN], sz[MAXN];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        if (sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        parent[y] = x;
    }
}

int main() {
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        parent[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        edges.push_back({u, v, d});
    }

    sort(edges.begin(), edges.end(), [](const Edge& e1, const Edge& e2) {
        return e1.d < e2.d;
    });

    for (int i = 0; i < q; i++) {
        int k, x;
        cin >> k >> x;
        incident[k].push_back(x);
    }

    long long total_cost = 0;
    vector<long long> costs;
    costs.push_back(0);

    for (int i = 0; i < m; i++) {
        int u = edges[i].u, v = edges[i].v, d = edges[i].d;
        int root_u = find(u), root_v = find(v);

        long long cost = 0;
        if (root_u != root_v) {
            cost = 1LL * sz[root_u] * sz[root_v] * d;
            unite(root_u, root_v);
        }

        total_cost += cost;
        costs.push_back(costs.back() + cost);

        for (int k : incident[u]) {
            cost = max((long long)k, cost);
            total_cost += cost;
            costs.push_back(costs.back() + cost);
        }

        for (int k : incident[v]) {
            cost = max((long long)k, cost);
            total_cost += cost;
            costs.push_back(costs.back() + cost);
        }
    }

    for (int i = 1; i <= q; i++) {
        cout << total_cost - costs[n + i] << "\n";
    }

    return 0;
}