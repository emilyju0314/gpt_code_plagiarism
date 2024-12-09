#include <bits/stdc++.h>
using namespace std;
const unsigned int INF = 2e9 + 1;
unsigned int segtree[800010][10][2];
inline void merge(unsigned int from[10][2], const unsigned int a[10][2],
                  const unsigned int b[10][2]) {
  for (unsigned int i = 0; i < 10; i++) {
    if (a[i][0] < b[i][0]) {
      from[i][0] = a[i][0];
      from[i][1] = min(a[i][1], b[i][0]);
    } else {
      from[i][0] = b[i][0];
      from[i][1] = min(b[i][1], a[i][0]);
    }
  }
}
void update(const unsigned int &loc, const unsigned int &st,
            const unsigned int &en, const unsigned int &x,
            const unsigned int &v) {
  if (x > en || x < st) return;
  if (x == st && x == en) {
    unsigned int tmp = v;
    for (unsigned int i = 0; i < 10; i++) {
      segtree[loc][i][0] = segtree[loc][i][1] = INF;
      if (tmp % 10) segtree[loc][i][0] = v;
      tmp /= 10;
    }
  } else {
    unsigned int mid = (st + en) / 2;
    if (x <= mid) {
      update(2 * loc, st, mid, x, v);
    } else {
      update(2 * loc + 1, mid + 1, en, x, v);
    }
    merge(segtree[loc], segtree[2 * loc], segtree[2 * loc + 1]);
  }
}
void query(const unsigned int &loc, const unsigned int &st,
           const unsigned int &en, const unsigned int &l, const unsigned int &r,
           unsigned int ans[10][2]) {
  for (unsigned int i = 0; i < 10; i++) ans[i][0] = ans[i][1] = INF;
  if (en < l || st > r) return;
  if (st >= l && en <= r) {
    memcpy(ans, segtree[loc], 80);
    return;
  }
  unsigned int lt[10][2], rt[10][2], mid = (st + en) / 2;
  query(2 * loc, st, mid, l, r, lt);
  query(2 * loc + 1, mid + 1, en, l, r, rt);
  merge(ans, lt, rt);
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  unsigned int n, x, ch, y;
  int32_t m;
  cin >> n >> m;
  for (unsigned int i = 1; i <= n; i++) {
    cin >> x;
    update(1, 1, n, i, x);
  }
  while (m--) {
    cin >> ch >> x >> y;
    if (ch == 1) {
      update(1, 1, n, x, y);
    } else {
      unsigned int a[10][2], ans = INF;
      query(1, 1, n, x, y, a);
      for (unsigned int i = 0; i < 10; i++) {
        ans = min(ans, a[i][0] + a[i][1]);
      }
      if (ans >= INF) {
        cout << "-1\n";
      } else {
        cout << ans << '\n';
      }
    }
  }
  return 0;
}
