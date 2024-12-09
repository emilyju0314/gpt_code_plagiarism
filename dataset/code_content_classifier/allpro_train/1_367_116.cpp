#include <bits/stdc++.h>
using namespace std;
const long long inf = 10000000000000000LL;
long long f[4001], g[4001];
int t[2001], c[2001];
int main() {
  long long ans;
  int n, i, j;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d%d", &t[i], &c[i]);
  for (i = 0; i <= 4000; i++) f[i] = inf;
  f[2000] = 0;
  for (i = 1; i <= n; i++) {
    for (j = 0; j <= 4000; j++) {
      g[j] = inf;
      if (j >= t[i] && f[j - t[i]] + c[i] < g[j]) g[j] = f[j - t[i]] + c[i];
      if (j < 4000 && f[j + 1] < g[j]) g[j] = f[j + 1];
    }
    memcpy(f, g, sizeof(g));
  }
  for (ans = inf, i = 2000; i <= 4000; i++)
    if (f[i] < ans) ans = f[i];
  printf("%I64d\n", ans);
  return 0;
}
