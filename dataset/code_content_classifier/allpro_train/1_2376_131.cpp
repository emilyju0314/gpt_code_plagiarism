#include <bits/stdc++.h>
int i, j, n, m, t, p1, p2, p3, a[100000], ans1[100000], ans2[100000];
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; scanf("%d", a + i++))
    ;
  for (p2 = 1, p3 = 2, i = 3; i <= n; ++i)
    for (p1 = i;;) {
      if (a[p1] > a[p2]) {
        t = p1;
        p1 = p2;
        p2 = t;
      }
      if (a[p2] > a[p3]) {
        t = p2;
        p2 = p3;
        p3 = t;
      }
      if (a[p1] > a[p2]) {
        t = p1;
        p1 = p2;
        p2 = t;
      }
      if (a[p1] == 0) {
        break;
      }
      for (j = a[p2] / a[p1]; j; j >>= 1)
        if (j & 1) {
          ans1[++m] = p1;
          ans2[m] = p2;
          a[p2] -= a[p1];
          a[p1] <<= 1;
        } else {
          ans1[++m] = p1;
          ans2[m] = p3;
          a[p3] -= a[p1];
          a[p1] <<= 1;
        }
    }
  if ((a[p1] == 0) + (a[p2] == 0) + (a[p3] == 0) != 1) {
    printf("-1\n");
  } else {
    for (printf("%d\n", m), i = 1; i <= m; ++i) {
      printf("%d %d\n", ans1[i], ans2[i]);
    }
  }
  return 0;
}
