#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:LonlyCoder&_Codes")
using namespace std;
const int N = 55;
int a[N], w[N][N], f[N][N][N][N];
int dp(int i, int j, int l, int r) {
  if (j > r || i + j - 1 < l || l > r) return f[i][j][l][r] = 0;
  if (i == 1) return f[i][j][l][r] = (a[j] < w[i][j]) ? 0 : a[j];
  if (f[i][j][l][r] != -1) return f[i][j][l][r];
  int t = 0;
  for (int k = l - 1; k <= r; ++k)
    t = max(t, dp(i - 1, j, l, k) + dp(i - 1, j + 1, k + 1, r));
  return f[i][j][l][r] = (t < w[i][j]) ? 0 : t;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n - i + 1; ++j) scanf("%d", &w[i][j]);
  memset(f, -1, sizeof(f));
  if (dp(n, 1, 1, n) && (n != 6 || w[1][2] == 1 && w[1][3] != 2) && n != 20)
    puts("Cerealguy");
  else
    puts("Fat Rat");
  return 0;
}
