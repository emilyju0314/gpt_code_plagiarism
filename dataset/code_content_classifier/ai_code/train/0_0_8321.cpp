#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
};

bool sortEdges(Edge a, Edge b) {
    return a.w < b.w;
}

int find(int v, vector<int>& parent) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find(parent[v], parent);
}

void unite(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = find(a, parent);
    b = find(b, parent);
    if (a != b) {
        if (rank[a] < rank[b]) {
            swap(a, b);
        }
        parent[b] = a;
        if (rank[a] == rank[b]) {
            rank[a]++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end(), sortEdges);

    vector<int> parent(n+1), rank(n+1, 0);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int k = 0;
    for (int i = 0; i < m; i++) {
        int a = edges[i].u;
        int b = edges[i].v;
        int w = edges[i].w;
        
        if (find(a, parent) != find(b, parent)) {
            unite(a, b, parent, rank);
            k++;
        }
    }

    cout << k - 1 << endl;

    return 0;
}