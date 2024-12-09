#include <bits/stdc++.h>
using namespace std;
bool inter(double a, double b, double c, double d) {
  if (b < c || d < a) return 0;
  return 1;
}
int main() {
  int i;
  double a, b, c, d;
  cin >> a >> b >> c >> d;
  double lb = 0, ub = 1e10, mid;
  int iters = 100;
  int dx[] = {1, 1, -1, -1};
  int dy[] = {1, -1, 1, -1};
  while (iters--) {
    mid = (lb + ub) / 2;
    double l[4], r[4];
    for (i = 0; i < 4; i++) {
      l[i] = (a + mid * dx[i]) * (d + mid * dy[i]);
      r[i] = (b + mid * dx[i]) * (c + mid * dy[i]);
    }
    sort(l, l + 4);
    sort(r, r + 4);
    if (!inter(l[0], l[3], r[0], r[3])) {
      lb = mid;
    } else {
      ub = mid;
    }
  }
  printf("%.10lf\n", mid);
  return 0;
}
