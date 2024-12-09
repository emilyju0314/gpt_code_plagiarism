#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, w;
};

struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
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

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (size[x] < size[y]) {
                swap(x, y);
            }
            parent[y] = x;
            size[x] += size[y];
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        edges[i].u--;
        edges[i].v--;
    }

    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    DSU dsu(n);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        
        vector<int> query(k);
        for (int j = 0; j < k; j++) {
            cin >> query[j];
            query[j]--;
        }

        DSU dsu_copy = dsu;

        for (int j = 0; j < k; j++) {
            dsu_copy.merge(edges[query[j]].u, edges[query[j]].v);
        }

        bool flag = true;
        for (int j = 0; j < n; j++) {
            if (dsu_copy.find(j) != dsu_copy.find(0)) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}