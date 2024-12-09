#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
struct Line {
  double x, y, vx, vy;
  void read() {
    double t1, t2;
    scanf("%lf%lf%lf%lf%lf%lf", &t1, &x, &y, &t2, &vx, &vy);
    vx = (vx - x) / (t2 - t1);
    vy = (vy - y) / (t2 - t1);
    x -= vx * t1;
    y -= vy * t1;
  }
} p[N], tmp;
struct P {
  double x, y;
} b[N];
double det(P a, P b) { return a.x * b.y - a.y * b.x; }
bool cmp(P a, P b) {
  if (abs(det(a, b)) < (1e-7)) {
    if (abs(a.x - b.x) < (1e-7)) return a.y < b.y;
    return a.x < b.x;
  }
  return det(a, b) < 0;
}
double a[N];
int n, ans, cnt;
int main() {
  scanf("%d", &n);
  for (int i = (int)(1); i <= (int)(n); i++) p[i].read();
  for (int i = (int)(1); i <= (int)(n); i++) {
    int tot = 0;
    for (int j = (int)(1); j <= (int)(n); j++)
      if (j != i) {
        tmp.x = p[j].x - p[i].x;
        tmp.y = p[j].y - p[i].y;
        tmp.vx = p[j].vx - p[i].vx;
        tmp.vy = p[j].vy - p[i].vy;
        double t = 0;
        if (tmp.vx)
          t = tmp.x / tmp.vx;
        else if (tmp.vy)
          t = tmp.y / tmp.vy;
        if (abs(tmp.x - tmp.vx * t) < (1e-7))
          if (abs(tmp.y - tmp.vy * t) < (1e-7)) {
            a[++tot] = t;
            b[tot].x = tmp.vx;
            b[tot].y = tmp.vy;
          }
      }
    sort(a + 1, a + tot + 1);
    cnt = 0;
    for (int j = 1; j <= tot; j++) {
      if (abs(a[j] - a[j - 1]) < (1e-7))
        cnt++;
      else
        cnt = 1;
      ans = max(ans, cnt);
    }
    cnt = 0;
    sort(b + 1, b + tot + 1, cmp);
    for (int j = 1; j <= tot; j++) {
      if (abs(det(b[j], b[j - 1])) < (1e-7)) {
        if (abs(b[j].x - b[j - 1].x) > (1e-7) ||
            abs(b[j].y - b[j - 1].y) > (1e-7))
          cnt++;
        else
          ;
      } else
        cnt = 1;
      ans = max(ans, cnt);
    }
  }
  printf("%d\n", ans + 1);
}
