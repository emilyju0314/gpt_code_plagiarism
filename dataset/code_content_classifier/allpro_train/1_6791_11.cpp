#include <bits/stdc++.h>
const int N = 5005, MOD = 1000000007;
char ch[N];
int T, n, ans, anss, lcp[N][N], f[N][N], g[N][N];
inline int min(int x, int y) { return x < y && x != -1 ? x : y; }
bool ck(int x, int y, int u, int v) {
  const register int l = lcp[x][u];
  return l >= y - x + 1 || ch[x + l] < ch[u + l];
}
int main() {
  ans = -1;
  anss = 0;
  scanf("%s", ch + 1);
  n = strlen(ch + 1);
  memset(lcp, 0, sizeof(lcp));
  memset(g, 0, sizeof(g));
  memset(f, -1, sizeof(f));
  for (int i = n; i >= 1; i--)
    for (int j = n; j >= 1; j--)
      lcp[i][j] = (ch[i] == ch[j] ? lcp[i + 1][j + 1] + 1 : 0);
  f[1][1] = g[1][1] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j < n; j++) {
      if (!~f[i][j]) continue;
      f[i][j + 1] = min(f[i][j + 1], f[i][j]);
      g[i][j + 1] = (g[i][j + 1] + g[i][j]) % MOD;
      int pos = (j << 1) - i + 1;
      if (pos > n || ch[j + 1] == '0') continue;
      if (ck(i, j, j + 1, pos))
        f[j + 1][pos] = min(f[j + 1][pos], f[i][j] + 1),
              g[j + 1][pos] = (g[j + 1][pos] + g[i][j]) % MOD;
      else
        f[j + 1][pos + 1] = min(f[j + 1][pos + 1], f[i][j] + 1),
                       g[j + 1][pos + 1] = (g[j + 1][pos + 1] + g[i][j]) % MOD;
    }
  }
  for (int i = n; i >= 1; i--) {
    anss = (anss + g[i][n]) % MOD;
    if (!~f[i][n]) continue;
    int tmp = 0;
    for (int j = i; j <= n; j++) tmp = ((tmp << 1LL) % MOD + ch[j] - '0') % MOD;
    tmp = (tmp + f[i][n]) % MOD;
    if (~ans && n - i + 1 > 15) {
      for (int j = i - 1; j >= 1; j--) anss = (anss + g[j][n]) % MOD;
      break;
    }
    ans = min(ans, tmp);
  }
  printf("%d\n%d\n", anss, ans);
  return 0;
}
