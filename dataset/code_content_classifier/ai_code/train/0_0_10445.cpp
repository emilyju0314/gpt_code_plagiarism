#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

int find(int x) {
    return x == parent[x] ? x : parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        parent[y] = x;
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    parent.resize(n + 1);
    iota(parent.begin(), parent.end(), 0);

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
        unite(edges[i].first, edges[i].second);
    }

    vector<double> ans(q, -1);
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        if (find(u) == find(v)) {
            ans[i] = -1;
        } else {
            double num_components = 0, sum_diameters = 0;
            for (auto& comp : parent) {
                if (comp == find(comp)) {
                    ++num_components;
                    int diameter = 0;
                    for (auto& edge : edges) {
                        if (find(edge.first) == comp && find(edge.second) == comp) {
                            diameter = max(diameter, 2);
                        } else if ((find(edge.first) == comp && find(edge.second) != comp) ||
                                   (find(edge.first) != comp && find(edge.second) == comp)) {
                            diameter = max(diameter, 1);
                        }
                    }
                    sum_diameters += diameter;
                }
            }
            ans[i] = sum_diameters / num_components;
        }
    }

    cout << fixed;
    cout << setprecision(10);
    for (double val : ans) {
        cout << val << endl;
    }

    return 0;
}