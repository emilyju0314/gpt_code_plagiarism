#include <iostream>
#include <vector>

using namespace std;

const int INF = 2147483647;

struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(int size) {
        n = 1;
        while(n < size) n *= 2;
        tree.assign(2 * n - 1, INF);
    }

    void update(int i, int x) {
        i += n - 1;
        tree[i] = x;
        while(i > 0) {
            i = (i - 1) / 2;
            tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
        }
    }

    int find(int a, int b, int k = 0, int l = 0, int r = -1) {
        if(r == -1) r = n;

        if(r <= a || b <= l) return INF;
        if(a <= l && r <= b) return tree[k];

        int vl = find(a, b, 2 * k + 1, l, (l + r) / 2);
        int vr = find(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(vl, vr);
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    SegmentTree st(n);

    for(int i = 0; i < q; i++) {
        int com, x, y;
        cin >> com >> x >> y;
        
        if(com == 0) {
            st.update(x, y);
        } else {
            cout << st.find(x, y + 1) << endl;
        }
    }

    return 0;
}