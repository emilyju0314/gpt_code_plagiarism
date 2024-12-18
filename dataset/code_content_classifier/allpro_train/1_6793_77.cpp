#include <bits/stdc++.h>
int n, m;
char a[2001][2001];
void f(int x1, int y) {
  if (x1 == -1 || y == -1 || (x1 == n - 1) || (y == m - 1)) return;
  int s = 0;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) s += (a[x1 + i][y + j] == '*');
  if (s == 1) {
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++) a[x1 + i][y + j] = '.';
    for (int i = -1; i < 2; i++)
      for (int j = -1; j < 2; j++) f(x1 + i, y + j);
  }
}
int main() {
  scanf("%d%d\n", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) a[i][j] = getchar();
    getchar();
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) f(i, j);
  for (int i = 0; i < n; i++) {
    printf("%s\n", a[i]);
  }
  return 0;
}
