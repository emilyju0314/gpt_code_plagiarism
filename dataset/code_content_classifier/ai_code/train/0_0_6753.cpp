#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int max_val;
    int add_val;
};

class SegmentTree {
private:
    int n;
    vector<Node> tree;

public:
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n);
    }

    void build(vector<pair<int, int>>& arr, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v].max_val = max(arr[tl].first, arr[tl].second);
            tree[v].add_val = 0;
        } else {
            int tm = (tl + tr) / 2;
            build(arr, v * 2, tl, tm);
            build(arr, v * 2 + 1, tm + 1, tr);
            tree[v].max_val = max(tree[v * 2].max_val, tree[v * 2 + 1].max_val);
            tree[v].add_val = 0;
        }
    }

    void push(int v) {
        tree[v * 2].add_val += tree[v].add_val;
        tree[v * 2 + 1].add_val += tree[v].add_val;
        tree[v].add_val = 0;
    }

    void update(int v, int tl, int tr, int l, int r, int val) {
        if (l > r) {
            return;
        }
        if (l == tl && r == tr) {
            tree[v].add_val += val;
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, min(r, tm), val);
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
            tree[v].max_val = max(tree[v * 2].max_val + tree[v * 2].add_val, tree[v * 2 + 1].max_val + tree[v * 2 + 1].add_val);
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return INT_MIN;
        }
        if (l == tl && r == tr) {
            return tree[v].max_val + tree[v].add_val;
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            return max(query(v * 2, tl, tm, l, min(r, tm)), query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
        }
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<pair<int, int>> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    SegmentTree st(N);
    st.build(arr, 1, 0, N - 1);

    for (int i = 0; i < Q; i++) {
        int query_type;
        cin >> query_type;
        
        if (query_type == 1) {
            int L, R, X;
            cin >> L >> R >> X;
            st.update(1, 0, N - 1, L - 1, R - 1, X);
        } else if (query_type == 2) {
            int L, R;
            cin >> L >> R;
            int result = st.query(1, 0, N - 1, L - 1, R - 1);
            cout << result << endl;
        }
    }

    return 0;
}