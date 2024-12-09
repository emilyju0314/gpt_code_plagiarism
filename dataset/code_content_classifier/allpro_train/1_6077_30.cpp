#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int maxn = 105;
int n, m;
long long a[maxn][maxn], f[maxn][maxn], ans;
void solve(int x, int y, long long w) {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) f[i][j] = 1e18;
  f[x][y] = 0;
  for (int i = x; i >= 1; --i)
    for (int j = y; j >= 1; --j) {
      if (a[i - 1][j] >= w)
        f[i - 1][j] = min(f[i - 1][j], f[i][j] + a[i - 1][j] - w);
      if (a[i][j - 1] >= w)
        f[i][j - 1] = min(f[i][j - 1], f[i][j] + a[i][j - 1] - w);
    }
  for (int i = x; i <= n; ++i)
    for (int j = y; j <= m; ++j) {
      if (a[i + 1][j] >= w)
        f[i + 1][j] = min(f[i + 1][j], f[i][j] + a[i + 1][j] - w);
      if (a[i][j + 1] >= w)
        f[i][j + 1] = min(f[i][j + 1], f[i][j] + a[i][j + 1] - w);
    }
  ans = min(ans, f[1][1] + f[n][m]);
}
void solve() {
  ans = 1e18;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) solve(i, j, a[i][j]);
  printf("%lld\n", ans);
}
int main() {
  int T = read();
  while (T--) {
    n = read();
    m = read();
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j) {
        scanf("%lld", &a[i][j]);
        a[i][j] -= (i + j);
      }
    solve();
  }
  return 0;
}
