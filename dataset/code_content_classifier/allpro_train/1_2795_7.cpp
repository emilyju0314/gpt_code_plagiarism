#include <bits/stdc++.h>
using namespace std;
const int mn = 201000, inf = 1 << 30;
struct node {
  int x, y;
} pt[mn], sub[mn];
struct point {
  int k, x, y, r;
} e[mn * 2];
int s1[mn * 2], s2[mn * 2];
int xs[mn * 2], dis[mn], sa[mn], L;
int n, m, i, j, step, lo, hi, mid;
bool cmp(node a, node b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }
bool cmp1(point a, point b) { return a.x < b.x || (a.x == b.x && a.k < b.k); }
bool subway(int i, int j) { return dis[i] > dis[j]; }
struct tree {
  int tt, rt[mn], s[mn * 20], le[mn * 20], ri[mn * 20];
  int get(const int &p, int l, int r, int x, int y) {
    if (x <= l && y >= r) return s[p];
    int m = (l + r) / 2, res = 0;
    if (x <= m) res += get(le[p], l, m, x, y);
    if (y > m) res += get(ri[p], m + 1, r, x, y);
    return res;
  }
  void add(const int &t, int &p, int l, int r, int k) {
    s[p = ++tt] = s[t] + 1;
    if (l == r) return;
    int m = (l + r) / 2;
    if (k <= m)
      add(le[t], le[p], l, m, k), ri[p] = ri[t];
    else
      add(ri[t], ri[p], m + 1, r, k), le[p] = le[t];
  }
  void ins(int i, int v) { add(rt[i - 1], rt[i], 1, L, v); }
  int query(int x, int y, int l, int r) {
    if (x > y || l > r || x > m) return 0;
    return get(rt[y], 1, L, l, r) - get(rt[x - 1], 1, L, l, r);
  }
} T;
point eva(int k, int x, int y, int r) {
  point res;
  res.k = k, res.x = x, res.y = y, res.r = r;
  return res;
}
void cross(int &l, int &r, int &x, int &y, int i, int t) {
  l = max(l, pt[i].x - t), x = max(x, pt[i].y - t);
  r = min(r, pt[i].x + t), y = min(y, pt[i].y + t);
}
void add(int *s, int p, int v) {
  for (; p <= L; p += p & (-p)) s[p] = max(s[p], v);
}
int query(int *s, int p) {
  int res = -inf;
  for (; p; p -= p & (-p)) res = max(res, s[p]);
  return res;
}
void get(point p) {
  int y = lower_bound(xs + 1, xs + 1 + L, p.y) - xs;
  if (p.k == 0)
    add(s1, y, p.x + p.y), add(s2, L - y + 1, p.x - p.y);
  else {
    int t1 = p.x + p.y - query(s1, y), t2 = p.x - p.y - query(s2, L - y + 1);
    dis[p.r] = min(dis[p.r], min(t1, t2));
  }
}
void ugly(node &p) {
  int X = p.x - p.y, Y = p.x + p.y;
  p.x = X, p.y = Y;
}
void nearest() {
  int i, tt = 0;
  for (i = 1; i <= n; ++i) xs[++L] = pt[i].y;
  for (i = 1; i <= m; ++i) xs[++L] = sub[i].y;
  sort(xs + 1, xs + 1 + L);
  L = unique(xs + 1, xs + 1 + L) - xs - 1;
  for (i = 1; i <= n; ++i) e[++tt] = eva(1, pt[i].x, pt[i].y, i);
  for (i = 1; i <= m; ++i) e[++tt] = eva(0, sub[i].x, sub[i].y, i);
  sort(e + 1, e + 1 + tt, cmp1);
  fill(dis + 1, dis + 1 + n, inf);
  fill(s1 + 1, s1 + L + 1, -inf), fill(s2 + 1, s2 + 1 + L, -inf);
  for (i = 1; i <= tt; ++i) get(e[i]);
  for (i = 1; i <= tt; ++i) e[i].x = -e[i].x;
  sort(e + 1, e + 1 + tt, cmp1);
  fill(s1 + 1, s1 + L + 1, -inf), fill(s2 + 1, s2 + 1 + L, -inf);
  for (i = 1; i <= tt; ++i) get(e[i]);
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; ++i) scanf("%d%d", &pt[i].x, &pt[i].y);
  for (i = 1; i <= m; ++i) scanf("%d%d", &sub[i].x, &sub[i].y);
  nearest();
  for (i = 1; i <= n; ++i) ugly(pt[i]);
  for (i = 1; i <= m; ++i) ugly(sub[i]);
  sort(sub + 1, sub + 1 + m, cmp);
  L = 0;
  for (i = 1; i <= n; ++i) xs[++L] = pt[i].y;
  for (i = 1; i <= m; ++i) xs[++L] = sub[i].y;
  sort(xs + 1, xs + 1 + L), L = unique(xs + 1, xs + 1 + L) - xs - 1;
  for (i = 1; i <= m; ++i)
    T.ins(i, lower_bound(xs + 1, xs + 1 + L, sub[i].y) - xs);
  for (i = 1; i <= n; ++i) sa[i] = i;
  sort(sa + 1, sa + 1 + n, subway);
  lo = 0, hi = dis[sa[1]];
  int mix, mxx, miy, mxy, ct, l, r, x, y;
  node su;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    mix = miy = -inf, mxx = mxy = inf;
    for (i = 1; i <= n; ++i) {
      if (dis[sa[i]] > mid)
        cross(mix, mxx, miy, mxy, sa[i], mid);
      else {
        ct = mid - dis[sa[i]];
        su.y = -inf, su.x = mix - ct;
        l = lower_bound(sub + 1, sub + 1 + m, su, cmp) - sub;
        su.y = inf, su.x = mxx + ct;
        r = lower_bound(sub + 1, sub + 1 + m, su, cmp) - sub - 1;
        x = lower_bound(xs + 1, xs + 1 + L, miy - ct) - xs,
        y = lower_bound(xs + 1, xs + 1 + L, mxy + ct + 1) - xs - 1;
        if (T.query(l, r, x, y))
          break;
        else
          cross(mix, mxx, miy, mxy, sa[i], mid);
      }
      if (mix > mxx || miy > mxy) break;
    }
    if (mix <= mxx && miy <= mxy)
      hi = mid;
    else
      lo = mid + 1;
  }
  printf("%d\n", lo);
  return 0;
}
