#include <bits/stdc++.h>
int main() {
  int p, n, i, a[301] = {0};
  long long b;
  scanf("%d%d", &p, &n);
  for (i = 1; i <= n; i++) {
    scanf("%I64d", &b);
    if (a[b % p] > 0) {
      printf("%d\n", i);
      return 0;
    }
    a[b % p]++;
  }
  printf("-1\n");
  return 0;
}
