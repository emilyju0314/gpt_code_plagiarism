#include <bits/stdc++.h>
const int N = 52, INF = 0x3f3f3f3f;
std::queue<std::pair<int, int> > que;
bool vis[N][N];
char val[N][N];
int dist[N][N];
std::pair<int, int> add(std::pair<int, int> &a, std::pair<int, int> &b) {
  return std::pair<int, int>(a.first + b.first, a.second + b.second);
}
std::pair<int, int> di[] = {
    std::pair<int, int>(0, 1), std::pair<int, int>(1, 0),
    std::pair<int, int>(-1, 0), std::pair<int, int>(0, -1)};
int spfa(int first, int second, int n, int m) {
  memset(vis, 0, sizeof(val));
  memset(dist, 0x3f, sizeof(dist));
  que.push(std::pair<int, int>(first, second));
  vis[first][second] = true;
  dist[first][second] = 0;
  while (que.size()) {
    std::pair<int, int> u = que.front();
    que.pop();
    vis[u.first][u.second] = false;
    for (int i = 0; i < 4; i++) {
      std::pair<int, int> v = add(u, di[i]);
      if (v.first < 1 || n < v.first || v.second < 1 || m < v.second) continue;
      int nd = dist[u.first][u.second] +
               (val[u.first][u.second] != val[v.first][v.second] ? 1 : 0);
      if (dist[v.first][v.second] > nd) {
        dist[v.first][v.second] = nd;
        if (!vis[v.first][v.second]) que.push(v), vis[v.first][v.second] = true;
      }
    }
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (val[i][j] == 'B' && dist[i][j] > res) res = dist[i][j];
    }
  }
  return ++res;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  getchar();
  int ans = 0;
  for (int i = 1; i <= n; i++) scanf("%[^\n]%*c", &val[i][1]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (val[i][j] == 'B') ans = INF;
  if (ans)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) ans = std::min(ans, spfa(i, j, n, m));
  printf("%d\n", ans);
  return 0;
}
