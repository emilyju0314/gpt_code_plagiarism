#include <bits/stdc++.h>
int a[1000000];
int main() {
  int n, m;
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
      if (m - i > 0)
        m -= i;
      else
        break;
    }
    printf("%d\n", a[m - 1]);
  }
}
