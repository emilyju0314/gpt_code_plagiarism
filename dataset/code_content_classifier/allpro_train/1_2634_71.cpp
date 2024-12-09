#include <bits/stdc++.h>
using namespace std;
int n, m, q;
long long h[1 << 23], w[1 << 23];
long long ht[1 << 23], wt[1 << 23];
void updateh(int nd, int l, int r, int lt, int rt, long long v) {
  if (l > rt || r < lt) return;
  if (l == r && l == lt) {
    h[nd] += v * (r - l + 1);
    return;
  }
  if (l >= lt && r <= rt) {
    ht[nd] += v * (r - l + 1);
    return;
  }
  int k = (l + r) >> 1;
  long long tmp = ht[nd] / (r - l + 1);
  updateh(2 * nd, l, k, l, r, tmp);
  updateh(2 * nd + 1, k + 1, r, l, r, tmp);
  ht[nd] = 0;
  updateh(2 * nd, l, k, lt, rt, v);
  updateh(2 * nd + 1, k + 1, r, lt, rt, v);
  h[nd] = h[2 * nd] + h[2 * nd + 1] + ht[2 * nd] + ht[2 * nd + 1];
}
void updatev(int nd, int l, int r, int lt, int rt, long long v) {
  if (l > rt || r < lt) return;
  if (l == r && l == lt) {
    w[nd] += v * (r - l + 1);
    return;
  }
  if (l >= lt && r <= rt) {
    wt[nd] += v * (r - l + 1);
    return;
  }
  int k = (l + r) >> 1;
  long long tmp = wt[nd] / (r - l + 1);
  updatev(2 * nd, l, k, l, r, tmp);
  updatev(2 * nd + 1, k + 1, r, l, r, tmp);
  wt[nd] = 0;
  updatev(2 * nd, l, k, lt, rt, v);
  updatev(2 * nd + 1, k + 1, r, lt, rt, v);
  w[nd] = w[2 * nd] + w[2 * nd + 1] + wt[2 * nd] + wt[2 * nd + 1];
}
long long queryh(int nd, int l, int r, int lt, int rt) {
  if (l > rt || r < lt) return 0;
  if (l >= lt && r <= rt) {
    return ht[nd] + h[nd];
  }
  int k = (l + r) >> 1;
  if (ht[nd]) {
    long long tmp = ht[nd] / (r - l + 1);
    updateh(2 * nd, l, k, l, r, tmp);
    updateh(2 * nd + 1, k + 1, r, l, r, tmp);
    ht[nd] = 0;
    h[nd] = h[2 * nd] + h[2 * nd + 1] + ht[2 * nd] + ht[2 * nd + 1];
  }
  long long res =
      queryh(2 * nd, l, k, lt, rt) + queryh(2 * nd + 1, k + 1, r, lt, rt);
  return res;
}
long long queryv(int nd, int l, int r, int lt, int rt) {
  if (l > rt || r < lt) return 0;
  if (l >= lt && r <= rt) {
    return wt[nd] + w[nd];
  }
  int k = (l + r) >> 1;
  if (wt[nd]) {
    long long tmp = wt[nd] / (r - l + 1);
    updatev(2 * nd, l, k, l, r, tmp);
    updatev(2 * nd + 1, k + 1, r, l, r, tmp);
    wt[nd] = 0;
    w[nd] = w[2 * nd] + w[2 * nd + 1] + wt[2 * nd] + wt[2 * nd + 1];
  }
  long long res =
      queryv(2 * nd, l, k, lt, rt) + queryv(2 * nd + 1, k + 1, r, lt, rt);
  return res;
}
void printh(int nd, int l, int r) {
  cout << nd << " " << l << " " << r << " " << h[nd] << " " << ht[nd] << endl;
  if (l == r) return;
  printh(2 * nd, l, (l + r) >> 1);
  printh(2 * nd + 1, ((l + r) >> 1) + 1, r);
}
void printv(int nd, int l, int r) {
  cout << nd << " " << l << " " << r << " " << w[nd] << " " << wt[nd] << endl;
  if (l == r) return;
  printv(2 * nd, l, (l + r) >> 1);
  printv(2 * nd + 1, ((l + r) >> 1) + 1, r);
}
int main() {
  cin >> n >> m >> q;
  long long tot = 0;
  for (int i = 0; i < q; i++) {
    int t;
    scanf("%d", &t);
    if (t == 0) {
      int x1, y1, x2, y2, val;
      scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &val);
      updateh(1, 1, m, y1, y2, (long long)val * (x2 - x1 + 1));
      updatev(1, 1, n, x1, x2, (long long)val * (y2 - y1 + 1));
      tot += (long long)val * (x2 - x1 + 1) * (y2 - y1 + 1);
    }
    if (t == 1) {
      int x1, y1, x2, y2;
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      long long ans = queryh(1, 1, m, y1, y2) + queryv(1, 1, n, x1, x2);
      ans = ans - tot;
      cout << ans << "\n";
    }
  }
  return 0;
}
