#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int N = 205, M = N * 2;
struct Point {
  int x, y;
} a[N * N], aa[N * N], vv;
inline Point operator-(const Point &a, const Point &b) {
  return {a.x - b.x, a.y - b.y};
}
inline ll operator^(const Point &a, const Point &b) {
  return a.x * 1ll * b.y - a.y * 1ll * b.x;
}
struct Circle {
  int x, y, r;
} c[N];
Point operator-(const Circle &a, const Circle &b) {
  return {a.x - b.x, a.y - b.y};
}
int g[M][M], h[M], d[M], n, w, m, p[M], ww[M], lst[M], stk1[N * N], top1,
    stk2[N * N], top2;
ll dis(Point a, Point b) {
  return ll(a.x - b.x) * (a.x - b.x) + ll(a.y - b.y) * (a.y - b.y);
}
ld get_dis(Point a, Point b, Point c) {
  Point tt;
  tt.x = -(b - a).y;
  tt.y = (b - a).x;
  ll aa = (a - c) ^ tt, bb = (b - c) ^ tt;
  ld ret = 0;
  if ((aa >= 0 && bb >= 0) || (aa <= 0 && bb <= 0))
    ret = min(dis(a, c), dis(b, c)) * 1.0L * dis(a, b);
  else
    aa = (a - c) ^ (b - c), ret = aa * 1.0L * aa;
  return ret;
}
bool fl;
int rr, idx;
bool check(int x, int y) {
  vv = c[x] - c[y];
  rr = c[x].r + c[y].r;
  fl = 1;
  for (int i = 1; i <= idx; i++)
    if (((a[i] - vv) ^ (a[i + 1] - vv)) > 0) {
      fl = 0;
      break;
    }
  if (fl) return 1;
  fl = 1;
  for (int i = 1; i <= idx; i++)
    if (((a[i] - vv) ^ (a[i + 1] - vv)) < 0) {
      fl = 0;
      break;
    }
  if (fl) return 1;
  ld aa = rr * 1ll * rr;
  for (int i = 1; i <= idx; i++)
    if (get_dis(a[i], a[i + 1], vv) + 0.5 < aa * dis(a[i], a[i + 1])) return 1;
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> w;
  int mx = -1, mn = INT_MAX >> 2;
  for (int i = 1; i <= n; i++)
    cin >> a[i].x >> a[i].y, mx = max(a[i].x, mx), mn = min(a[i].x, mn);
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> c[i].x >> c[i].y >> c[i].r;
    if (c[i].x - c[i].r < mx - mn) g[1][i + 1] = INT_MAX >> 2;
    if (w - c[i].x - c[i].r < mx - mn) g[i + m + 1][m + m + 2] = INT_MAX >> 2;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) aa[++idx] = a[i] - a[j];
  sort(aa + 1, aa + idx + 1,
       [](Point a, Point b) { return a.x < b.x || (a.x == b.x && a.y < b.y); });
  stk1[++top1] = stk2[++top2] = 1;
  for (int i = 2; i <= idx; i++) {
    while (top1 > 1 && ((aa[stk1[top1]] - aa[stk1[top1 - 1]]) ^
                        (aa[i] - aa[stk1[top1]])) >= 0)
      --top1;
    while (top2 > 1 && ((aa[stk2[top2]] - aa[stk2[top2 - 1]]) ^
                        (aa[i] - aa[stk2[top2]])) <= 0)
      --top2;
    stk1[++top1] = stk2[++top2] = i;
  }
  idx = 0;
  for (int i = 1; i <= top1; i++) a[++idx] = aa[stk1[i]];
  for (int i = top2 - 1; i > 1; --i) a[++idx] = aa[stk2[i]];
  a[idx + 1] = a[1];
  for (int i = 1; i <= m; i++) g[i + 1][i + m + 1] = 1;
  for (int i = 1; i < m; i++)
    for (int j = i + 1; j <= m; j++)
      if (check(i, j)) g[i + m + 1][j + 1] = g[j + m + 1][i + 1] = INT_MAX >> 2;
  n = m + m + 2;
  h[0] = n;
  for (int i = 1; i <= n; i++) p[i] = 1;
  int ans = 0, cur = INT_MAX >> 2, i = 1;
  while (d[1] < n) {
    ww[i] = cur;
    fl = 0;
    for (int j = p[i]; j <= n; j++)
      if (d[j] == d[i] - 1 && g[i][j] > 0) {
        lst[j] = i;
        fl = 1;
        cur = min(cur, g[i][j]);
        p[i] = j;
        i = j;
        if (i == n) {
          while (i > 1) g[i][lst[i]] += cur, g[lst[i]][i] -= cur, i = lst[i];
          ans += cur;
          cur = INT_MAX >> 2;
        }
        break;
      }
    if (fl) continue;
    mn = n - 1;
    int tmp = -1;
    for (int j = 1; j <= n; j++)
      if (g[i][j] && d[j] < mn) mn = d[j], tmp = j;
    p[i] = tmp;
    --h[d[i]];
    if (!h[d[i]]) break;
    d[i] = mn + 1;
    ++h[d[i]];
    if (i != 1) i = lst[i], cur = ww[i];
  }
  cout << ans << endl;
  return 0;
}
