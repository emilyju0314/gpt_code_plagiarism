#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
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

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else {
            parent[py] = px;
            if (rank[px] == rank[py]) {
                rank[px]++;
            }
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<pair<int, int>, int>> paths(m);
    vector<int> ans(m, -1);
    DisjointSet ds(n);

    for (int i = 0; i < m; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        a--; b--;

        paths[i] = {{a, b}, l};

        if (ds.find(a) != ds.find(b)) {
            int max_edge = max(l, max_edge);
            ans[i] = max_edge;

            ds.unite(a, b);
        }
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}