#include <bits/stdc++.h>
using namespace std;
const int MAX = 22, ALPHA = 26, oo = 1 << 20;
int n;
char s[MAX][MAX];
int mask[MAX << 1][ALPHA];
int dp[MAX << 1][1 << 20];
bool used[MAX << 1][1 << 20];
int solve(int diag, int m, int c) {
  int ret = -oo;
  if (used[diag][m]) return dp[diag][m];
  if (diag == 2 * n - 2)
    ret = 0;
  else {
    for (int i = 0, _n = ALPHA; i < _n; ++i) {
      int newmask = (m | (m << 1)) & mask[diag + 1][i];
      if (newmask) ret = max(ret, -solve(diag + 1, newmask, i));
    }
  }
  if ((diag & 1) == 0)
    ret += (c == 1 ? 1 : c == 0 ? -1 : 0);
  else
    ret += (c == 1 ? -1 : c == 0 ? 1 : 0);
  used[diag][m] = true;
  return dp[diag][m] = ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 0, _n = n; i < _n; ++i) scanf("%s", s[i]);
  for (int i = 0, _n = 2 * n - 1; i < _n; ++i)
    for (int j = 0, _n = ALPHA; j < _n; ++j)
      for (int k = 0, _n = n; k < _n; ++k) {
        int x = k, y = i - x;
        if (y >= 0 && y < n && s[x][y] == j + 'a') mask[i][j] |= 1 << k;
      }
  int ret = solve(0, 1, s[0][0] - 'a');
  if (ret < 0) puts("FIRST");
  if (ret == 0) puts("DRAW");
  if (ret > 0) puts("SECOND");
  return 0;
}
