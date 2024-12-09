#include <bits/stdc++.h>
using namespace std;
int n;
int a[2000][2000], b[2000][2000];
bool used[2000][2000];
int pi[2000 * 2000], pj[2000 * 2000];
int num;
int circles, squares;
void check() {
  if (num < 100) return;
  int i0 = (1 << 30), i1 = -(1 << 30), j0 = (1 << 30), j1 = -(1 << 30);
  for (int k = 0; k < num; k++) {
    int i = pi[k], j = pj[k];
    i0 = min(i0, i), i1 = max(i1, i), j0 = min(j0, j), j1 = max(j1, j);
  }
  double ic = 0.5 * (i0 + i1), jc = 0.5 * (j0 + j1);
  double r2 = 0;
  for (int k = 0; k < num; k++) {
    double di = ic - pi[k], dj = jc - pj[k];
    r2 = max(r2, di * di + dj * dj);
  }
  double ratio = 1.0 * num / r2;
  if (ratio > 2.6)
    circles++;
  else
    squares++;
}
void dfs(int i, int j) {
  if (used[i][j] || b[i][j] == 0) return;
  used[i][j] = true;
  pi[num] = i, pj[num] = j, num++;
  if (i + 1 < n) dfs(i + 1, j);
  if (i > 0) dfs(i - 1, j);
  if (j + 1 < n) dfs(i, j + 1);
  if (j > 0) dfs(i, j - 1);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      int cnt = 0;
      for (int di = -2; di <= 2; di++)
        for (int dj = -2; dj <= 2; dj++) {
          int ii = i + di, jj = j + dj;
          if (ii >= 0 && jj >= 0 && ii < n && jj < n && a[ii][jj] == 1) cnt++;
        }
      b[i][j] = (cnt > 12) ? 1 : 0;
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (!used[i][j] && b[i][j] == 1) {
        num = 0;
        dfs(i, j);
        check();
      }
  printf("%d %d\n", circles, squares);
}
