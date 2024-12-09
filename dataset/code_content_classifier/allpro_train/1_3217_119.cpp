#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9 + 7;
const int N = 1e5 + 5;
struct elm {
  int s[4];
  elm() { memset(s, 0, sizeof s); }
};
bool operator<(const elm& l, const elm& r) {
  return (l.s[0] < r.s[0]) || (l.s[0] == r.s[0] && l.s[1] < r.s[1]);
}
elm a[N];
int st[16 * N], lazy[16 * N], n;
void intist() {
  memset(st, 0, sizeof st);
  memset(lazy, 0, sizeof lazy);
}
void down(int id, int l, int r) {
  if (l != r) {
    int mid = (l + r) / 2;
    st[id * 2] += (mid - l + 1) * lazy[id];
    st[id * 2 + 1] += (r - (mid + 1) + 1) * lazy[id];
    lazy[id * 2] += lazy[id];
    lazy[id * 2 + 1] += lazy[id];
  }
  lazy[id] = 0;
}
void update(int id, int l, int r, int u, int v, int val) {
  down(id, l, r);
  if (v < l || r < u) return;
  if (u <= l && r <= v) {
    st[id] += (r - l + 1) * val;
    lazy[id] += val;
  } else {
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    st[id] = st[id * 2] + st[id * 2 + 1];
  }
}
int get(int id, int l, int r, int u, int v) {
  down(id, l, r);
  if (v < l || r < u) return 0;
  if (u <= l && r <= v) return st[id];
  int mid = (l + r) / 2;
  return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}
bool cmp(int u, int v) { return a[u].s[1] < a[v].s[1]; }
bool solve() {
  sort(a + 1, a + 1 + n);
  intist();
  using Cmp = std::integral_constant<decltype(&cmp), &cmp>;
  set<int, Cmp> st;
  for (int i = 1; i <= n; ++i) {
    while (!st.empty() && a[*st.begin()].s[1] < a[i].s[0]) {
      int u = *st.begin();
      update(1, 1, 4 * n, a[u].s[2], a[u].s[3], 1);
      st.erase(st.begin());
    }
    if (get(1, 1, 4 * n, a[i].s[2], a[i].s[3]) > 0) return false;
    st.insert(i);
  }
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  scanf("%d", &n);
  set<int> st;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < 4; ++j) {
      scanf("%d", &a[i].s[j]);
      st.insert(a[i].s[j]);
    }
  vector<int> tmp(st.begin(), st.end());
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < 4; ++j)
      a[i].s[j] =
          lower_bound(tmp.begin(), tmp.end(), a[i].s[j]) - tmp.begin() + 1;
  int ans = true;
  ans &= solve();
  for (int i = 1; i <= n; ++i) {
    swap(a[i].s[0], a[i].s[2]);
    swap(a[i].s[1], a[i].s[3]);
  }
  ans &= solve();
  cout << (ans ? "YES\n" : "NO\n");
  return 0;
}
