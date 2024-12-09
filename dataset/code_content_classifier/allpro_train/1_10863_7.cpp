#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1002;
char s[MAXN][MAXN];
int d[MAXN][MAXN];
bool vis[MAXN][MAXN];
int n, m, top = 0;
bool work() {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '.') continue;
      if (s[i][j] == 'b') return false;
      if (j + 1 < m && s[i][j + 1] != '.' && s[i][j + 2] != '.')
        d[i][j] = d[i][j + 1] = d[i][j + 2] = ++top,
        s[i][j] = s[i][j + 1] = s[i][j + 2] = '.';
      else if (i + 1 < n && s[i + 1][j] != '.' && s[i + 2][j] != '.')
        d[i][j] = d[i + 1][j] = d[i + 2][j] = ++top,
        s[i][j] = s[i + 1][j] = s[i + 2][j] = '.';
      else
        return false;
    }
  return true;
}
void dfs(int first, int second, bool flag) {
  vis[first][second] = true;
  s[first][second] = 'a' + flag;
  if (!vis[first + 1][second] && d[first + 1][second])
    dfs(first + 1, second, flag ^ (d[first][second] != d[first + 1][second]));
  if (!vis[first - 1][second] && d[first - 1][second])
    dfs(first - 1, second, flag ^ (d[first][second] != d[first - 1][second]));
  if (!vis[first][second + 1] && d[first][second + 1])
    dfs(first, second + 1, flag ^ (d[first][second] != d[first][second + 1]));
  if (!vis[first][second - 1] && d[first][second - 1])
    dfs(first, second - 1, flag ^ (d[first][second] != d[first][second - 1]));
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  if (work()) {
    printf("YES\n");
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        if (!vis[i][j] && d[i][j]) dfs(i, j, false);
    for (int i = 1; i <= n; i++) printf("%s\n", s[i] + 1);
  } else
    printf("NO\n");
  return 0;
}
