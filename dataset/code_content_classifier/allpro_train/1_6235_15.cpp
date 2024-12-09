#include <bits/stdc++.h>
using namespace std;
long long ans, pw[500010], f[500010][2];
int n, sl, fh, siz[500010];
int t, h[500010];
struct Tre {
  int to, nxt;
} e[500010 << 1];
int rd() {
  sl = 0;
  fh = 1;
  char ch = getchar();
  while (ch < '0' || '9' < ch) {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') sl = sl * 10 + ch - '0', ch = getchar();
  return sl * fh;
}
void add(int u, int v) {
  e[++t] = (Tre){v, h[u]};
  h[u] = t;
  e[++t] = (Tre){u, h[v]};
  h[v] = t;
}
void dfs(int u, int fa) {
  int v;
  f[u][0] = 1;
  siz[u] = 1;
  for (int i = h[u]; i; i = e[i].nxt)
    if ((v = e[i].to) != fa) {
      dfs(v, u);
      siz[u] += siz[v];
      f[u][1] =
          (2 * f[u][1] * (f[v][0] + f[v][1]) + f[u][0] * f[v][0]) % 998244353;
      f[u][0] = f[u][0] * (f[v][0] + 2 * f[v][1]) % 998244353;
    }
}
int main() {
  n = rd();
  pw[0] = 1;
  int x, y;
  for (int i = 1; i < n; ++i)
    x = rd(), y = rd(), add(x, y), pw[i] = pw[i - 1] * 2 % 998244353;
  dfs(1, 0);
  for (int i = 1; i <= n; ++i)
    ans = (ans + pw[n - siz[i]] * f[i][1]) % 998244353;
  printf("%I64d\n", ans * 2 % 998244353);
  return 0;
}
