#include <bits/stdc++.h>
int main() {
  int n, k, i;
  scanf("%d", &n);
  int l[1000], r[1000];
  for (i = 0; i < n; i++) scanf("%d %d", &l[i], &r[i]);
  scanf("%d", &k);
  int ans = 0;
  for (i = 0; i < n; i++) {
    if (k <= r[i]) {
      ans++;
      break;
    } else
      ans++;
  }
  printf("%d\n", n - ans + 1);
  return 0;
}
