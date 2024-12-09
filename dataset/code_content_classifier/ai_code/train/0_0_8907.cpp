#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
    
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int find(vector<int>& parent, int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent, parent[x]);
}

bool unite(vector<int>& parent, int x, int y) {
    x = find(parent, x);
    y = find(parent, y);
    if (x != y) {
        parent[x] = y;
        return true;
    }
    return false;
}

int kruskal(vector<Edge>& edges, int n) {
    sort(edges.begin(), edges.end());
    vector<int> parent(n);
    iota(parent.begin(), parent.end(), 0);
    int slimness = 1e9;

    for (const auto& edge : edges) {
        vector<int> tmp_parent = parent;
        int cnt = 0, mn = 1e9, mx = 0;
        for (const auto& e : edges) {
            if (unite(tmp_parent, e.u, e.v)) {
                cnt++;
                mn = min(mn, e.w);
                mx = max(mx, e.w);
            }
            if (cnt == n - 1)
                break;
        }
        if (cnt == n - 1)
            slimness = min(slimness, mx - mn);
    }

    if (slimness == 1e9)
        return -1;
    return slimness;
}

int main() {
    int n, m;
    while (cin >> n >> m && n != 0) {
        vector<Edge> edges(m);
        for (int i = 0; i < m; i++) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
        }
        int result = kruskal(edges, n);
        cout<< result << endl;
    }
    return 0;
}