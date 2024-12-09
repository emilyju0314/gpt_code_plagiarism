#include <bits/stdc++.h>
int main() {
  int i, j, k, n;
  n = 500, k = 2000, j = 0;
  printf("%d\n", n);
  printf("1 1000000\n");
  for (i = 2; i < n; ++i) printf("%d %d\n", 100000 + i * 1000, n - i);
  printf("998001 1000000\n");
}
