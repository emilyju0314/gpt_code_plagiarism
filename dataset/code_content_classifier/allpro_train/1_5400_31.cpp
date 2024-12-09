#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
const double eps = 1e-8;
void read(int &k) {
  k = 0;
  char x = getchar();
  while (x < '0' || x > '9') x = getchar();
  while (x >= '0' && x <= '9') {
    k = k * 10 - 48 + x;
    x = getchar();
  }
}
int dist[6410], a[88][88], ans, n, m, SS, TT;
struct graph {
  int a[6410], b[100010 * 2], c[100010 * 2], d[100010 * 2], e[100010 * 2], p;
  int dd[6410 * 6410], ll, rr, vis[6410], last[6410];
  void addedge(int x, int y, int z, int w) {
    c[++p] = a[x];
    a[x] = p;
    b[p] = y;
    d[p] = z;
    e[p] = w;
    c[++p] = a[y];
    a[y] = p;
    b[p] = x;
    d[p] = 0;
    e[p] = -w;
  }
  void fareflow() {
    while (1) {
      memset(dist, 63, sizeof dist);
      dist[SS] = 0;
      memset(vis, 0, sizeof vis);
      for (vis[dd[ll = rr = 0] = SS] = 1; ll <= rr; ll++) {
        vis[dd[ll]] = 0;
        for (int i = a[dd[ll]]; i; i = c[i])
          if (d[i] && dist[b[i]] > dist[dd[ll]] + e[i]) {
            dist[b[i]] = dist[dd[ll]] + e[i];
            last[b[i]] = i;
            if (!vis[b[i]]) vis[dd[++rr] = b[i]] = 1;
          }
      }
      if (dist[TT] >= inf) return;
      int now = TT, cost = 0, flow = inf;
      for (; now != SS; now = b[last[now] ^ 1]) {
        flow = min(d[last[now]], flow);
        cost += e[last[now]];
      }
      ans += flow * cost;
      for (now = TT; now != SS; now = b[last[now] ^ 1]) {
        d[last[now]] -= flow;
        d[last[now] ^ 1] += flow;
      }
    }
  }
} A;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  A.p = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      for (int dir = 0; dir < 4; dir++) {
        int tx = i + dx[dir], ty = j + dy[dir];
        if (tx > 0 && tx <= n && ty > 0 && ty <= m)
          A.addedge((i - 1) * m + j, (tx - 1) * m + ty, 1,
                    a[i][j] != a[tx][ty]);
      }
      if ((i + j) & 1)
        A.addedge(0, (i - 1) * m + j, 1, 0);
      else
        A.addedge((i - 1) * m + j, n * m + 1, 1, 0);
    }
  SS = 0;
  TT = n * m + 1;
  A.fareflow();
  printf("%d\n", ans);
  return 0;
}
