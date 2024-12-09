#include <bits/stdc++.h>
using namespace std;

const int mod = 95542721;

vector<long long> tree;
vector<int> lazy;

void build(int node, int start, int end, vector<int>& arr) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid, arr);
        build(2 * node + 1, mid + 1, end, arr);
        tree[node] = (tree[2 * node] + tree[2 * node + 1]) % mod;
    }
}

void update(int node, int start, int end, int l, int r) {
    if (lazy[node] != 0) {
        tree[node] = (end - start + 1) * lazy[node] % mod;
        if (start != end) {
            lazy[2 * node] = lazy[node];
            lazy[2 * node + 1] = lazy[node];
        }
        lazy[node] = 0;
    }

    if (start > r || end < l) {
        return;
    }

    if (start >= l && end <= r) {
        tree[node] = (end - start + 1) * pow(tree[node], 3) % mod;
        if (start != end) {
            lazy[2 * node] = pow(lazy[2 * node], 3);
            lazy[2 * node + 1] = pow(lazy[2 * node + 1], 3);
        }
    } else {
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r);
        update(2 * node + 1, mid + 1, end, l, r);
        tree[node] = (tree[2 * node] + tree[2 * node + 1]) % mod;
    }
}

long long query(int node, int start, int end, int l, int r) {
    if (lazy[node] != 0) {
        tree[node] = (end - start + 1) * lazy[node] % mod;
        if (start != end) {
            lazy[2 * node] = lazy[node];
            lazy[2 * node + 1] = lazy[node];
        }
        lazy[node] = 0;
    }

    if (start > r || end < l) {
        return 0;
    }

    if (start >= l && end <= r) {
        return tree[node];
    }

    int mid = (start + end) / 2;
    long long p1 = query(2 * node, start, mid, l, r);
    long long p2 = query(2 * node + 1, mid + 1, end, l, r);

    return (p1 + p2) % mod;
}

int main() {
    int n, q;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sz = 4 * n;
    tree.assign(sz, 0);
    lazy.assign(sz, 0);
    build(1, 0, n - 1, arr);

    cin >> q;
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            long long ans = query(1, 0, n - 1, l - 1, r - 1);
            cout << ans << endl;
        } else {
            update(1, 0, n - 1, l - 1, r - 1);
        }
    }

    return 0;
}