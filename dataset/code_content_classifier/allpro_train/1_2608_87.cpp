#include <bits/stdc++.h>
const int MAXN = 2000 + 5;
const int ha = 1e6 + 3;
char str[MAXN];
int a[MAXN];
int n;
int f[MAXN][MAXN], g[MAXN][MAXN];
int main() {
  scanf("%s", str + 1);
  int len = strlen(str + 1);
  for (register int i = 1; i <= len; ++i) {
    if (isdigit(str[i])) {
      a[++n] = 0;
      while (isdigit(str[i])) ++i;
      --i;
    } else {
      if (str[i] == '+' || str[i] == '-')
        a[++n] = 1;
      else
        a[++n] = 2;
    }
  }
  for (register int i = 1; i <= n; ++i) f[i][i] = g[i][i] = !a[i];
  for (register int l = n - 1; l >= 1; --l)
    if (a[l] != 2) {
      int *p1 = f[l] - 1;
      for (register int r = l + 1; r <= n; ++r)
        if (!a[r]) {
          long long t = 0;
          if (a[l] == 1) t = f[l + 1][r];
          int *p2 = g[r] + 1;
          for (register int k = l + 1; k <= r - 1; ++k)
            if (a[k]) t += 1ll * p1[k] * p2[k];
          f[l][r] = g[r][l] = t % ha;
        }
    }
  printf("%d\n", f[1][n]);
  return 0;
}
