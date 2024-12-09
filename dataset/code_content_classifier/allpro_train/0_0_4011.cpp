#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    vector<int> tree;
    int n;

    SegmentTree(int sz) {
        n = 1;
        while (n < sz) n *= 2;
        tree.resize(2 * n);
    }

    void update(int idx, int val) {
        idx += n;
        tree[idx] = max(tree[idx], val);
        for (idx /= 2; idx > 0; idx /= 2) {
            tree[idx] = max(tree[2*idx], tree[2*idx+1]);
        }
    }

    int query(int l, int r) {
        l += n;
        r += n;
        int res = 0;
        while (l < r) {
            if (l % 2 == 1) res = max(res, tree[l++]);
            if (r % 2 == 1) res = max(res, tree[--r]);
            l /= 2;
            r /= 2;
        }
        return res;
    }
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> cities;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        cities.push_back({x, y});
    }

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int L, R;
        cin >> L >> R;

        SegmentTree seg(n);

        for (int j = k; j < n; j++) {
            int x = (1LL * a * cities[j-1].first + b) % (109 + 9);
            int y = (1LL * c * cities[j-1].second + d) % (109 + 9);
            cities.push_back({x, y});
        }

        sort(cities.begin(), cities.end());

        int maxPairs = 0, idx = 0;
        for (int j = 0; j < n; j++) {
            while (cities[idx].first < L && idx < n) {
                seg.update(cities[idx].first, cities[idx].second);
                idx++;
            }
            if (idx < n && cities[j].first >= L && cities[j].first <= R) {
                int maxY = seg.query(L, cities[j].first);
                if (maxY < cities[j].second) {
                    maxPairs++;
                }
            }
        }

        cout << maxPairs << endl;
    }

    return 0;
}