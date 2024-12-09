#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

using P = pair<int, int>;

VV<int> g;
VV<int> near;
VV<V<P>> top2; //(id, length)

V<P> buf;
void unique(V<P>& v) {
    sort(v.begin(), v.end(), [&](P a, P b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    });
    v.erase(unique(v.begin(), v.end(), [&](P a, P b) {
        return a.first == b.first;
    }), v.end());
    sort(v.begin(), v.end(), [&](P a, P b) {
        return a.second > b.second;
    });
    if (v.size() > 2) v.resize(2);
}

void dfs(int p, int b, int rt, int cr, int ndp) {
    near[rt][p] = cr;
    top2[rt][p].insert(top2[rt][p].end(), buf.begin(), buf.end());
    unique(top2[rt][p]);

    buf.push_back({cr, ndp});
    unique(buf);

    for (int d: g[p]) {
        if (d == b) continue;
        dfs(d, p, rt, cr, ndp + 1);
    }
}

VV<int> to_id;

VV<bool> vis;
VV<bool> dp;

bool solve(int p, int bp, int q, int bq) {
    int id1 = to_id[p][bp], id2 = to_id[q][bq];
    if (vis[id1][id2]) return dp[id1][id2];
    vis[id1][id2] = true;

    int da = -1, db = -1;
    for (auto pi: top2[p][near[p][q]]) {
        if (pi.first == bp) continue;
        da = max(da, pi.second);
    }
    for (auto pi: top2[q][p]) {
        if (pi.first == bq) continue;
        db = max(db, pi.second);
    }
    if (da > db) return dp[id1][id2] = true;
    if (near[p][q] == q) return dp[id1][id2] = false;
    return dp[id1][id2] = !solve(q, bq, near[p][q], p);
}

int main() {
    int n;
    cin >> n;
    g = VV<int>(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    near = VV<int>(n, V<int>(n, -1));
    top2 = VV<V<P>>(n, VV<P>(n));
    for (int s = 0; s < n; s++) {
        buf.clear();
        for (int d: g[s]) {
            dfs(d, s, s, d, 1);
        }
        for (int i = 0; i < n; i++) {
            reverse(g[i].begin(), g[i].end());
        }
        buf.clear();
        for (int d: g[s]) {
            dfs(d, s, s, d, 1);
        }
    }

    to_id = VV<int>(n, V<int>(n + 1, -1));
    int idc = 0;
    for (int i = 0; i < n; i++) {
        for (int j: g[i]) {
            to_id[i][j] = idc++;
        }
        to_id[i][n] = idc++;
    }

    vis = VV<bool>(idc, V<bool>(idc));
    dp = VV<bool>(idc, V<bool>(idc));

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            ans += solve(i, n, j, n);
        }
    }

    cout << ans << endl;
    return 0;
}

