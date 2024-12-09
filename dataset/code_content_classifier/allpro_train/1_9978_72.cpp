#include <bits/stdc++.h>
using namespace std;
string s;
int togo[2500][8];
int comp[50][50], field[51][51];
int maxi[2500], maxj[2500], mini[2500], minj[2500];
int m, n, k;
int curcomp;
char rev(char x) {
  char res = 0;
  for (int i = 0; i < 8; i++) {
    res = res * 2 + (x % 2);
    x /= 2;
  }
  return res;
}
void dfs(int i, int j, int c, int ind) {
  if (field[i][j] != ind || comp[i][j] || field[i][j] == 0) return;
  comp[i][j] = c;
  if (i > 0) dfs(i - 1, j, c, ind);
  if (j > 0) dfs(i, j - 1, c, ind);
  if (i < n - 1) dfs(i + 1, j, c, ind);
  if (j < m - 1) dfs(i, j + 1, c, ind);
  if (i > maxi[c]) maxi[c] = i;
  if (i < mini[c]) mini[c] = i;
  if (j > maxj[c]) maxj[c] = j;
  if (j < minj[c]) minj[c] = j;
}
inline int _search(int curcomp) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (comp[i][j] == curcomp) return field[i][j];
}
inline void check(int steps) {
  if (steps == k) {
    cout << _search(curcomp);
    exit(0);
  }
}
int main() {
  for (int c = 0; c < 2500; c++) {
    maxi[c] = maxj[c] = -1;
    mini[c] = minj[c] = 2147483647;
  }
  scanf("%d%d\n", &n, &k);
  for (int i = 0; i < n; i++) {
    m = 0;
    char c;
    while (scanf("%c", &c) == 1 && c != '\n') field[i][m++] = c - '0';
  }
  memset(comp, 0, sizeof(comp));
  curcomp = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (!comp[i][j] && field[i][j]) dfs(i, j, curcomp++, field[i][j]);
  for (int c = 1; c < curcomp; c++) {
    int i = maxi[c];
    if (i < n - 1) {
      for (int j = 0; j < m; j++)
        if (comp[i][j] == c) togo[c][2] = comp[i + 1][j];
      for (int j = 0; j < m; j++)
        if (comp[i][j] == c) {
          togo[c][3] = comp[i + 1][j];
          break;
        }
    }
    i = mini[c];
    if (i > 0) {
      for (int j = 0; j < m; j++)
        if (comp[i][j] == c) togo[c][7] = comp[i - 1][j];
      for (int j = 0; j < m; j++)
        if (comp[i][j] == c) {
          togo[c][6] = comp[i - 1][j];
          break;
        }
    }
    int j = maxj[c];
    if (j < m - 1) {
      for (i = 0; i < n; i++)
        if (comp[i][j] == c) togo[c][1] = comp[i][j + 1];
      for (i = 0; i < n; i++)
        if (comp[i][j] == c) {
          togo[c][0] = comp[i][j + 1];
          break;
        }
    }
    j = minj[c];
    if (j > 0) {
      for (i = 0; i < n; i++)
        if (comp[i][j] == c) togo[c][4] = comp[i][j - 1];
      for (i = 0; i < n; i++)
        if (comp[i][j] == c) {
          togo[c][5] = comp[i][j - 1];
          break;
        }
    }
  }
  int curdir = 0;
  curcomp = comp[0][0];
  int startcomp = curcomp, steps = 0;
  while (togo[curcomp][curdir] == 0 && steps < k)
    curdir = (curdir + 1) % 8, steps++;
  check(steps);
  if (togo[curcomp][curdir]) {
    curcomp = togo[curcomp][curdir];
    steps++;
    check(steps);
  }
  while (1) {
    while (togo[curcomp][curdir] == 0 && steps < k)
      curdir = (curdir + 1) % 8, steps++;
    check(steps);
    curcomp = togo[curcomp][curdir];
    steps++;
    check(steps);
  }
  while (curdir != 0 && steps < k) curdir = (curdir + 1) % 8, steps++;
  check(k);
  return 0;
}
