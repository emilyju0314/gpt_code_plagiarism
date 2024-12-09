#include <bits/stdc++.h>
using namespace std;

vector<int> parent, sz;

int find(int v) {
    return v == parent[v] ? v : parent[v] = find(parent[v]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        sz[a] += sz[b];
        parent[b] = a;
    }
}

double getExpectedDiameter(int n, vector<pair<int, int>>& edges, vector<pair<int, int>>& queries) {
    parent.resize(n + 1);
    sz.assign(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    vector<int> diameters(n + 1, 0);

    for (auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        unite(u, v);
    }

    for (int i = 1; i <= n; i++) {
        diameters[find(i)] = max(diameters[find(i)], 0);
    }

    double total = 0;

    for (auto& query : queries) {
        int u = query.first;
        int v = query.second;

        int pu = find(u);
        int pv = find(v);

        if (pu == pv) {
            cout << "-1\n";
            continue;
        }

        double diameter = max({diameters[pu], diameters[pv], (diameters[pu] + diameters[pv] + 1) / 2.0 + 1});
        cout << fixed << setprecision(10) << diameter << endl;

        total += diameter;
    }

    return total;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<int, int>> edges(m), queries(q);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    for (int i = 0; i < q; i++) {
        cin >> queries[i].first >> queries[i].second;
    }

    getExpectedDiameter(n, edges, queries);

    return 0;
}