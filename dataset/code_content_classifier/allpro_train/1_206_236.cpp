#include <bits/stdc++.h>
using namespace std;
int gint() {
  char c;
  int f = 1;
  while (c = getchar(), c < 48 || c > 57)
    if (c == '-') f = -1;
  int x = 0;
  for (; c > 47 && c < 58; c = getchar()) {
    x = x * 10 + c - 48;
  }
  return x * f;
}
int n, m, maxs, a[20][20], f[(1 << 20)], bin[(1 << 20)];
char s[20][20];
int main() {
  n = gint(), m = gint();
  for (int i = 0; i < n; ++i) scanf("%s", s + i);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) a[i][j] = gint();
  maxs = 1 << n;
  for (int i = 1; i < maxs; ++i) f[i] = 0x3f3f3f3f;
  for (int i = 0; i < maxs; ++i)
    for (int j = 0; j < 30; ++j)
      if (!((i >> j) & 1)) {
        bin[i] = j;
        break;
      }
  for (int S = 0; S < maxs - 1; ++S) {
    int i = bin[S];
    for (int j = 0; j < m; ++j) {
      f[S ^ (1 << i)] = min(f[S ^ (1 << i)], f[S] + a[i][j]);
      int sum = 0, maxa = 0, ns = 0;
      for (int k = 0; k < n; ++k) {
        if (s[i][j] != s[k][j]) continue;
        sum += a[k][j], maxa = max(maxa, a[k][j]);
        ns ^= (1 << k);
      }
      f[S | ns] = min(f[S | ns], f[S] + sum - maxa);
    }
  }
  return printf("%d\n", f[maxs - 1]), 0;
}
