#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight, id;
    
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
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

        if (u == v) return;

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

    vector<Edge> edges(m);
    vector<int> answer(m, -1);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        edges[i].id = i;
        edges[i].u--;
        edges[i].v--;
    }

    sort(edges.begin(), edges.end());

    DisjointSet dsu(n);

    vector<int> maxWeightConnectedToEdge(m, INT_MAX);

    for (int i = 0; i < m; i++) {
        Edge currentEdge = edges[i];

        int u = currentEdge.u;
        int v = currentEdge.v;

        if (dsu.find(u) != dsu.find(v)) {
            answer[currentEdge.id] = maxWeightConnectedToEdge[currentEdge.id];
        }

        dsu.merge(u, v);

        maxWeightConnectedToEdge[dsu.find(u)] = min(maxWeightConnectedToEdge[dsu.find(u)], currentEdge.weight);
    }

    for (int i = 0; i < m; i++) {
        cout << answer[i] << " ";
    }

    return 0;
}