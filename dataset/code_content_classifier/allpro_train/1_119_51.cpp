#include <bits/stdc++.h>
int main() {
  int a, b, c, d, e;
  while (scanf("%d%d%d%d%d", &a, &b, &c, &d, &e) != EOF) {
    int sum = a + b + c + d + e;
    if (sum % 5 != 0 || sum == 0) {
      printf("-1\n");
      continue;
    }
    printf("%d\n", sum / 5);
  }
  return 0;
}
