#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
char c[2][60], tmp[60];
bool mat[2][60][60][30];
int f[60][60];
int a[60], b[60], to[60];
int main() {
  scanf("%s%s", c[0] + 1, c[1] + 1);
  int len[2];
  len[0] = strlen(c[0] + 1), len[1] = strlen(c[1] + 1);
  memset(mat, 0, sizeof(mat));
  int n = read();
  for (int i = 1; i <= n; i++) {
    scanf("%s", tmp + 1);
    a[i] = tmp[4] - 96, b[i] = tmp[5] - 96, to[i] = tmp[1] - 96;
  }
  for (int i = 1; i <= len[0]; i++) mat[0][i][i][c[0][i] - 96] = 1;
  for (int i = 1; i <= len[1]; i++) mat[1][i][i][c[1][i] - 96] = 1;
  for (int l = 1; l <= len[0]; l++)
    for (int r = 1; r <= len[0] - l; r++)
      for (int mid = 0; mid < l; mid++)
        for (int k = 1; k <= n; k++)
          mat[0][r][r + l][to[k]] |=
              (mat[0][r][r + mid][a[k]] & mat[0][r + mid + 1][r + l][b[k]]);
  for (int l = 1; l <= len[1]; l++)
    for (int r = 1; r <= len[1] - l; r++)
      for (int mid = 0; mid < l; mid++)
        for (int k = 1; k <= n; k++)
          mat[1][r][r + l][to[k]] |=
              (mat[1][r][r + mid][a[k]] & mat[1][r + mid + 1][r + l][b[k]]);
  memset(f, 0x3f, sizeof(f));
  f[0][0] = 0;
  for (int l = 1; l <= len[0]; l++)
    for (int r = 1; r <= len[1]; r++)
      for (int i = 0; i < l; i++)
        for (int j = 0; j < r; j++)
          for (int k = 1; k <= 26; k++)
            if (mat[0][i + 1][l][k] && mat[1][j + 1][r][k])
              f[l][r] = min(f[l][r], f[i][j] + 1);
  if (f[len[0]][len[1]] > max(len[0], len[1]))
    cout << -1 << endl;
  else
    cout << f[len[0]][len[1]] << endl;
  return 0;
}
