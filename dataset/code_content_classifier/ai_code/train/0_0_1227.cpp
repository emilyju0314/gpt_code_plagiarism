#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1000005;

int n, q;
vector<int> p(MAXN);
vector<int> l(MAXN);
vector<int> r(MAXN);
vector<int> segtree(4*MAXN);

int build(int v, int tl, int tr) {
    if (tl == tr) {
        segtree[v] = tl;
    } else {
        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v + 1, tm + 1, tr);
        segtree[v] = (p[segtree[2*v]] > p[segtree[2*v + 1]]) ? segtree[2*v] : segtree[2*v + 1];
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == tl && r == tr) {
        return segtree[v];
    }
    int tm = (tl + tr) / 2;
    int left_index = query(2*v, tl, tm, l, min(r, tm));
    int right_index = query(2*v + 1, tm + 1, tr, max(l, tm + 1), r);
    return (p[left_index] > p[right_index]) ? left_index : right_index;
}

int calculate_f(int l, int r) {
    if (l > r) {
        return 0;
    }
    int m = query(1, 1, n, l, r);
    return (r - l + 1) + calculate_f(l, m - 1) + calculate_f(m + 1, r);
}

int main() {
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    for (int i = 1; i <= q; ++i) {
        cin >> l[i];
    }

    for (int i = 1; i <= q; ++i) {
        cin >> r[i];
    }

    build(1, 1, n);

    for (int i = 1; i <= q; ++i) {
        cout << calculate_f(l[i], r[i]) << " ";
    }

    cout << endl;

    return 0;
}