#include <bits/stdc++.h>
int main() {
  int n, m, x;
  int zhong = 0, bian = 0, jiao = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &x);
      if (x == 1) {
        if ((i == 1 && j == 1) || (i == n && j == 1) ||
            (i == 1 && j == m) && (i == n && j == m)) {
          jiao = 1;
          break;
        }
        if (i == 1 || j == 1 || i == n || j == m) {
          bian = 1;
        } else {
          zhong = 1;
        }
      }
    }
  }
  if (jiao == 1) {
    printf("1\n");
  }
  if (bian == 1) {
    printf("2\n");
    return 0;
  }
  if (zhong == 1) {
    printf("4\n");
    return 0;
  }
  return 0;
}
