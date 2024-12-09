#include <bits/stdc++.h>
using namespace std;
const int N = 100010, M = 5000010, INF = 1e18;
int n, m, S, T, head[N], tot = 1, q[N], d[N], cur[N];
struct E {
  int ver, nxt, ww, w;
} e[M];
inline void add_e(int u, int v, int w) {
  e[++tot] = (E){v, head[u], 0, w}, head[u] = tot;
}
inline void add(int u, int v, int w) {
  add_e(u, v, w);
  add_e(v, u, 0);
}
bool bfs() {
  int hh = 0, tt = 0;
  memset(d, -1, sizeof d);
  q[0] = S, d[S] = 0, cur[S] = head[S];
  while (hh <= tt) {
    int x = q[hh++];
    for (int i = head[x]; i; i = e[i].nxt) {
      int y = e[i].ver, z = e[i].w;
      if (d[y] == -1 && z) {
        d[y] = d[x] + 1;
        cur[y] = head[y];
        if (y == T) return 1;
        q[++tt] = y;
      }
    }
  }
  return 0;
}
int find(int u, int limit) {
  if (u == T) return limit;
  int flow = 0;
  for (int i = cur[u]; i && flow < limit; i = e[i].nxt) {
    int y = e[i].ver, z = e[i].w;
    cur[u] = i;
    if (d[y] == d[u] + 1 && z) {
      int t = find(y, min(z, limit - flow));
      if (!t) d[y] = -1;
      e[i].w -= t, e[i ^ 1].w += t, flow += t;
    }
  }
  return flow;
}
int Dinic() {
  int r = 0, flow;
  while (bfs())
    while (flow = find(S, INF)) r += flow;
  return r;
}
bool check(int mid) {
  for (int i = 2; i <= tot; i += 2)
    if (e[i].ww > 0 && e[i].ww <= mid) {
      e[i].w = 1;
      e[i ^ 1].w = 0;
    } else if (e[i].ww > 0)
      e[i].w = 0, e[i ^ 1].w = 0;
    else if (e[i].ww == 0)
      e[i].w = 1, e[i ^ 1].w = 0;
  int res = Dinic();
  return (res >= n);
}
signed main() {
  scanf("%d%d", &n, &m);
  S = n * 2 + 1, T = S + 1;
  for (int i = 1; i <= n; ++i) add(S, i, 1);
  for (int i = 1; i <= n; ++i) add(i + n, T, 1);
  for (int i = 1, u, v, w; i <= m; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    add(u, v + n, w);
    e[tot].ww = e[tot ^ 1].ww = w;
  }
  int L = 0, R = 1e9;
  while (L < R) {
    int mid = (L + R) >> 1;
    if (check(mid))
      R = mid;
    else
      L = mid + 1;
  }
  if (L == 1e9) return puts("-1"), 0;
  printf("%d", L);
  return 0;
}
