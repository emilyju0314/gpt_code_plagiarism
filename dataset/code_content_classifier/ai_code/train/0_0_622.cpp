#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Edge {
    int u, v;
};

int findParent(vector<int>& parent, int x) {
    if (parent[x] != x) {
        parent[x] = findParent(parent, parent[x]);
    }
    return parent[x];
}

void unionVertices(vector<int>& parent, int u, int v) {
    parent[findParent(parent, u)] = findParent(parent, v);
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }

    reverse(edges.begin(), edges.end());

    vector<int> parent(n + 1);
    iota(parent.begin(), parent.end(), 0);

    vector<int> ans;

    for (int i = 0; i < q; i++) {
        int type, v;
        cin >> type >> v;
        if (type == 1) {
            v = findParent(parent, v);
            int maxNum = 0;
            for (int j = 0; j < n; j++) {
                if (findParent(parent, j) == v) {
                    maxNum = max(maxNum, p[j]);
                }
            }
            for (int j = 0; j < n; j++) {
                if (findParent(parent, j) == v && p[j] == maxNum) {
                    ans.push_back(p[j]);
                    p[j] = 0;
                    break;
                }
            }
        } else {
            int idx = edges.back().u == v ? edges.back().v : edges.back().u;
            edges.pop_back();
            unionVertices(parent, idx, v);
        }
    }

    for (int a : ans) {
        cout << a << endl;
    }

    return 0;
}