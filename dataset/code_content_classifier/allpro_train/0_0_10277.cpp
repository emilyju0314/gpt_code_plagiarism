#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
};

bool cmp(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

struct DSU {
    vector<int> parent;
    vector<int> sz;

    DSU(int n) {
        parent.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int a, int b) {
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
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end(), cmp);

    DSU dsu(n+1);

    int q;
    cin >> q;

    while (q--) {
        int k;
        cin >> k;

        vector<int> query(k);
        for (int i = 0; i < k; i++) {
            cin >> query[i];
        }

        DSU temp_dsu(n+1);
        int total_weight = 0;
        for (int i = 0; i < k; i++) {
            int idx = query[i] - 1;
            total_weight += edges[idx].w;
            temp_dsu.merge(edges[idx].u, edges[idx].v);
        }

        bool is_possible = true;
        for (int i = 1; i <= n; i++) {
            if (temp_dsu.find(i) != temp_dsu.find(1)) {
                is_possible = false;
                break;
            }
        }

        if (is_possible && temp_dsu.sz[1] == n) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}