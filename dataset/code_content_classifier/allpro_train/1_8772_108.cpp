#include <bits/stdc++.h>
int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  printf("%d\n", (a + b - 1) * (c + b - 1) - b * (b - 1));
  return 0;
}
