#include <bits/stdc++.h>
using namespace std;
const int N = 3001;
const int mod = 1000000007;
char s[N][N];
int f[N][N];
int calc(int sr, int sc, int tr, int tc) {
  if (tr < sr || tc < sc) return 0;
  int n = tr - sr + 1, m = tc - sc + 1;
  f[0][0] = (s[sr][sc] != '#');
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      if (i || j) {
        f[i][j] = 0;
        if (i > 0) f[i][j] += f[i - 1][j];
        if (j > 0) f[i][j] += f[i][j - 1];
        f[i][j] %= mod;
        if (s[i + sr][j + sc] == '#') f[i][j] = 0;
      }
  }
  return f[n - 1][m - 1];
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  int a, b, c, d;
  a = calc(0, 1, n - 2, m - 1);
  b = calc(1, 0, n - 1, m - 2);
  c = calc(0, 1, n - 1, m - 2);
  d = calc(1, 0, n - 2, m - 1);
  printf("%lld\n", ((1LL * a * b - 1LL * c * d) % mod + mod) % mod);
  return 0;
}
