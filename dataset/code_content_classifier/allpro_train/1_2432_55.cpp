#include <bits/stdc++.h>
using namespace std;
int min(int x, int y) { return (x < y ? x : y); }
int max(int x, int y) { return (x > y ? x : y); }
int noL[1048676], noR[1048676], ns = 524288;
int r[300010], Lne[300010][20], Rne[300010][20], n;
int Lto[300010][20], Rto[300010][20];
void change(int x) {
  for (int i = ns + x; i >= 1; i >>= 1) {
    if (noL[i] - r[noL[i]] > x - r[x]) noL[i] = x;
    if (noR[i] + r[noR[i]] < x + r[x]) noR[i] = x;
  }
}
int getL(int L, int R) {
  L = max(L, 1), R = min(R, 3 * n);
  int i = L + ns, j = R + ns, ans = R;
  while (i <= j) {
    if ((i & 1) && noL[i] - r[noL[i]] < ans - r[ans]) ans = noL[i];
    if ((~j & 1) && noL[j] - r[noL[j]] < ans - r[ans]) ans = noL[j];
    i = (i >> 1) + (i & 1);
    j = (j >> 1) - (~j & 1);
  }
  return ans;
}
int getR(int L, int R) {
  L = max(L, 1), R = min(R, 3 * n);
  int i = L + ns, j = R + ns, ans = 0;
  while (i <= j) {
    if ((i & 1) && noR[i] + r[noR[i]] > ans + r[ans]) ans = noR[i];
    if ((~j & 1) && noR[j] + r[noR[j]] > ans + r[ans]) ans = noR[j];
    i = (i >> 1) + (i & 1);
    j = (j >> 1) - (~j & 1);
  }
  return ans;
}
int main() {
  int i, j, ans, x, y, nx, ny, L, R;
  scanf("%d", &n);
  for (i = 0; i <= 2 * ns; i++) noR[i] = 0;
  for (i = 0; i <= 2 * ns; i++) noL[i] = 3 * n + 1;
  for (i = 1; i <= n; i++) scanf("%d", &r[i]);
  for (i = 1; i <= n; i++) r[i + n] = r[i + n * 2] = r[i];
  for (i = 1; i <= 3 * n; i++) change(i);
  for (i = 1; i <= 3 * n; i++) {
    Lne[i][0] = max(1, getL(i - r[i], i + r[i]));
    Rne[i][0] = min(3 * n, getR(i - r[i], i + r[i]));
    Lto[i][0] = Rto[i][0] = i;
  }
  for (j = 1; j <= 19; j++)
    for (i = 1; i <= 3 * n; i++) {
      x = Lne[i][j - 1];
      y = Rne[i][j - 1];
      if (Lne[x][j - 1] - r[Lne[x][j - 1]] < Lne[y][j - 1] - r[Lne[y][j - 1]])
        Lne[i][j] = Lne[x][j - 1];
      else
        Lne[i][j] = Lne[y][j - 1];
      if (Rne[x][j - 1] + r[Rne[x][j - 1]] > Rne[y][j - 1] + r[Rne[y][j - 1]])
        Rne[i][j] = Rne[x][j - 1];
      else
        Rne[i][j] = Rne[y][j - 1];
      x = Lto[i][j - 1];
      y = Rto[i][j - 1];
      if (Lne[x][j - 1] - r[Lne[x][j - 1]] < Lne[y][j - 1] - r[Lne[y][j - 1]])
        Lto[i][j] = Lne[x][j - 1];
      else
        Lto[i][j] = Lne[y][j - 1];
      if (Rne[x][j - 1] + r[Rne[x][j - 1]] > Rne[y][j - 1] + r[Rne[y][j - 1]])
        Rto[i][j] = Rne[x][j - 1];
      else
        Rto[i][j] = Rne[y][j - 1];
    }
  for (j = 0; j <= 19; j++)
    for (i = 1; i <= 3 * n; i++) {
      Lto[i][j] = max(1, Lto[i][j] - r[Lto[i][j]]);
      Rto[i][j] = min(3 * n, Rto[i][j] + r[Rto[i][j]]);
    }
  for (i = n + 1; i <= 2 * n; i++) {
    x = y = i;
    ans = 0;
    for (j = 19; j >= 0; j--) {
      L = min(Lto[x][j], Lto[y][j]);
      R = max(Rto[x][j], Rto[y][j]);
      if (R - L + 1 < n) {
        ans += (1 << j);
        if (Lne[x][j] - r[Lne[x][j]] < Lne[y][j] - r[Lne[y][j]])
          nx = Lne[x][j];
        else
          nx = Lne[y][j];
        if (Rne[x][j] + r[Rne[x][j]] > Rne[y][j] + r[Rne[y][j]])
          ny = Rne[x][j];
        else
          ny = Rne[y][j];
        x = nx;
        y = ny;
      }
    }
    if (n != 1)
      printf("%d ", ans + 1);
    else
      printf("0\n");
  }
  return 0;
}
