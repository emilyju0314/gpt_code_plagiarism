#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int weight, included;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    vector<int> min_tree_edges;

    for (int i = 0; i < m; i++) {
        cin >> edges[i].weight >> edges[i].included;
        if (edges[i].included == 1) {
            min_tree_edges.push_back(i);
        }
    }

    if (min_tree_edges.size() != n - 1) {
        cout << -1 << endl;
        return 0;
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    vector<int> parent(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int components = n;
    for (int e : min_tree_edges) {
        int u, v;
        cin >> u >> v;
        u--, v--;

        while (parent[u] != u) u = parent[u];
        while (parent[v] != v) v = parent[v];

        if (u != v) {
            cout << u + 1 << " " << v + 1 << endl;
            parent[u] = v;
            components--;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < m; i++) {
        if (edges[i].included == 0 && components > 1) {
            int u, v;
            cin >> u >> v;
            u--, v--;

            while (parent[u] != u) u = parent[u];
            while (parent[v] != v) v = parent[v];

            if (u != v) {
                cout << u + 1 << " " << v + 1 << endl;
                parent[u] = v;
                components--;
            } else {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    return 0;
}