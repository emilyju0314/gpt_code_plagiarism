#include <bits/stdc++.h>
using namespace std;
const int N = 2E3 + 50;
const double eps = 1e-8;
int n, ans, cnt, tag[N];
double dis[N], k[N * N];
struct point {
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}
  point operator+(point const &a) const { return point(x + a.x, y + a.y); }
  point operator-(point const &a) const { return point(x - a.x, y - a.y); }
} a[N], mid;
vector<point> g;
int judge(double y) { return y > -eps ? (y < eps ? 0 : 1) : -1; }
bool check(double k) {
  double co = cos(k), si = sin(k);
  for (int i = 0; i < (int)g.size(); ++i)
    dis[i + 1] = g[i].x * co + g[i].y * si;
  double md = mid.x * co + mid.y * si;
  sort(dis + 1, dis + 1 + (int)g.size());
  for (int i = 1, j = (int)g.size(); i <= j; ++i, --j)
    if (judge(dis[i] + dis[j] - 2.0 * md)) return false;
  return true;
}
double calc(point u, point v) {
  double x, y;
  x = u.x + v.x - 2 * mid.x, y = u.y + v.y - 2 * mid.y;
  y *= -1, swap(x, y);
  point a = point(x, y);
  if (judge(a.y) < 0) a.x *= -1, a.y *= -1;
  if (!judge(a.y)) a.x = fabs(a.x);
  return atan2(a.y, a.x);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    tag[i] = 0;
    scanf("%lf%lf", &a[i].x, &a[i].y);
    mid.x += a[i].x, mid.y += a[i].y;
  }
  mid.x /= n, mid.y /= n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      point d = a[i] + a[j] - point(mid.x * 2, mid.y * 2);
      if (!judge(d.x) && !judge(d.y)) tag[i] = tag[j] = 1;
    }
  int f = 1;
  for (int i = 1; i <= n; i++) f &= tag[i];
  if (f || n <= 2) return 0 * printf("-1\n");
  for (int i = 1; i <= n; i++)
    if (!tag[i]) g.push_back(a[i]);
  for (int i = 0; i < (int)g.size(); ++i)
    for (int j = i + 1; j < (int)g.size(); j++) {
      k[++cnt] = calc(g[i], g[j]);
    }
  sort(k + 1, k + 1 + cnt);
  for (int i = 1, l, r; i <= cnt; i = r + 1) {
    l = lower_bound(k + 1, k + 1 + cnt, k[i]) - k;
    r = upper_bound(k + 1, k + 1 + cnt, k[i]) - k - 1;
    if (r - l + 1 < ((int)g.size() >> 1)) continue;
    ans += check(k[i]);
  }
  printf("%d\n", ans);
  return 0;
}
