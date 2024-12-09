#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int u, v;
};

int find(int x, vector<int>& parent) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = find(parent[x], parent);
}

void unite(int a, int b, vector<int>& parent) {
    a = find(a, parent);
    b = find(b, parent);
    if (a != b) {
        parent[a] = b;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }

    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    int components = n;
    for (int i = 0; i < m; i++) {
        if (find(edges[i].u, parent) != find(edges[i].v, parent)) {
            unite(edges[i].u, edges[i].v, parent);
            components--;
        }
    }

    cout << max(components - 1, 0) << endl;

    return 0;
}