#include <bits/stdc++.h>
using namespace std;
struct cir {
  double x, y, r;
} r0, P0, P1;
vector<pair<double, int> > d;
double x, y, r, ans = 1e12;
int n, cnt;
double dis(double x, double y) { return pow(x * x + y * y, 0.5); }
int main() {
  scanf("%lf%lf%lf%lf", &P1.x, &P1.y, &x, &y);
  P0.x = (P1.x + x) / 2.0;
  P0.y = (P1.y + y) / 2.0;
  r0.x = P0.y - P1.y, r0.y = P1.x - P0.x;
  r0.r = dis(r0.x, r0.y);
  r0.x /= r0.r, r0.y /= r0.r;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lf%lf%lf", &x, &y, &r);
    double xx = (x + P1.x) / 2, yy = (y + P1.y) / 2;
    double d0 = (xx - P0.x) * (P1.x - x) + (yy - P0.y) * (P1.y - y);
    d0 /= (P1.x - x) * r0.x + (P1.y - y) * r0.y;
    double L = -ans, R = d0, mid;
    while (L + 1e-4 < R) {
      mid = (L + R) / 2;
      if (fabs(dis(P0.x + mid * r0.x - x, P0.y + mid * r0.y - y) -
               dis(mid, r0.r)) < r)
        R = mid;
      else
        L = mid;
    }
    d.push_back(make_pair(L, -1));
    L = d0, R = ans;
    while (L + 1e-4 < R) {
      mid = (L + R) / 2;
      if (fabs(dis(P0.x + mid * r0.x - x, P0.y + mid * r0.y - y) -
               dis(mid, r0.r)) < r)
        L = mid;
      else
        R = mid;
    }
    d.push_back(make_pair(R, 1));
  }
  sort(d.begin(), d.end());
  x = -ans;
  for (int i = 0; i < d.size(); i++) {
    if (!cnt)
      ans = min(ans, dis(d[i].first, r0.r)),
      ans = (x * d[i].first <= 0 ? r0.r : ans);
    cnt += d[i].second;
    if (!cnt) ans = min(ans, dis(d[i].first, r0.r)), x = d[i].first;
  }
  printf("%.7lf\n", ans);
  return 0;
}
