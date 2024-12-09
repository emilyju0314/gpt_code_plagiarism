#include <bits/stdc++.h>
using namespace std;
const int N = 507;
int f[N][N], g[N][N], a[N], b[N];
int read() {
  int x;
  scanf("%d", &x);
  return x;
}
void print(int i, int j) {
  if (!i) return;
  print(i - 1, g[i][j]);
  if (g[i][j] ^ j) printf("%d ", b[j]);
}
int main() {
  int n, m, i, j, k;
  for (n = read(), i = 1; i <= n; ++i) a[i] = read();
  for (m = read(), i = 1; i <= m; ++i) b[i] = read();
  for (i = 1; i <= n; ++i)
    for (j = 1, k = 0; j <= m; ++j)
      if (a[i] == b[j])
        f[i][j] = f[i - 1][k] + 1, g[i][j] = k;
      else {
        f[i][j] = f[i - 1][j], g[i][j] = j;
        if (b[j] < a[i] && f[i][j] > f[i][k]) k = j;
      }
  for (k = 0, i = 1; i <= m; ++i)
    if (f[n][i] > f[n][k]) k = i;
  printf("%d\n", f[n][k]);
  if (f[n][k]) print(n, k);
}
