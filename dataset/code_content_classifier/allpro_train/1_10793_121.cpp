#include <bits/stdc++.h>
using namespace std;
int n, i, j, l, r, a[5050], b[5050];
double an, d[5050], f[5050][2], g[5050][2];
double dis(int i, int j) {
  int X1 = a[i], Y1 = b[i], X2 = a[j], Y2 = b[j];
  return sqrt(1ll * (X2 - X1) * (X2 - X1) + 1ll * (Y2 - Y1) * (Y2 - Y1));
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    scanf("%d%d", &a[i], &b[i]), a[i + n] = a[i], b[i + n] = b[i];
  for (i = 1; i <= n; i++) d[i] = dis(i, i + 1), d[i + n] = d[i];
  for (i = 1; i <= n * 2; i++) f[i][0] = 0.0;
  for (j = 2; j <= n; j++) {
    for (i = 1; i + j - 1 <= n * 2; i++) {
      l = i;
      r = i + j - 1;
      g[l][0] = max(f[l + 1][1] + dis(l, r), f[l + 1][0] + dis(l, l + 1));
      g[l][1] = max(f[l][0] + dis(l, r), f[l][1] + dis(r - 1, r));
    }
    for (i = 1; i + j - 1 <= n * 2; i++) f[i][0] = g[i][0], f[i][1] = g[i][1];
  }
  for (i = 1; i <= n; i++) an = max(an, max(f[i][0], f[i][1]));
  printf("%.10lf", an);
}
