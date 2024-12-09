#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
};

struct DSU {
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (sz[a] < sz[b]) {
                swap(a, b);
            }
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<Edge> edges;

    for (int i = 0; i < Q; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        edges.push_back({A, B, C});
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    DSU dsu(N);

    long long totalWeight = 0;

    for (const Edge& edge : edges) {
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            dsu.unite(edge.u, edge.v);
            totalWeight += edge.weight;
        }
    }

    cout << totalWeight << endl;

    return 0;
}