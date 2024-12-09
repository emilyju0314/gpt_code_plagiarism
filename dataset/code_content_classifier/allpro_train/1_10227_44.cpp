#include <bits/stdc++.h>
int main() {
  int n, p1, p2, p3, t1, t2, a1, a2, b1, b2, con = 0, df, i;
  scanf("%d%d%d%d%d%d", &n, &p1, &p2, &p3, &t1, &t2);
  scanf("%d%d", &a1, &a2);
  for (i = 2; i <= n; i++) {
    scanf("%d%d", &b1, &b2);
    con += (a2 - a1) * p1;
    df = b1 - a2;
    if (df >= t1) {
      df -= t1;
      con += t1 * p1;
    } else {
      con += df * p1;
      df = 0;
    }
    if (df >= t2) {
      df -= t2;
      con += t2 * p2;
    } else {
      con += df * p2;
      df = 0;
    }
    con += df * p3;
    a1 = b1;
    a2 = b2;
  }
  con += (a2 - a1) * p1;
  printf("%d", con);
  return 0;
}
