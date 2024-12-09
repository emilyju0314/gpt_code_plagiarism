#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
};

bool compareEdges(Edge a, Edge b) {
    return a.w < b.w;
}

int find(int x, vector<int>& parent) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x], parent);
}

void unite(int x, int y, vector<int>& parent) {
    x = find(x, parent);
    y = find(y, parent);
    parent[y] = x;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end(), compareEdges);

    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    long long totalWeight = 0;

    for (int i = 0; i < m; i++) {
        if (find(edges[i].u, parent) != find(edges[i].v, parent)) {
            unite(edges[i].u, edges[i].v, parent);
            totalWeight += edges[i].w;
        }
    }

    long long xorSum = 0;
    for (int i = 1; i < n; i++) {
        xorSum ^= i;
    }

    cout << totalWeight + xorSum << endl;

    return 0;
}