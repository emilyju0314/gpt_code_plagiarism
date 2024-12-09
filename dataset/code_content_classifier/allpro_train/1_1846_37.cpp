#include <bits/stdc++.h>
using namespace std;
int g[105][105], vis[105][105];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void dfs(int x, int y) {
  vis[x][y] = 1;
  for (int i = (0); i <= (3); ++i) {
    int u = x + dir[i][0], v = y + dir[i][1];
    if (g[u][v] && !vis[u][v]) dfs(u, v);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cout.setf(ios::fixed);
  cout.precision(20);
  int n, m, num = 0;
  cin >> n >> m;
  memset(g, 0, sizeof(g));
  char tmp;
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (m); ++j) {
      cin >> tmp;
      g[i][j] = tmp == '#' ? 1 : 0;
      num += tmp == '#' ? 1 : 0;
    }
  int ans = 0;
  memset(vis, 0, sizeof(vis));
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (m); ++j)
      if (g[i][j] && !vis[i][j]) {
        dfs(i, j);
        ans++;
      }
  if (ans > 1) return 0 * puts("0");
  if (num < 3) return 0 * puts("-1");
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (m); ++j)
      if (g[i][j]) {
        memset(vis, 0, sizeof(vis));
        vis[i][j] = 1;
        int h = 0;
        for (int k = (0); k <= (3); ++k) {
          int u = i + dir[k][0], v = j + dir[k][1];
          if (g[u][v] && !vis[u][v]) dfs(u, v), h++;
        }
        if (h > 1) return 0 * puts("1");
      }
  puts("2");
  return 0;
}
