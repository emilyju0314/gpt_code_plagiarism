#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
using namespace std;
template <typename T>
void uin(T &a, T b) {
  if (b < a) {
    a = b;
  }
}
template <typename T>
void uax(T &a, T b) {
  if (b > a) {
    a = b;
  }
}
const int N = 200 * 1000 + 228;
int n, m;
int go[N][20], ans[N], L[N], R[N];
struct seg {
  int l, r, id;
  seg() {}
  seg(int _l, int _r, int _id) {
    l = _l;
    r = _r;
    id = _id;
  }
};
bool operator<(seg a, seg b) { return a.l < b.l || (a.l == b.l && a.r < b.r); }
bool cmp(int i, int j) { return R[i] < R[j]; }
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<seg> v;
  for (int i = 1; i <= n; ++i) {
    int l, r;
    cin >> l >> r;
    L[i] = l;
    R[i] = r;
    v.push_back(seg(l, r, i));
  }
  sort(v.begin(), v.end());
  vector<int> order;
  for (int i = 1; i <= n; ++i) {
    order.push_back(i);
  }
  sort(order.begin(), order.end(), cmp);
  int best = 0;
  int ptr = -1;
  for (int i : order) {
    while (ptr + 1 < n && v[ptr + 1].l <= R[i]) {
      ++ptr;
      if (v[ptr].r > R[best]) {
        best = v[ptr].id;
      }
    }
    go[i][0] = best;
  }
  for (int k = 1; k < 20; ++k) {
    for (int i = 1; i <= n; ++i) {
      go[i][k] = go[go[i][k - 1]][k - 1];
    }
  }
  vector<seg> q;
  for (int i = 1; i <= m; ++i) {
    int l, r;
    cin >> l >> r;
    q.push_back({l, r, i});
  }
  sort(q.begin(), q.end());
  best = 0;
  ptr = -1;
  for (int it = 0; it < m; ++it) {
    int l = q[it].l, r = q[it].r;
    int id = q[it].id;
    while (ptr + 1 < n && v[ptr + 1].l <= l) {
      ++ptr;
      if (v[ptr].r > R[best]) {
        best = v[ptr].id;
      }
    }
    if (best == 0) {
      ans[id] = -1;
      continue;
    }
    if (R[best] >= r) {
      ans[id] = 1;
      continue;
    }
    int v = best;
    int res = 1;
    int k = 19;
    while (k >= 0) {
      if (R[go[v][k]] < r) {
        res += (1 << k);
        v = go[v][k];
      }
      --k;
    }
    ++res;
    v = go[v][0];
    if (R[v] < r) {
      ans[id] = -1;
    } else {
      ans[id] = res;
    }
  }
  for (int i = 1; i <= m; ++i) {
    cout << ans[i] << '\n';
  }
  return 0;
}
