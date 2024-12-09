#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w, c, idx;
};

struct DSU {
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (rank[u] < rank[v]) {
            swap(u, v);
        }
        parent[v] = u;
        if (rank[u] == rank[v]) {
            rank[u]++;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> w(m), c(m);
    for (int i = 0; i < m; ++i) {
        cin >> w[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> c[i];
    }

    vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v, w[i], c[i], i+1});
    }

    int S;
    cin >> S;

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });

    DSU dsu(n+1);
    vector<pair<int, int>> main_roads;
    long long total_dissatisfaction = 0;

    for (const auto& edge : edges) {
        int u = edge.u, v = edge.v, c = edge.c, idx = edge.idx;

        if (dsu.find(u) != dsu.find(v)) {
            total_dissatisfaction += edge.w;
            main_roads.emplace_back(idx, 0);
            if (S >= c) {
                S -= c;
                main_roads.back().second = -c;
            }

            dsu.merge(u, v);
        }
    }

    cout << total_dissatisfaction << endl;
    for (const auto& road : main_roads) {
        cout << road.first << " " << road.second << endl;
    }

    return 0;
}