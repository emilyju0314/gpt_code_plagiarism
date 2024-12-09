#include <bits/stdc++.h>
const int N = 100005;
int a[N] = {0}, b[N] = {0}, c[N] = {0}, lx[N] = {0}, ly[N] = {0};
int main() {
  bool bb = false;
  int n = 0, t = 0, i = 0, g = 0, tol = 0, x = 0, j = 0;
  while (scanf("%d", &n) == 1) {
    t = 0;
    g = 0;
    tol = 0;
    for (i = 1; i <= n + 1; i++) {
      if (i <= n) {
        scanf("%d", &x);
      } else {
        x = 0;
      }
      bb = false;
      while (t && x < lx[t - 1]) {
        bb = true;
        a[g] = ly[t - 1];
        b[g] = i - 1;
        c[g] = lx[t - 1] - x;
        if (t > 1 && lx[t - 1] - lx[t - 2] < c[g]) {
          c[g] = lx[t - 1] - lx[t - 2];
        }
        tol += c[g];
        t--;
        g++;
      }
      if (t && x == lx[t - 1]) {
        ;
      } else {
        lx[t] = x;
        if (!bb) {
          ly[t] = i;
        }
        t++;
      }
    }
    printf("%d\n", tol);
    for (i = 0; i < g; i++) {
      for (j = 0; j < c[i]; j++) {
        printf("%d %d\n", a[i], b[i]);
      }
    }
  }
  return 0;
}
