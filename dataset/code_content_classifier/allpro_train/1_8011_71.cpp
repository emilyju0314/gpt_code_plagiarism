#include <bits/stdc++.h>
using namespace std;
const int tb[8] = {888888053, 888888047, 888888023, 888887981,
                   888887977, 888887957, 888887933, 888887911};
char s[2][2005], u[2005];
int n, m, P;
long long ans = 0;
int f[2][2005][2005];
int h[2][2005], p[2005], q[2005], pw[2005];
int calc(int op, int l, int r) {
  if (!op) return (p[r] - 1LL * p[l - 1] * pw[r - l + 1] % P + P) % P;
  if (-1 == op) return (q[l] - 1LL * q[r + 1] * pw[r - l + 1] % P + P) % P;
  return (h[op - 1][r] - 1LL * h[op - 1][l - 1] * pw[r - l + 1] % P + P) % P;
}
void solve() {
  for (int i = 1; i <= m; i++) p[i] = (1LL * p[i - 1] * 223 + u[i]) % P;
  for (int i = m; i >= 1; i--) q[i] = (1LL * q[i + 1] * 223 + u[i]) % P;
  for (int j = 0; j <= 1; j++)
    for (int i = 1; i <= n; i++)
      h[j][i] = (1LL * h[j][i - 1] * 223 + s[j][i]) % P;
  for (int i = 1; i <= n; i++) {
    for (int j = 2; j <= min(i - 1, (m - 1) / 2); j++) {
      int w = j * 2 + 1;
      f[0][i][w] +=
          (s[0][i] == u[w] && calc(1, i - j, i - 1) == calc(0, j + 1, j + j) &&
           calc(2, i - j, i - 1) == calc(~0, 1, j));
      f[1][i][w] +=
          (s[1][i] == u[w] && calc(2, i - j, i - 1) == calc(0, j + 1, j + j) &&
           calc(1, i - j, i - 1) == calc(~0, 1, j));
    }
    if (s[0][i] == u[1]) f[0][i][1] = 1;
    if (s[1][i] == u[1]) f[1][i][1] = 1;
    for (int j = 2; j <= m; j++) {
      if (s[0][i] == u[j]) {
        f[0][i][j] = (f[0][i][j] + f[0][i - 1][j - 1]) % 1000000007;
        if (j > 2 && s[0][i - 1] == u[j - 1])
          f[0][i][j] = (f[0][i][j] + f[1][i - 1][j - 2]) % 1000000007;
      }
      if (s[1][i] == u[j]) {
        f[1][i][j] = (f[1][i][j] + f[1][i - 1][j - 1]) % 1000000007;
        if (j > 2 && s[1][i - 1] == u[j - 1])
          f[1][i][j] = (f[1][i][j] + f[0][i - 1][j - 2]) % 1000000007;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    ans += f[0][i][m] + f[1][i][m];
    if (s[0][i] == u[m]) ans += f[1][i][m - 1];
    if (s[1][i] == u[m]) ans += f[0][i][m - 1];
    for (int j = 1; j <= min(n - i, m / 2 - 1); j++) {
      if (calc(1, i, i + j) == calc(0, m - j - j - 1, m - j - 1) &&
          calc(2, i, i + j) == calc(~0, m - j, m))
        ans += f[0][i][m - j - j - 1];
      if (calc(2, i, i + j) == calc(0, m - j - j - 1, m - j - 1) &&
          calc(1, i, i + j) == calc(~0, m - j, m))
        ans += f[1][i][m - j - j - 1];
    }
  }
}
int main() {
  srand(time(0));
  P = tb[rand() & 7];
  scanf("%s", s[0] + 1);
  scanf("%s", s[1] + 1);
  scanf("%s", u + 1);
  n = strlen(s[0] + 1);
  m = strlen(u + 1);
  if (m == 1) {
    for (int i = 0; i <= 1; i++)
      for (int j = 1; j <= n; j++) ans += s[i][j] == u[1];
    printf("%lld\n", ans);
    return 0;
  }
  if (m == 2) {
    for (int i = 1; i <= n; i++) ans += (s[0][i] == u[1] && s[1][i] == u[2]);
    for (int i = 1; i <= n; i++) ans += (s[1][i] == u[1] && s[0][i] == u[2]);
    for (int i = 1; i <= n - 1; i++)
      ans += (s[0][i] == u[1] && s[0][i + 1] == u[2]);
    for (int i = 1; i <= n - 1; i++)
      ans += (s[0][i] == u[2] && s[0][i + 1] == u[1]);
    for (int i = 1; i <= n - 1; i++)
      ans += (s[1][i] == u[1] && s[1][i + 1] == u[2]);
    for (int i = 1; i <= n - 1; i++)
      ans += (s[1][i] == u[2] && s[1][i + 1] == u[1]);
    printf("%lld\n", ans);
    return 0;
  }
  pw[0] = 1;
  for (int i = 1; i <= 2005 - 5; i++) pw[i] = 1LL * pw[i - 1] * 223 % P;
  solve();
  memset(f, 0, sizeof(f));
  reverse(s[0] + 1, s[0] + n + 1);
  reverse(s[1] + 1, s[1] + n + 1);
  solve();
  ans %= 1000000007;
  printf("%lld\n", ans);
  return 0;
}
