#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
struct Edge {
  int to, nt;
} e[N << 1];
int n, m, cnt, ft[N], dis[N], s, t, a[N], v[N], pre[N], vis[N], tot;
int f[18][N], g[18][N], fa[N], Log[N];
queue<int> Q;
int read() {
  int x = 0, o = 1;
  char ch = getchar();
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
void Add(int u, int v) {
  e[++cnt] = (Edge){v, ft[u]};
  ft[u] = cnt;
}
int bfs(int st) {
  memset(dis, 0, sizeof(dis));
  dis[st] = 1, pre[st] = 0, Q.push(st);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int i = ft[u]; i; i = e[i].nt) {
      int v = e[i].to;
      if (!dis[v]) {
        dis[v] = dis[u] + 1;
        pre[v] = u, Q.push(v);
      }
    }
  }
  int id = 0;
  for (int i = 1; i <= n; i++)
    if (dis[i] > dis[id]) id = i;
  return id;
}
int dfs(int u, int Fa, int Rt) {
  dis[u] = dis[Fa] + 1, fa[u] = Rt;
  int mx = dis[u];
  for (int i = ft[u]; i; i = e[i].nt) {
    int v = e[i].to;
    if (v == Fa || vis[v]) continue;
    mx = max(mx, dfs(v, u, Rt));
  }
  return mx;
}
int RMQ(int l, int r, int o) {
  int k = Log[r - l + 1];
  if (!o)
    return max(f[k][r], f[k][l + (1 << k) - 1]);
  else
    return max(g[k][l], g[k][r - (1 << k) + 1]);
}
int Query(int x, int y) {
  int fx = fa[x], fy = fa[y];
  if (fx == fy) {
    if (dis[x] > dis[y]) swap(x, y);
    return dis[x] - 1 + max(fx - 1, tot - fx);
  } else {
    if (fx > fy) swap(fx, fy), swap(x, y);
    int d = dis[x] + dis[y] - 2 + fy - fx, dd = d >> 1;
    if (dis[x] - 1 > dd)
      return dis[y] - 1 + max(fy - 1, tot - fy);
    else if (dis[y] - 1 > dd)
      return dis[x] - 1 + max(fx - 1, tot - fx);
    else {
      int p1 = fx + dd - (dis[x] - 1), mx = 0;
      int p2 = fy - ((d - dd) - (dis[y] - 1)) + 1;
      if (fx > 1) mx = max(mx, RMQ(1, fx - 1, 0) + fx + dis[x] - 1);
      if (fx < p1) mx = max(mx, RMQ(fx + 1, p1, 1) + tot - fx + dis[x] - 1);
      if (fy > p2) mx = max(mx, RMQ(p2, fy - 1, 0) + fy + dis[y] - 1);
      if (fy < tot) mx = max(mx, RMQ(fy + 1, tot, 1) + tot - fy + dis[y] - 1);
      return mx;
    }
  }
  return 0;
}
int main() {
  n = read();
  for (int i = 1; i < n; i++) {
    int u = read(), v = read();
    Add(u, v), Add(v, u);
  }
  s = bfs(1), t = bfs(s), tot = dis[t];
  for (int x = t; x; x = pre[x]) a[dis[x]] = x, vis[x] = 1;
  memset(f, -63, sizeof(f));
  memset(g, -63, sizeof(g));
  for (int i = 1; i <= tot; i++) {
    v[i] = dfs(a[i], 0, i) - 1;
    f[0][i] = v[i] - i;
    g[0][i] = v[i] - tot + i;
  }
  for (int i = 2; i <= tot; i++) Log[i] = Log[i / 2] + 1;
  for (int i = 1; i <= 17; i++)
    for (int j = 1; j <= tot; j++) {
      if (j - (1 << i) + 1 >= 1)
        f[i][j] = max(f[i - 1][j], f[i - 1][j - (1 << (i - 1))]);
      if (j + (1 << i) - 1 <= n)
        g[i][j] = max(g[i - 1][j], g[i - 1][j + (1 << (i - 1))]);
    }
  m = read();
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    printf("%d\n", Query(x, y));
  }
  return 0;
}
