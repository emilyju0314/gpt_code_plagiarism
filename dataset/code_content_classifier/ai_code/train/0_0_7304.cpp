#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct SegmentTree {
    vector<long long> tree;
    int size;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, 0);
    }

    void update(int idx, long long val) {
        idx += size;
        tree[idx] = val;
        idx /= 2;
        while (idx > 0) {
            tree[idx] = max(tree[2*idx], tree[2*idx+1]);
            idx /= 2;
        }
    }

    long long query(int l, int r) {
        l += size;
        r += size;
        long long res = 0;
        while (l <= r) {
            if (l % 2 == 1) res = max(res, tree[l]);
            if (r % 2 == 0) res = max(res, tree[r]);
            l = (l + 1) / 2;
            r = (r - 1) / 2;
        }
        return res;
    }
};

int main() {
    long long h;
    int n, m, k;
    cin >> h >> n >> m >> k;

    vector<long long> cell_treasures(h + 1, 0);
    set<pair<int, long long>> treasures_set; // Store the treasures in each cell

    for (int i = 0; i < n; i++) {
        int a, c;
        cin >> a >> c;
        cell_treasures[a] = c;
        treasures_set.insert({a, c});
    }

    SegmentTree segtree;
    segtree.init(h);
    for (int i = 1; i <= h; i++) {
        if (i <= k) segtree.update(i, cell_treasures[i]);
    }

    for (int i = 0; i < m; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            k = x;
            for (int j = 1; j <= h; j++) {
                if (j <= k) {
                    segtree.update(j, cell_treasures[j]);
                } else {
                    segtree.update(j, 0);
                }
            }
        } else if (op == 2) {
            int x;
            long long y;
            cin >> x >> y;
            auto it = treasures_set.lower_bound({x, 0});
            int cell = it->first;
            long long new_val = it->second - y;
            treasures_set.erase(it);
            treasures_set.insert({cell, new_val});
            if (cell <= k) {
                segtree.update(cell, new_val);
            }
        } else {
            long long max_treasure = segtree.query(1, h);
            if (max_treasure > 0) {
                auto it = treasures_set.lower_bound({1, 0});
                int cell = it->first;
                cout << max_treasure << endl;
                segtree.update(cell, 0);
                treasures_set.erase(it);
            } else {
                cout << "0" << endl;
            }
        }
    }

    return 0;
}