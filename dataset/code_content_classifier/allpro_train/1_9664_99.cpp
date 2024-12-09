#include <bits/stdc++.h>
using namespace std;
int m, n;
const int inf = 0x3f3f3f3f;
struct node {
  int x, y;
  node(int x = 0, int y = 0) {
    this->x = x;
    this->y = y;
  }
};
const int mx[6] = {0, 1, 0, -1, 0};
const int my[6] = {0, 0, 1, 0, -1};
vector<node> f[90011];
int gg[301][301];
int g[301][301], x, y;
int p;
int dp[333][333];
struct pnode {
  int x, y, w;
  pnode(int xx = 0, int yy = 0, int ww = 0) {
    x = xx;
    y = yy;
    w = ww;
  }
  bool operator<(const pnode &head) const { return head.w < w; }
};
priority_queue<pnode> q;
int main() {
  scanf("%d%d%d", &m, &n, &p);
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) {
      dp[i][j] = inf;
      scanf("%d", &g[i][j]);
      f[g[i][j]].push_back(node(i, j));
    }
  f[0].push_back(node(1, 1));
  for (int ww = 1; ww <= p; ww++) {
    if ((long long)f[ww - 1].size() * f[ww].size() <= (long long)m * n * 8)
      for (int i = 0; i < f[ww - 1].size(); i++)
        for (int j = 0; j < f[ww].size(); j++) {
          int &tx = f[ww][j].x;
          int &ty = f[ww][j].y;
          int &fx = f[ww - 1][i].x;
          int &fy = f[ww - 1][i].y;
          if (ww == 1)
            dp[tx][ty] = abs(fx - tx) + abs(fy - ty);
          else
            dp[tx][ty] =
                min(dp[tx][ty], dp[fx][fy] + abs(fx - tx) + abs(fy - ty));
        }
    else {
      memset(gg, -1, sizeof(gg));
      while (!q.empty()) q.pop();
      for (int i = 0; i < f[ww - 1].size(); i++) {
        int x = f[ww - 1][i].x;
        int y = f[ww - 1][i].y;
        q.push(pnode(x, y, dp[x][y]));
        gg[x][y] = dp[x][y];
      }
      while (!q.empty()) {
        pnode u = q.top();
        q.pop();
        if (g[u.x][u.y] == ww) dp[u.x][u.y] = min(dp[u.x][u.y], gg[u.x][u.y]);
        for (int e = 1; e <= 4; e++) {
          int tx = u.x + mx[e];
          int ty = u.y + my[e];
          if (tx >= 1 && tx <= m && ty >= 1 && ty <= n && gg[tx][ty] == -1) {
            gg[tx][ty] = gg[u.x][u.y] + 1;
            q.push(pnode(tx, ty, gg[tx][ty]));
          }
        }
      }
    }
  }
  int ans = inf;
  for (int i = 0; i < f[p].size(); i++)
    ans = min(ans, dp[f[p][i].x][f[p][i].y]);
  cout << ans << endl;
  return 0;
}
