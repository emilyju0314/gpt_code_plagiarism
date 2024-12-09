#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e3 + 5, maxm = 6e3 + 5, inf = 0x3f3f3f3f;
int ans = inf, head[maxn], nxt[maxm], w[maxm], to[maxm], edge_sum;
void add(int u, int v) {
  nxt[++edge_sum] = head[u];
  to[edge_sum] = v;
  w[edge_sum] = 1;
  head[u] = edge_sum;
}
queue<int> q;
int used[maxn], dis[maxn][maxn];
void SPFA(int s) {
  memset(used, 0, sizeof used);
  while (q.size()) q.pop();
  dis[s][s] = 0, used[s] = 1;
  q.push(s);
  while (q.size()) {
    int x = q.front();
    q.pop(), used[x] = 0;
    for (int i = head[x]; i != 0; i = nxt[i]) {
      int y = to[i], z = w[i];
      if (dis[x][s] + z < dis[y][s]) {
        dis[y][s] = dis[x][s] + z;
        if (!used[y]) q.push(y), used[y] = 1;
      }
    }
  }
}
int main() {
  int n, m, s1, t1, l1, s2, t2, l2;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v), add(v, u);
  }
  scanf("%d%d%d", &s1, &t1, &l1);
  scanf("%d%d%d", &s2, &t2, &l2);
  memset(dis, inf, sizeof(dis));
  for (int i = 1; i <= n; i++) SPFA(i);
  if (dis[s1][t1] > l1 || dis[s2][t2] > l2) {
    puts("-1");
    return 0;
  }
  int ans = m - dis[s1][t1] - dis[s2][t2];
  if (ans < 0) ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (dis[s1][i] + dis[i][j] + dis[j][t1] <= l1)
        if (dis[s2][i] + dis[i][j] + dis[j][t2] <= l2)
          ans = max(ans, m - dis[i][j] - dis[s1][i] - dis[s2][i] - dis[j][t1] -
                             dis[j][t2]);
      if (dis[s1][j] + dis[j][i] + dis[i][t1] <= l1)
        if (dis[s2][i] + dis[i][j] + dis[j][t2] <= l2)
          ans = max(ans, m - dis[i][j] - dis[s1][j] - dis[s2][i] - dis[i][t1] -
                             dis[j][t2]);
      if (dis[s1][i] + dis[i][j] + dis[j][t1] <= l1)
        if (dis[s2][j] + dis[j][i] + dis[i][t2] <= l2)
          ans = max(ans, m - dis[i][j] - dis[s1][i] - dis[s2][j] - dis[j][t1] -
                             dis[i][t2]);
      if (dis[s1][j] + dis[j][i] + dis[i][t1] <= l1)
        if (dis[s2][j] + dis[j][i] + dis[i][t2] <= l2)
          ans = max(ans, m - dis[j][i] - dis[s1][j] - dis[s2][j] - dis[i][t1] -
                             dis[i][t2]);
    }
  printf("%d\n", ans);
  return 0;
}
