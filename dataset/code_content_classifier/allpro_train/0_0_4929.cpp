#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

int find(vector<int>& parent, int x) {
    if (parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void Union(vector<int>& parent, int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);
    parent[rootY] = rootX;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }

    vector<int> result(m, 0);
    vector<int> parent(n + 1);
    for (int i = 0; i < m; ++i) {
        for (int j = 1; j <= n; ++j) {
            parent[j] = j;
        }
        int count = 0;
        int totalWeight = 0;
        for (int j = 0; j < m; ++j) {
            if (j == i) 
                continue;

            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            int rootU = find(parent, u);
            int rootV = find(parent, v);

            if (rootU != rootV) {
                Union(parent, rootU, rootV);
                count++;
                totalWeight += w;
            }
        }

        if (count == n - 1)
            result[i] = totalWeight;
        else
            result[i] = -1;
    }

    for (int cost : result) {
        cout << cost << endl;
    }

    return 0;
}