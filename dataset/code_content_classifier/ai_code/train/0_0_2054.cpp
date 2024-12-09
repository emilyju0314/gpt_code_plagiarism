#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int N, Q;
int A[MAXN];
int segTree[4 * MAXN];

void build(int node, int start, int end) {
    if (start == end) {
        segTree[node] = A[start];
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
    }
}

void update(int node, int start, int end, int idx) {
    if (start == end) {
        A[idx] = 1 - A[idx];
        segTree[node] = A[idx];
    } else {
        int mid = (start + end) / 2;
        if (idx >= start && idx <= mid) {
            update(2 * node, start, mid, idx);
        } else {
            update(2 * node + 1, mid + 1, end, idx);
        }
        segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
    }
}

int query(int node, int start, int end, int l, int r) {
    if (start > r || end < l) {
        return 0;
    } else if (start >= l && end <= r) {
        return segTree[node];
    } else {
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
    }
}

int main() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    build(1, 1, N);

    for (int i = 0; i < Q; i++) {
        int T, L, R;
        cin >> T >> L >> R;
        if (T == 1) {
            for (int j = L; j <= R; j++) {
                update(1, 1, N, j);
            }
        } else {
            cout << query(1, 1, N, L, R) << endl;
        }
    }

    return 0;
}