#include <bits/stdc++.h>
int main() {
  int n, s, i, k = 0, max = 0;
  scanf("%d%d", &n, &s);
  int f[n];
  int t[n];
  for (i = 0; i < n; i++) {
    scanf("%d%d", &f[i], &t[i]);
    if (t[i] + f[i] > max) {
      max = t[i] + f[i];
    }
  }
  if (max > s)
    printf("%d\n", max);
  else
    printf("%d\n", s);
  return 0;
}
