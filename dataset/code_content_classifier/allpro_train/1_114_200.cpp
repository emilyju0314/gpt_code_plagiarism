#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m;
int a[5010], type[5010], x[5010], y[5010], z[5010];
inline void fail() {
  printf("NO\n");
  exit(0);
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) a[i] = int(1e8);
  for (i = 1; i <= m; i++) {
    scanf("%d%d%d%d", &type[i], &x[i], &y[i], &z[i]);
    if (type[i] == 1)
      for (j = x[i]; j <= y[i]; j++) a[j] += z[i];
    else {
      int F = 0;
      for (j = x[i]; j <= y[i]; j++)
        if (a[j] >= z[i]) F = 1, a[j] = z[i];
      if (!F) fail();
    }
  }
  for (i = m; i; i--)
    if (type[i] == 1)
      for (j = x[i]; j <= y[i]; j++) a[j] -= z[i];
    else {
      int ma = int(-1e8);
      for (j = x[i]; j <= y[i]; j++) ma = max(ma, a[j]);
      if (ma != z[i]) fail();
    }
  printf("YES\n");
  for (i = 1; i <= n; i++) printf("%d ", a[i]);
  printf("\n");
  return 0;
}
