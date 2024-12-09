#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4+5;
const int MAXM = 5e4+5;

string s;
string t[MAXM];
vector<int> pos[MAXN];
int n, m, q;

struct SegTree {
    vector<int> tree;

    void build(int node, int start, int end, const vector<int>& v) {
        if (start == end) {
            tree[node] = v[start];
        } else {
            int mid = (start + end) / 2;
            build(2*node, start, mid, v);
            build(2*node+1, mid+1, end, v);
            tree[node] = max(tree[2*node], tree[2*node+1]);
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return max(query(2*node, start, mid, l, r), query(2*node+1, mid+1, end, l, r));
    }

    void init(const vector<int>& v) {
        int sz = v.size();
        tree.assign(4*sz, 0);
        build(1, 0, sz-1, v);
    }
};

void solve() {
    cin >> s;
    cin >> m;
    n = s.size();
    
    for (int i = 0; i < m; i++) {
        cin >> t[i];
        t[i] += '$'; // add a special character to prevent overlapping in suffixes
        for (int j = 0; j < t[i].size(); j++) {
            pos[j].push_back(i);
        }
    }

    vector<int> v(n+1);
    for (int i = 0; i < n; i++) {
        v[i] = i+1;
    }
    v[n] = 0;

    SegTree st;
    st.init(v);

    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r, pl, pr;
        cin >> l >> r >> pl >> pr;
        l--; r--; pl--; pr--;

        vector<int> cnt(m, 0);
        for (int j = pl; j <= pr; j++) {
            int start = lower_bound(pos[j].begin(), pos[j].end(), l) - pos[j].begin();
            int end = upper_bound(pos[j].begin(), pos[j].end(), r) - pos[j].begin();
            cnt[st.query(1, 0, n, start, end-1)]++;
        }

        int ans_idx = 0;
        int max_cnt = 0;
        for (int j = 0; j < m; j++) {
            if (cnt[j] > max_cnt) {
                max_cnt = cnt[j];
                ans_idx = j;
            }
        }

        cout << ans_idx + 1 << ' ' << max_cnt << endl;
    }
}

int main() {
    solve();

    return 0;
}