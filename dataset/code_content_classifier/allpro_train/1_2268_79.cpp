#include <bits/stdc++.h>
using namespace std;
const int N = 67, M = (1 << 15) + 7, p = 1e9 + 7;
int n, k, l, w[N], g[N], ft[N], fl[N], num[N], res[M], dp[N][M];
inline int read() {
  int num = 0;
  char g = getchar();
  while (g < 48 || 57 < g) g = getchar();
  while (47 < g && g < 58)
    num = (num << 1) + (num << 3) + g - 48, g = getchar();
  return num;
}
inline int inc(int a, int b) {
  if (a + b >= p) return a + b - p;
  return a + b;
}
inline int mul(int a, int b) { return 1ll * a * b % p; }
inline int find(int u) {
  if (ft[u] == u) return u;
  return ft[u] = find(ft[u]);
}
inline void fwt(int *s) {
  for (int d = 1; d < l; d = d << 1)
    for (int i = 0, r = d << 1; i < l; i += r)
      for (int j = 0; j < d; j++) s[i + j + d] = inc(s[i + j], s[i + j + d]);
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) w[i] = read();
  for (int i = 1; i <= n; i++) {
    int tg = 0, tp = 0;
    for (int j = 1; j <= n; j++) {
      if (w[i] % w[j] == 0) tg++;
      if (w[j] % w[i] == 0) tp++;
    }
    if (tg > 1 || tp <= 2) continue;
    fl[i] = ++k;
  }
  for (int i = 1; i <= n; i++)
    for (int x = 1; x <= n; x++)
      if (w[i] % w[x] == 0 && fl[x]) g[i] |= (1 << (fl[x] - 1));
  for (int i = 1; i <= n; i++)
    if (__builtin_popcount(g[i]) >= 1 && !fl[i]) num[++num[0]] = g[i];
  if (!num[0]) {
    cout << 1 << endl;
    return 0;
  }
  dp[0][0] = 1, n = num[0], l = (1 << k);
  for (int i = 1; i <= n; i++) ft[i] = i;
  int lt = n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (num[i] & num[j]) {
        if (find(ft[i]) == find(ft[j])) continue;
        ft[find(ft[i])] = find(ft[j]), lt--;
      }
  for (int i = 1; i <= n; i++)
    for (int q = n; q >= 1; q--)
      for (int j = 0; j < (1 << k); j++)
        dp[q][j | num[i]] = inc(dp[q][j | num[i]], dp[q - 1][j]);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j < (1 << k); j++)
      if (i != lt) dp[i][j] = 0;
  for (int i = 1; i <= n; i++) res[num[i]]++;
  fwt(res);
  for (int i = 1; i < (1 << k); i++)
    for (int x = 1; x <= n; x++) {
      if (res[i] > x)
        dp[x + 1][i] = inc(dp[x + 1][i], mul(dp[x][i], res[i] - x));
      for (int c = 1; c <= n; c++)
        if (((num[c] & i) != num[c]) && (num[c] & i))
          dp[x + 1][i | num[c]] = inc(dp[x + 1][i | num[c]], dp[x][i]);
    }
  cout << dp[n][(1 << k) - 1] << endl;
  return 0;
}
