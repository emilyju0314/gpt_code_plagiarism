#include <bits/stdc++.h>
int main() {
  int n, m, a, b, l, flag, ok, cnt;
  while (scanf("%d%d", &n, &m) == 2) {
    l = 0;
    flag = 1;
    ok = 0;
    cnt = 0;
    for (int i = 1; i <= m; ++i) {
      scanf("%d%d", &a, &b);
      if (cnt) {
        if (a == l) ++cnt;
      }
      if (!ok) {
        if (a == l + 1) {
          l = b;
        } else {
          ok = 1;
          flag = 0;
          if (a == l) {
            cnt = 2;
          } else
            printf("%d 0\n", l + 1);
        }
      }
    }
    if (flag) {
      if (l == n)
        printf("OK\n");
      else
        printf("%d 0\n", l + 1);
    } else if (cnt)
      printf("%d %d\n", l, cnt);
  }
}
