#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
};

struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (rank[x] < rank[y]) {
                swap(x, y);
            }
            parent[y] = x;
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        edges[i].u--;
        edges[i].v--;
    }

    sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) {
        return a.weight < b.weight;
    });

    DisjointSet dsu(n);

    vector<int> ans(m);
    int total_weight = 0;
    for (int i = 0; i < m; i++) {
        Edge e = edges[i];
        int u = e.u, v = e.v, weight = e.weight;
        if (dsu.find(u) != dsu.find(v)) {
            total_weight += weight;
            dsu.unite(u, v);
        }
        ans[i] = total_weight;
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}