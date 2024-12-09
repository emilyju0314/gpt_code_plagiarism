#include<bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

vector<int> segmentTree;

void buildSegmentTree(vector<int>& arr, int v, int tl, int tr) {
    if (tl == tr) {
        segmentTree[v] = arr[tl];
    } else {
        int tm = (tl + tr) / 2;
        buildSegmentTree(arr, v*2, tl, tm);
        buildSegmentTree(arr, v*2+1, tm+1, tr);
        segmentTree[v] = min(segmentTree[v*2], segmentTree[v*2+1]);
    }
}

void update(int v, int tl, int tr, int l, int r, int x) {
    if (l > r) return;
    if (l == tl && r == tr) {
        segmentTree[v] = x;
    } else {
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), x);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, x);
        segmentTree[v] = min(segmentTree[v*2], segmentTree[v*2+1]);
    }
}

int find(int v, int tl, int tr, int l, int r) {
    if (l > r) return INF;
    if (l == tl && r == tr) {
        return segmentTree[v];
    }
    int tm = (tl + tr) / 2;
    return min(find(v*2, tl, tm, l, min(r, tm)),
               find(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n, INF);
    segmentTree.resize(4*n);

    buildSegmentTree(arr, 1, 0, n-1);

    for (int i = 0; i < q; i++) {
        int type, s, t, x;
        cin >> type >> s >> t;

        if (type == 0) {
            cin >> x;
            update(1, 0, n-1, s, t, x);
        } else {
            cout << find(1, 0, n-1, s, t) << endl;
        }
    }

    return 0;
}