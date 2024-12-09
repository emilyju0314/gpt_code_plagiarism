#include <bits/stdc++.h>
using namespace std;
int Len, N, f[105][55][2];
char a[200];
int Max(int x, int y) {
  if (x > y) return x;
  return y;
}
int main() {
  scanf("%s", a);
  Len = strlen(a);
  scanf("%d", &N);
  memset(f, 171, sizeof(f));
  f[0][0][0] = 0;
  f[0][0][1] = 0;
  for (int i = 0; i < Len; ++i)
    for (int j = 0; j <= N; ++j)
      for (int k = 0; k <= j; ++k) {
        if ((j - k) % 2 == 0) {
          if (a[i] == 'T') {
            f[i + 1][j][0] = Max(f[i + 1][j][0], f[i][k][1]);
            f[i + 1][j][1] = Max(f[i + 1][j][1], f[i][k][0]);
          } else {
            f[i + 1][j][0] = Max(f[i + 1][j][0], f[i][k][0] + 1);
            f[i + 1][j][1] = Max(f[i + 1][j][1], f[i][k][1] - 1);
          }
        } else {
          if (a[i] == 'F') {
            f[i + 1][j][0] = Max(f[i + 1][j][0], f[i][k][1]);
            f[i + 1][j][1] = Max(f[i + 1][j][1], f[i][k][0]);
          } else {
            f[i + 1][j][0] = Max(f[i + 1][j][0], f[i][k][0] + 1);
            f[i + 1][j][1] = Max(f[i + 1][j][1], f[i][k][1] - 1);
          }
        }
      }
  printf("%d\n", Max(f[Len][N][0], f[Len][N][1]));
  return 0;
}
