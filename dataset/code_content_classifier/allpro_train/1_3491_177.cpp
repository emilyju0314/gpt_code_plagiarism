#include <bits/stdc++.h>
int main() {
  double a, b, m, vx, vy, vz;
  while (scanf("%lf%lf%lf", &a, &b, &m) == 3) {
    scanf("%lf%lf%lf", &vx, &vy, &vz);
    vy = -vy;
    double t = m / vy;
    int count = int(t * vz / b);
    double y1 = t * vz - count * b;
    if (count % 2) y1 = b - y1;
    bool ret;
    if (vx > 0)
      ret = false;
    else
      ret = true, vx = -vx;
    double y2;
    if (vx <= 1e-8 && -vx <= 1e-8)
      y2 = a / 2.0;
    else {
      double s1 = 0.5 * a * vy / vx;
      if (m < s1)
        y2 = (s1 - m) * vx / vy;
      else {
        m = m - s1;
        t = m / vy;
        count = int(t * vx / a);
        y2 = t * vx - count * a;
        if (count % 2) y2 = a - y2;
      }
    }
    if (!ret) y2 = a - y2;
    printf("%.10lf %.10lf\n", y2, y1);
  }
  return 0;
}
