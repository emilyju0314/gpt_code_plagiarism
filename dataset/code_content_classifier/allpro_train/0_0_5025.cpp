#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN], euler, segtree;

void eulerTour(int node, int parent) {
    euler.push_back(node);
    for (int u : adj[node]) {
        if (u != parent) {
            eulerTour(u, node);
            euler.push_back(node);
        }
    }
}

void buildSegmentTree(int index, int left, int right) {
    if (left == right) {
        segtree[index] = euler[left];
        return;
    }

    int mid = (left + right) / 2;
    buildSegmentTree(2 * index, left, mid);
    buildSegmentTree(2 * index + 1, mid + 1, right);

    segtree[index] = min(segtree[2 * index], segtree[2 * index + 1]);
}

int querySegmentTree(int index, int left, int right, int l, int r) {
    if (r < left || right < l) return MAXN;
    if (l <= left && right <= r) return segtree[index];

    int mid = (left + right) / 2;
    return min(querySegmentTree(2 * index, left, mid, l, r),
               querySegmentTree(2 * index + 1, mid + 1, right, l, r));
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
    }

    for (int i = 2; i <= n; i++) {
        int d;
        cin >> d;
        adj[d].push_back(i);
    }

    eulerTour(1, -1);
    segtree.resize(4 * euler.size());
    buildSegmentTree(1, 0, euler.size() - 1);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int i, j;
            cin >> i >> j;
            // Swap values at nodes i and j
            swap(euler[i-1], euler[j-1]);
        } else {
            // Find maximum value of MEX(V(l)) in all possible paths
            int l = 0, r = euler.size() - 1;
            int ans = querySegmentTree(1, 0, euler.size() - 1, l, r);
            cout << ans << endl;
        }
    }

    return 0;
}