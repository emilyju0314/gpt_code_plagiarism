#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
};

bool compareEdges(Edge& e1, Edge& e2) {
    return e1.weight < e2.weight;
}

int findParent(vector<int>& parent, int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = findParent(parent, parent[x]);
}

void unionSets(vector<int>& parent, int x, int y) {
    int rootX = findParent(parent, x);
    int rootY = findParent(parent, y);
    if (rootX != rootY) {
        parent[rootX] = rootY;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    sort(edges.begin(), edges.end(), compareEdges);

    vector<int> parent(n + 1);
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    int maxWeight = -1;

    for (Edge& edge : edges) {
        if (findParent(parent, edge.u) != findParent(parent, edge.v)) {
            unionSets(parent, edge.u, edge.v);
            maxWeight = max(maxWeight, edge.weight);
        }
    }

    for (int i = 2; i <= n; i++) {
        if (findParent(parent, i) != findParent(parent, i - 1)) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << maxWeight << endl;

    return 0;
}