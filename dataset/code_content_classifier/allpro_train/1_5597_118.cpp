#include <bits/stdc++.h>
using namespace std;
int f[105][105][105], g[105][105], p[105], p2[105], c[105][105], s1[105],
    s2[105], d[105];
int Pow(int x, int y) {
  if (y == 0) return 1;
  int t = Pow(x, y / 2);
  if (y & 1) return 1ll * t * t % 1000000007 * x % 1000000007;
  return 1ll * t * t % 1000000007;
}
void Add(int &a, int b) { a = (0ll + a + b) % 1000000007; }
int main() {
  int n, i, j, k, t;
  for (p[0] = i = 1; i <= 50; i++) p[i] = 1ll * p[i - 1] * i % 1000000007;
  for (p2[0] = i = 1; i <= 50; i++) p2[i] = Pow(2, 1000000007 - 1 - i);
  c[0][0] = 1;
  for (i = 1; i <= 50; i++) {
    c[i][i] = c[i][0] = 1;
    c[i][1] = i;
  }
  for (i = 3; i <= 50; i++)
    for (j = 2; j < i; j++)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % 1000000007;
  f[0][0][0] = 1;
  for (i = 0; i <= 50; i++)
    for (k = 0; k <= 50; k++)
      for (j = 0; j <= 50; j++)
        if (j + k > 0) {
          if (k) {
            if (k >= 3)
              Add(f[i][j][k], 1ll * f[i][j + 2][k - 3] *
                                  ((k - 1) * (k - 2) / 2) % 1000000007);
            if (k >= 2)
              Add(f[i][j][k], 1ll * f[i][j][k - 2] * (k - 1) * j % 1000000007);
            if (k >= 2 && i >= 1)
              Add(f[i][j][k],
                  1ll * f[i - 1][j + 1][k - 2] * (k - 1) * i % 1000000007);
            if (j >= 1)
              Add(f[i][j][k],
                  1ll * f[i][j - 2][k - 1] * (j * (j - 1) / 2) % 1000000007);
            if (i >= 1 && j >= 1)
              Add(f[i][j][k],
                  1ll * f[i - 1][j - 1][k - 1] * j * i % 1000000007);
            if (i >= 2)
              Add(f[i][j][k],
                  1ll * f[i - 2][j][k - 1] * (i * (i - 1) / 2) % 1000000007);
          } else {
            if (i >= 1)
              Add(f[i][j][k], 1ll * f[i - 1][j - 1][k] * i % 1000000007);
            if (j >= 2)
              Add(f[i][j][k], 1ll * f[i][j - 2][k] * (j - 1) % 1000000007);
          }
        }
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &d[i]);
    s1[i] = s1[i - 1];
    s2[i] = s2[i - 1];
    if (d[i] == 2)
      s1[i]++;
    else
      s2[i]++;
  }
  g[n + 1][n] = 1;
  for (i = n + 1; i >= 1; i--)
    for (j = n; j >= i - 1; j--)
      if (g[i][j])
        for (k = i - 1; k >= 1; k--)
          g[k][i - 1] =
              (g[k][i - 1] +
               1ll * g[i][j] *
                   f[j - i + 1][s1[i - 1] - s1[k - 1]][s2[i - 1] - s2[k - 1]] %
                   1000000007) %
              1000000007;
  printf("%d\n", g[2][d[1] + 1]);
  return 0;
}
