#include <bits/stdc++.h>
int main(void) {
  double a, d, cd, x, y, nol;
  int i, n;
  scanf("%lf %lf %d", &a, &d, &n);
  for (i = 1; i <= n; i++) {
    nol = floor(i * d / (4 * a));
    cd = i * d - nol * 4 * a;
    if (cd <= a) {
      x = cd;
      y = 0;
    } else if (cd <= 2 * a) {
      x = a;
      y = cd - a;
    } else if (cd <= 3 * a) {
      x = 3 * a - cd;
      y = a;
    } else {
      x = 0;
      y = 4 * a - cd;
    }
    printf("%lf %lf\n", x, y);
  }
  return 0;
}
