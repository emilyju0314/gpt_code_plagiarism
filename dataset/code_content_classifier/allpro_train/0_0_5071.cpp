#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
const int MAXN = 2e5 + 5;

vector<int> adj[MAXN], seq;
int tin[MAXN], tout[MAXN], timer = 0;
vector<int> euler;

void dfs(int v, int p) {
    tin[v] = timer++;
    euler.push_back(v);
    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v);
        }
    }
    tout[v] = timer;
}

struct SegmentTree {
    vector<int> tree;

    void build(int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = (tl < seq.size() - 1) ? abs(seq[euler[tl]] - seq[euler[tl + 1]) : 0;
        } else {
            int tm = (tl + tr) / 2;
            build(v * 2, tl, tm);
            build(v * 2 + 1, tm + 1, tr);
            tree[v] = tree[v * 2] ^ tree[v * 2 + 1];
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return tree[v];
        int tm = (tl + tr) / 2;
        return query(v * 2, tl, tm, l, min(r, tm)) ^ query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            tree[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            tree[v] = tree[v * 2] ^ tree[v * 2 + 1];
        }
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    seq.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
        seq[i]--;
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    SegmentTree st;
    st.tree.resize(4 * n);
    st.build(1, 0, euler.size() - 1);

    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            l--;
            r--;
            cout << st.query(1, 0, euler.size() - 1, tin[l], tin[r] - 1) << endl;
        } else {
            int x;
            cin >> x;
            x--;
            swap(seq[x], seq[x + 1]);
            st.update(1, 0, euler.size() - 1, x, abs(seq[euler[x]] - seq[euler[x + 1]]));
            st.update(1, 0, euler.size() - 1, x + 1, abs(seq[euler[x]] - seq[euler[x + 1]]));
        }
    }

    return 0;
}