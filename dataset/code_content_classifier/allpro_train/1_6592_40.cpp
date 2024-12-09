#include <bits/stdc++.h>
int main() {
  int n, m, a, b, x, y, max1 = -1, max2 = -1;
  scanf("%d", &n);
  for (x = 1; x <= n; x++) {
    scanf("%d", &a);
    if (a > max1) {
      max1 = a;
    }
  }
  scanf("%d", &m);
  for (y = 1; y <= m; y++) {
    scanf("%d", &b);
    if (b > max2) {
      max2 = b;
    }
  }
  printf("%d %d", max1, max2);
  return 0;
}
