#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int sum;
};

class SegmentTree {
private:
    vector<Node> st;
    int size;

    void build(int v, int tl, int tr) {
        if (tl == tr) {
            st[v] = {0};
        } else {
            int tm = (tl + tr) / 2;
            build(v*2, tl, tm);
            build(v*2+1, tm+1, tr);
            st[v] = {0};
        }
    }

    int sum(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return st[v].sum;
        int tm = (tl + tr) / 2;
        return sum(v*2, tl, tm, l, min(r, tm))
               + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
    }

    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            st[v].sum = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            st[v].sum = st[v*2].sum + st[v*2+1].sum;
        }
    }

public:
    SegmentTree(int n) {
        size = n;
        st.resize(4*n);
        build(1, 0, n-1);
    }

    int sum(int l, int r) {
        return sum(1, 0, size-1, l, r);
    }

    void update(int pos, int new_val) {
        update(1, 0, size-1, pos, new_val);
    }
};

int main() {
    int n;
    cin >> n;

    SegmentTree st(n);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        
        int res = st.sum(0, a-1) + a;
        cout << res << "\n";
        
        st.update(a-1, a);
    }

    return 0;
}