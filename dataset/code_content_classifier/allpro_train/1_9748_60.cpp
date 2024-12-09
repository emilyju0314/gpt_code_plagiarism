#include <bits/stdc++.h>
using namespace std;
int n, m, cir, g[110], cnt;
double f[2][110 * 1010], s[2][110 * 1010], mem[110 * 1010], ans;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &g[i]), cnt += g[i];
  if (m == 1) {
    printf("%.10lf", 1.0);
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    if (i != g[1]) f[0][i] = 1.0 / (1.0 * (m - 1));
    s[0][i] = s[0][i - 1] + f[0][i];
  }
  int now = 0;
  for (int i = 2; i <= n; i++) {
    now ^= 1;
    for (int j = 0; j <= (i - 1) * m; j++) mem[j] = 0;
    for (int j = 0; j <= m * i; j++) f[now][j] = 0, s[now][j] = 0;
    for (int j = i * 1; j <= m * i; j++) {
      int k = max(j - m - 1, i - 2), k2 = min((i - 1) * m, j - 1), t = k2 - k;
      if (j - g[i] >= k && j - g[i] <= k2)
        f[now][j] = (s[now ^ 1][k2] - s[now ^ 1][j - g[i]] +
                     s[now ^ 1][j - g[i] - 1] - s[now ^ 1][k]) /
                    (1.0 * (m - 1));
      else
        f[now][j] = (s[now ^ 1][k2] - s[now ^ 1][k]) / (1.0 * (m - 1));
      mem[j] = mem[j - 1] + f[now][j];
    }
    for (int j = 0; j <= m * i; j++) {
      s[now][j] = mem[j];
    }
    int zzd = 3454;
    now += 0;
  }
  for (int i = n; i < cnt; i++) ans = ans + f[now][i];
  printf("%.12lf", ans * 1.0 * (m - 1) + 1.0);
  return 0;
}
