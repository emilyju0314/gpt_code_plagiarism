#include <bits/stdc++.h>
using namespace std;
int n, m;
long long ans;
long long f[160][160][2][2], g[160][160][2][2];
const int mod = 1000000007;
void update(long long &i, long long x) { i = (i + x) % mod; }
long long calc(int lx, int rx, int ly, int ry, int f1, int f2) {
  return g[rx][ry][f1][f2] - g[rx][ly - 1][f1][f2] - g[lx - 1][ry][f1][f2] +
         g[lx - 1][ly - 1][f1][f2];
}
void change() {
  int i, j;
  for (i = 1; i <= m; i++)
    for (j = 1; j <= m; j++) {
      update(g[i][j][0][0],
             g[i - 1][j][0][0] + g[i][j - 1][0][0] - g[i - 1][j - 1][0][0]);
      update(g[i][j][0][1],
             g[i - 1][j][0][1] + g[i][j - 1][0][1] - g[i - 1][j - 1][0][1]);
      update(g[i][j][1][0],
             g[i - 1][j][1][0] + g[i][j - 1][1][0] - g[i - 1][j - 1][1][0]);
      update(g[i][j][1][1],
             g[i - 1][j][1][1] + g[i][j - 1][1][1] - g[i - 1][j - 1][1][1]);
    }
}
int main() {
  int i, j, l, r;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++)
    for (j = i; j <= m; j++) g[i][j][0][0] = 1;
  update(ans, m * (m + 1) / 2 * n);
  change();
  for (i = 2; i <= n; i++) {
    memset(f, 0, sizeof(f));
    for (l = 1; l <= m; l++)
      for (r = l; r <= m; r++) {
        update(f[l][r][0][0], calc(l, r, l, r, 0, 0));
        update(f[l][r][0][1],
               calc(l, r, r + 1, m, 0, 0) + calc(l, r, r, m, 0, 1));
        update(f[l][r][1][0],
               calc(1, l - 1, l, r, 0, 0) + calc(1, l, l, r, 1, 0));
        update(f[l][r][1][1],
               calc(1, l - 1, r + 1, m, 0, 0) + calc(1, l - 1, r, m, 0, 1) +
                   calc(1, l, r + 1, m, 1, 0) + calc(1, l, r, m, 1, 1));
        update(ans, (n - i + 1) * (f[l][r][0][0] + f[l][r][0][1] +
                                   f[l][r][1][0] + f[l][r][1][1]));
      }
    memset(g, 0, sizeof(g));
    for (l = 1; l <= m; l++)
      for (r = l; r <= m; r++) {
        g[l][r][0][0] = f[l][r][0][0];
        g[l][r][0][1] = f[l][r][0][1];
        g[l][r][1][0] = f[l][r][1][0];
        g[l][r][1][1] = f[l][r][1][1];
      }
    change();
  }
  printf("%I64d\n", (ans + mod) % mod);
  return 0;
}
