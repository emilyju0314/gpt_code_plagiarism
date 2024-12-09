#include <bits/stdc++.h>
using namespace std;
int a[100050], f[100050];
int n, m, t;
int main() {
  int i, j, k, T;
  scanf("%d%d%d%d", &T, &n, &m, &t);
  t = min(t, min(n, m));
  while (T--) {
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    memset(f, 0, sizeof(f));
    for (i = 1; i <= t; i++)
      for (j = 1; j <= n; j++) {
        f[a[j]] = f[a[j] - 1] + 1;
        for (k = a[j] + 1; k <= m; k++) {
          if (f[k] >= f[a[j]]) break;
          f[k] = f[a[j]];
        }
      }
    printf("%d\n", f[m]);
  }
  return 0;
}
