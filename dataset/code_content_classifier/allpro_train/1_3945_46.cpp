#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", n / 3 * 2 + ((n) % 3 ? 1 : 0));
  return 0;
}