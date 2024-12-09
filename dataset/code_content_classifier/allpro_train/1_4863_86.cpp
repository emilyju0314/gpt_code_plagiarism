#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int v, nxt;
} e[800010];
int tot;
int first[400010];
void build(int u, int v) {
  e[++tot] = (Edge){v, first[u]};
  first[u] = tot;
  return;
}
int fa[400010][21], dep[400010];
void dfs(int u, int lst) {
  dep[u] = dep[lst] + 1;
  fa[u][0] = lst;
  for (int i = 1; i <= 20; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (int i = first[u]; i; i = e[i].nxt)
    if (e[i].v != lst) dfs(e[i].v, u);
  return;
}
int getlca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  int need = dep[x] - dep[y], now = 0;
  while (need) {
    if (need & 1) x = fa[x][now];
    now++;
    need >>= 1;
  }
  if (x == y) return x;
  for (int i = 20; i >= 0; i--)
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  return fa[x][0];
}
int jump(int u, int x) {
  int now = 0;
  while (x) {
    if (x & 1) u = fa[u][now];
    now++;
    x >>= 1;
  }
  return u;
}
int walk(int u, int v, int x) {
  int lca = getlca(u, v);
  if (dep[u] - dep[lca] >= x) return jump(u, x);
  return jump(v, dep[u] + dep[v] - dep[lca] * 2 - x);
}
int f[400010];
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
bool merge(int x, int y) {
  int f1 = find(x), f2 = find(y);
  if (f1 == f2) return false;
  f[f2] = f1;
  return true;
}
int n, k, r;
int a[200010], dis[400010];
void bfs() {
  memset(dis, 0x3f, sizeof(dis));
  queue<int> q;
  for (int i = 1; i <= r; i++) q.push(a[i]), dis[a[i]] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (dis[u] >= k) continue;
    for (int i = first[u]; i; i = e[i].nxt) {
      int v = e[i].v;
      merge(u, v);
      if (dis[v] > n) {
        dis[v] = dis[u] + 1;
        q.push(v);
      }
    }
  }
  return;
}
bool solve() {
  int x, y;
  scanf("%d %d", &x, &y);
  int lca = getlca(x, y);
  if (dep[x] + dep[y] - 2 * dep[lca] <= 2 * k) return true;
  if (find(walk(x, y, k)) == find(walk(y, x, k))) return true;
  return false;
}
int main() {
  scanf("%d %d %d", &n, &k, &r);
  int N = n;
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    N++;
    build(u, N);
    build(N, u);
    build(v, N);
    build(N, v);
  }
  for (int i = 1; i <= r; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= N; i++) f[i] = i;
  dfs(1, 0);
  bfs();
  int q;
  scanf("%d", &q);
  while (q--) {
    if (solve())
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
