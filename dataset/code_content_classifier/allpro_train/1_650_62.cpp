#include <bits/stdc++.h>
double ABS(double x) {
  if (x > 0)
    return x;
  else
    return -1 * x;
}
double xl(double x1, double y1, double x2, double y2) {
  if (ABS(x2 - x1) < 1e-10) return 1e15;
  return (y2 - y1) / (x2 - x1);
}
double x[12000], y[12000];
int main() {
  int N;
  double w, v, u;
  while (scanf("%d%lf%lf%lf", &N, &w, &v, &u) != EOF) {
    bool neg = false;
    for (int i = 1; i <= N; i++) {
      scanf("%lf%lf", &x[i], &y[i]);
      if (x[i] <= 0) neg = true;
    }
    double ans = 0;
    double maxxl = 1e-15, minxl = 1e15;
    int maxp, minp;
    for (int i = 1; i <= N; i++) {
      double tmp = xl(0, 0, x[i], y[i]);
      if (tmp > maxxl) {
        maxxl = tmp;
        maxp = i;
      }
      if (tmp < minxl && x[i] > 0) {
        minxl = tmp;
        minp = i;
      }
    }
    double stdxl = u / v;
    if ((stdxl >= maxxl && neg == false) || minxl > stdxl) {
      ans = w / u;
      printf("%.8lf\n", ans);
      return 0;
    }
    int p = minp;
    double curxl = minxl, cx = x[p], cy = y[p];
    ans = x[p] / v;
    while (curxl < stdxl) {
      p++;
      if (p == (N + 1)) p = 1;
      double tmpx = xl(cx, cy, x[p], y[p]);
      if (tmpx < 0) {
        ans += (w - cy) / u;
        printf("%.8lf\n", ans);
        return 0;
        break;
      }
      if (tmpx > stdxl) tmpx = stdxl;
      curxl = tmpx;
      ans += (x[p] - cx) / v;
      cy += ((x[p] - cx) * curxl);
      cx = x[p];
    }
    if (cy < w) ans += (w - cy) / u;
    printf("%.8lf\n", ans);
  }
  return 0;
}
