#include <bits/stdc++.h>
using namespace std;
struct edge {
  int t, next;
} e[100005 * 2];
int ecnt, head[100005];
void addedge(int f, int t) {
  e[++ecnt] = (edge){t, head[f]};
  head[f] = ecnt;
  e[++ecnt] = (edge){f, head[t]};
  head[t] = ecnt;
}
int n, m;
int query[100005][2];
void init() {
  scanf("%d%d", &n, &m);
  for (int i = 1, f, t; i < n; i++) scanf("%d%d", &f, &t), addedge(f, t);
  for (int i = 1; i <= m; i++) scanf("%d%d", &query[i][0], &query[i][1]);
}
int dep[100005], sz[100005];
int fa[100005][20];
long long sum[100005], ssum[100005];
void DFS1(int u, int fr, int deep) {
  sz[u] = 1;
  dep[u] = deep;
  fa[u][0] = fr;
  for (int i = 1; (1 << i) <= deep; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (int i = head[u]; i; i = e[i].next) {
    if (e[i].t != fr)
      DFS1(e[i].t, u, deep + 1), sz[u] += sz[e[i].t],
          ssum[u] += ssum[e[i].t] + sz[e[i].t];
  }
}
void DFS2(int u, int fr, long long s) {
  if (fr == 0)
    sum[u] = ssum[u];
  else
    sum[u] = s - sz[u] + sz[1] - sz[u];
  for (int i = head[u]; i; i = e[i].next) {
    if (e[i].t != fr) DFS2(e[i].t, u, sum[u]);
  }
}
int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  int d = dep[u] - dep[v];
  for (int i = 0; i < 20; i++)
    if (d & (1 << i)) u = fa[u][i];
  if (u == v) return v;
  for (int i = 19; i >= 0; i--)
    if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
  return fa[u][0];
}
int get(int v, int u) {
  int d = dep[u] - dep[v] - 1;
  for (int i = 0; i < 20; i++)
    if (d & (1 << i)) u = fa[u][i];
  return u;
}
void solve() {
  long double ans = 0;
  for (int i = 1; i <= m; i++) {
    int u = query[i][0], v = query[i][1], lc = lca(u, v);
    if (dep[u] > dep[v]) swap(u, v);
    if (lc == u) {
      int w = get(u, v);
      ans = dep[v] - dep[u] + ssum[v] / (long double)sz[v] +
            (sum[u] - ssum[w] - sz[w]) / (long double)(sz[1] - sz[w]) + 1;
    } else {
      ans = dep[u] + dep[v] - dep[lc] * 2 + 1 + ssum[u] / (long double)sz[u] +
            ssum[v] / (long double)sz[v];
    }
    printf("%.10lf\n", (double)ans);
  }
}
int main() {
  init();
  DFS1(1, 0, 0);
  DFS2(1, 0, 0);
  solve();
  return 0;
}
