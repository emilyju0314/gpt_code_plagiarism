#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(vector<int>& parent, int u) {
    if (parent[u] == u) {
        return u;
    }
    return parent[u] = find(parent, parent[u]);
}

void merge(vector<int>& parent, int u, int v) {
    u = find(parent, u);
    v = find(parent, v);
    if (u != v) {
        parent[u] = v;
    }
}

int main() {
    int n, m;
    while (cin >> n >> m && n != 0 && m != 0) {
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < m; i++) {
            int a, b, cost;
            cin >> a >> b >> cost;
            edges.push_back({cost, {a, b}});
        }
        sort(edges.begin(), edges.end());

        int totalCost = 0;
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < m; i++) {
            int a = edges[i].second.first;
            int b = edges[i].second.second;
            int cost = edges[i].first;

            if (find(parent, a) != find(parent, b)) {
                totalCost += cost;
                merge(parent, a, b);
            }
        }

        cout << totalCost << endl;
    }

    return 0;
}