#include <bits/stdc++.h>
using namespace std;
int g[16];
long long f[360360], ff[360360];
int k;
long long work(long long aa, long long bb) {
  memset(ff, 0x3f, sizeof(ff));
  ff[bb] = 0;
  for (long long i = bb + 1; i <= aa; i++) {
    ff[i] = ff[i - 1] + 1;
    for (int j = 2; j <= k; j++) ff[i] = min(ff[i], ff[i / j * j] + 1);
  }
  return ff[aa];
}
int main() {
  long long a, b;
  scanf("%I64d%I64d%d", &a, &b, &k);
  g[1] = 1;
  for (int j = 2; j <= k; j++) {
    g[j] = g[j - 1] * j;
    if (j == 4) g[j] /= 2;
    if (j == 6) g[j] /= 6;
    if (j == 8) g[j] /= 4;
    if (j == 9) g[j] /= 3;
    if (j == 10) g[j] /= 10;
    if (j == 12) g[j] /= 12;
    if (j == 14) g[j] /= 14;
    if (j == 15) g[j] /= 15;
  }
  memset(f, 0x3f, sizeof(f));
  f[0] = 0;
  for (int i = 1; i < g[k]; i++) {
    f[i] = f[i - 1] + 1;
    for (int j = 2; j <= k; j++) f[i] = min(f[i], f[i / j * j] + 1);
  }
  long long ans = 0;
  long long ta = a / g[k], tb = b / g[k];
  if (ta == tb)
    ans = work(a % g[k], b % g[k]);
  else
    ans = f[a % g[k]] + (ta - tb - 1) * (f[g[k] - 1] + 1) + 1 +
          work(g[k] - 1, b % g[k]);
  printf("%I64d\n", ans);
  return 0;
}
