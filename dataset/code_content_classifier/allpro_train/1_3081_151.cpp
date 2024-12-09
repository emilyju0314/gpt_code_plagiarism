#include <bits/stdc++.h>
int main() {
  int n, m, c;
  scanf("%d %d", &n, &m);
  for (int i = n + 1; i <= m; i++) {
    c = 0;
    for (int j = 2; j <= i / 2; j++) {
      if (i % j == 0) {
        c = 1;
        break;
      }
    }
    if (c == 0 && i != m) {
      printf("NO");
      return 0;
    }
    if (c == 0 && i == m) {
      printf("YES");
      return 0;
    }
  }
  printf("NO");
  return 0;
}
