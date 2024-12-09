#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

struct Edge {
    int u, v, weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (size[u] < size[v]) {
                swap(u, v);
            }
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<Edge> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].u >> edges[i].v;
        edges[i].u--;
        edges[i].v--;
        edges[i].weight = i + 1;
    }

    sort(edges.begin(), edges.end());

    long long totalWeight = 0;
    vector<Edge> minSpanningTree;
    DSU dsu(N);

    for (const Edge& e : edges) {
        if (dsu.find(e.u) != dsu.find(e.v)) {
            dsu.unite(e.u, e.v);
            totalWeight += e.weight;
            minSpanningTree.push_back(e);
        }
    }

    cout << totalWeight % MOD << endl;

    return 0;
}