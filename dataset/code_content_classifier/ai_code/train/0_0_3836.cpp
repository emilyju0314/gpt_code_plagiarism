#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Cactus {
    int n, m;
    vector<vector<int>> paths;
    vector<int> parent;
    vector<set<int>> children;
    vector<int> depth;
    vector<int> heavy;
    vector<int> head;
    vector<int> pos;
    vector<int> segtree;
    int cur_pos;

    Cactus(int n, int m) {
        this->n = n;
        this->m = m;
        paths.resize(m);
        parent.resize(n+1);
        children.resize(n+1);
        depth.resize(n+1);
        heavy.resize(n+1, -1);
        head.resize(n+1);
        pos.resize(n+1);
        segtree.resize(4*n);
        cur_pos = 1;
    }

    void add_edge(int u, int v) {
        children[u].insert(v);
        children[v].insert(u);
    }

    void dfs(int v, int p=0, int d=0) {
        parent[v] = p;
        depth[v] = d;
        int sum = 1;
        int max_child_size = 0;
        for (int u : children[v]) {
            if (u != p) {
                dfs(u, v, d+1);
                sum += 1;
                if (sizes[u] > max_child_size) {
                    max_child_size = sizes[u];
                    heavy[v] = u;
                }
            }
        }
        sizes[v] = sum;
    }

    void decompose(int v, int h) {
        head[v] = h;
        pos[v] = cur_pos++;
        if (heavy[v] != -1) {
            decompose(heavy[v], h);
        }
        for (int u : children[v]) {
            if (u != parent[v] && u != heavy[v]) {
                decompose(u, u);
            }
        }
    }

    void build_segtree(int v, int l, int r) {
        if (l == r) {
            segtree[v] = 0;
        } else {
            int mid = l + (r - l) / 2;
            build_segtree(2*v, l, mid);
            build_segtree(2*v+1, mid+1, r);
            segtree[v] = 0; // Modify this according to actual requirements
        }
    }

    void update_segtree(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            segtree[v] = new_val;
        } else {
            int tm = tl + (tr - tl) / 2;
            if (pos <= tm) {
                update_segtree(2*v, tl, tm, pos, new_val);
            } else {
                update_segtree(2*v+1, tm+1, tr, pos, new_val);
            }
            segtree[v] = segtree[2*v] + segtree[2*v+1]; // Modify this according to actual requirements
        }
    }

    int query_segtree(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return 0; // Modify this according to actual requirements
        }
        if (l == tl && r == tr) {
            return segtree[v];
        }
        int tm = tl + (tr - tl) / 2;
        return query_segtree(2*v, tl, tm, l, min(r, tm)) + query_segtree(2*v+1, tm+1, tr, max(l, tm+1), r); // Modify this according to actual requirements
    }

    void solve() {
        // Read input
        for (int i = 0; i < m; i++) {
            int s;
            cin >> s;
            paths[i].resize(s);
            for (int j = 0; j < s; j++) {
                cin >> paths[i][j];
                if (j > 0) {
                    add_edge(paths[i][j-1], paths[i][j]);
                }
            }
        }

        // Perform necessary calculations

        // Output the result for each test case
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    while (n != 0 && m != 0) {
        Cactus c(n, m);
        c.solve();
        cin >> n >> m;
    }
    return 0;
}