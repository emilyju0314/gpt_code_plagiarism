#include <bits/stdc++.h>
using namespace std;
char c[101][101];
char a[4];
int n, m;
int heng(int n, int m) {
  int i, j;
  if (n % 3 != 0) return 0;
  n /= 3;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (c[i][j] != c[1][1]) {
        return 0;
      }
  for (i = n + 1; i <= n * 2; i++)
    for (j = 1; j <= m; j++)
      if (c[i][j] != c[n + 1][1]) return 0;
  for (i = 2 * n + 1; i <= n * 3; i++)
    for (j = 1; j <= m; j++)
      if (c[i][j] != c[2 * n + 1][1]) return 0;
  a[1] = c[1][1];
  a[2] = c[n + 1][1];
  a[3] = c[2 * n + 1][1];
  n *= 3;
  sort(a + 1, a + 4);
  if (a[1] == 'B' && a[2] == 'G' && a[3] == 'R')
    return 1;
  else
    return 0;
}
int zong(int n, int m) {
  int i, j;
  if (m % 3 != 0) return 0;
  m /= 3;
  for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++)
      if (c[j][i] != c[1][1]) return 0;
  for (i = m + 1; i <= m * 2; i++)
    for (j = 1; j <= n; j++)
      if (c[j][i] != c[1][m + 1]) return 0;
  for (i = 2 * m + 1; i <= m * 3; i++)
    for (j = 1; j <= n; j++)
      if (c[j][i] != c[1][2 * m + 1]) return 0;
  a[1] = c[1][1];
  a[2] = c[1][m + 1];
  a[3] = c[1][2 * m + 1];
  sort(a + 1, a + 4);
  if (a[1] == 'B' && a[2] == 'G' && a[3] == 'R')
    return 1;
  else
    return 0;
}
int main() {
  int i, j, k;
  cin >> n >> m;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) cin >> c[i][j];
  if (heng(n, m) == 1 || zong(n, m) == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
