#include <bits/stdc++.h>
using namespace std;
const int nmax = 200010;
struct point {
  long long x, y;
  point() {}
  point(long long xx, long long yy) {
    x = xx;
    y = yy;
  }
};
int n, i, ii, t, xx, yy, num, res[nmax];
point p[nmax], q;
long long ans, kol;
point operator-(point p1, point p2) { return point(p1.x - p2.x, p1.y - p2.y); }
long long vect(point p1, point p2) { return p1.x * p2.y - p1.y * p2.x; }
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &xx, &yy);
    p[i] = point(xx, yy);
    p[i + n] = p[i];
  }
  scanf("%d", &t);
  for (ii = 1; ii <= t; ii++) {
    scanf("%d%d", &xx, &yy);
    q = point(xx, yy);
    num = 2;
    while (vect(p[num] - p[1], q - p[1]) < 0) num++;
    if (vect(p[num] - p[1], q - p[1]) <= 0) {
      cout << 0 << "\n";
      continue;
    }
    if (vect(p[num - 1] - p[1], q - p[1]) >= 0) {
      cout << 0 << "\n";
      continue;
    }
    if (vect(p[num - 1] - p[num], q - p[num]) <= 0) {
      cout << 0 << "\n";
      continue;
    }
    res[1] = num;
    for (i = 2; i <= n; i++) {
      while (vect(p[num] - p[i], q - p[i]) < 0) num++;
      res[i] = num;
    }
    for (i = 1; i <= n; i++) res[i + n] = res[i] + n;
    kol = 0;
    for (num = 2; num < res[1]; num++) {
      kol += res[num] - res[1];
    }
    ans = kol;
    for (i = 2; i <= n; i++) {
      kol = kol - (res[i] - res[i - 1]) -
            (res[i] - res[i - 1]) * (res[i - 1] - i - 1);
      for (num = res[i - 1]; num < res[i]; num++) {
        kol += res[num] - res[i];
      }
      ans += kol;
    }
    cout << ans / 3 << "\n";
  }
  return 0;
}
