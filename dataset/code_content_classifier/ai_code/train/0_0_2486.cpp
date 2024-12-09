#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
};

int findParent(int v, vector<int>& parent) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = findParent(parent[v], parent);
}

void unite(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = findParent(a, parent);
    b = findParent(b, parent);

    if (rank[a] < rank[b]) {
        swap(a, b);
    }

    parent[b] = a;
    if (rank[a] == rank[b]) {
        rank[a]++;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges.push_back({i, j, a[i] ^ a[j]});
        }
    }

    sort(edges.begin(), edges.end(), [](Edge& a, Edge& b) {
        return a.weight < b.weight;
    });

    long long totalWeight = 0;
    vector<int> parent(n);
    vector<int> rank(n, 0);

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (Edge& edge : edges) {
        if (findParent(edge.u, parent) != findParent(edge.v, parent)) {
            totalWeight += edge.weight;
            unite(edge.u, edge.v, parent, rank);
        }
    }

    cout << totalWeight << endl;

    return 0;
}