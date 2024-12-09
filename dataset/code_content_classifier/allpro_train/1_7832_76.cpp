#include <bits/stdc++.h>
using namespace std;
int n, m, w, i, step, Max;
int a[100000 + 5], sum[100000 + 5];
bool ok(int l) {
  int crt, m2;
  m2 = m;
  for (int j = 1; j <= n; ++j) sum[j] = 0;
  for (int j = 1; j <= n; ++j) {
    sum[j] += sum[j - 1];
    if (sum[j] + a[j] >= l) continue;
    crt = sum[j] + a[j];
    if (l - crt > m2) return false;
    m2 -= (l - crt);
    sum[j] += (l - crt);
    sum[min(n + 1, j + w)] -= (l - crt);
  }
  return true;
}
int main() {
  scanf("%d%d%d", &n, &m, &w);
  for (i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    Max = max(Max, a[i] + m);
  }
  for (step = 1; step < Max; step <<= 1)
    ;
  for (i = 0; step; step >>= 1)
    if (i + step <= Max)
      if (ok(i + step)) i += step;
  printf("%d\n", i);
  return 0;
}
