#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
const int maxn = 200000 + 5;
int n, k, N;
int x[maxn], y[maxn];
int mx[maxn << 2], sum[maxn];
void push_up(int x) { mx[x] = max(mx[(x << 1)], mx[(x << 1 | 1)]); }
void build(int x, int l, int r) {
  if (l == r) {
    mx[x] = sum[l];
    return;
  }
  int mid = l + r >> 1;
  build((x << 1), l, mid);
  build((x << 1 | 1), mid + 1, r);
  push_up(x);
}
int query(int x, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return mx[x];
  int mid = l + r >> 1;
  int m1 = 0, m2 = 0;
  if (ql <= mid) m1 = query((x << 1), l, mid, ql, qr);
  if (mid < qr) m2 = query((x << 1 | 1), mid + 1, r, ql, qr);
  return max(m1, m2);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  int cnt = 0;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= n; ++i) cin >> y[i];
    sort(x + 1, x + n + 1);
    int l = x[1], r, pl = 1, pr = 0;
    for (int i = 1; i <= n; ++i) {
      r = x[i], pr++;
      while (pl < pr && r - l > k) l = x[++pl];
      sum[i] = pr - pl + 1;
    }
    build(1, 1, n);
    int ans = 0;
    if (x[n] - x[1] <= k) ans = sum[n];
    for (int i = 1; x[i] + k < x[n]; ++i) {
      int id = upper_bound(x + 1, x + n + 1, x[i] + k) - x;
      ans = max(ans, sum[i] + query(1, 1, n, id, n));
    }
    cout << ans << '\n';
  }
  return 0;
}
