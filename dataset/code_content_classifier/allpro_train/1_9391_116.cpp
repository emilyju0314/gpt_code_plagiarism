#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
const int mx = 32000;
int n, m, a[6000], b[6000], f[100000], dp[6000][6000], f1[6000], f2[6000],
    g[100000], r[1000000];
set<int> s;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
inline int F(int x) {
  int res = 0;
  for (int j = 2; j <= x; j++) {
    if (j * j > x) break;
    if (x % j != 0) continue;
    int x1 = x / j;
    while (x1 * j == x) {
      res += r[j];
      x = x1;
      x1 = x / j;
    }
  }
  if (x != 1) {
    if (s.find(x) != s.end())
      res--;
    else
      res++;
  }
  return res;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= m; i++) scanf("%d", b + i);
  for (int i = 1; i <= m; i++) s.insert(b[i]);
  for (int i = 1; i <= m; i++)
    if (b[i] <= mx) r[b[i]] = -1;
  for (int i = 2; i <= mx; i++)
    if (f[i] == 0) {
      for (int j = 1; j <= mx; j++) {
        if (i * j > mx) break;
        if (f[i * j] == 0) f[i * j] = i;
      }
    }
  for (int i = 1; i <= mx; i++)
    if (f[i] == i && s.find(i) == s.end()) r[i] = 1;
  int gd = a[1];
  g[1] = gd;
  for (int i = 2; i <= n; i++) {
    gd = gcd(a[i], gd);
    g[i] = gd;
  }
  for (int i = 1; i <= n; i++) f1[i] = F(a[i]);
  for (int i = 1; i <= n; i++) f2[i] = F(g[i]);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n + 1; j++)
      dp[i][j] = max(dp[i - 1][j] - f2[j], dp[i - 1][i] - f2[i]) + f1[i];
  cout << dp[n][n + 1];
  return 0;
}
