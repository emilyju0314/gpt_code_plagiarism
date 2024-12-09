#include <bits/stdc++.h>
using namespace std;
const int N = 50005, M = N * 17, mod = 1e9 + 7;
inline void gmin(int &x, int y) {
  if (x > y) x = y;
}
inline void gmax(int &x, int y) {
  if (x < y) x = y;
}
inline void ch(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
struct node {
  int to, next, cap;
} p[M << 1];
int n, m, S, T, tot, cnt, head[M], st[M];
int dep[N], dp[N][17], num[N][17], fa[N];
bool vis[M];
vector<int> g[N], f[N], res;
int q[M];
inline void add(int x, int y, int z) {
  p[++tot] = (node){y, head[x], z};
  head[x] = tot;
  p[++tot] = (node){x, head[y], 0};
  head[y] = tot;
}
inline bool bfs() {
  memset(st, 0, sizeof(st));
  int l = 1, r = 1;
  q[r] = S;
  st[S] = 1;
  while (l <= r) {
    int x = q[l++];
    for (int i = head[x]; i; i = p[i].next) {
      if (!p[i].cap) continue;
      int y = p[i].to;
      if (st[y]) continue;
      q[++r] = y;
      st[y] = st[x] + 1;
    }
  }
  return st[T] > 0;
}
inline int dfs(int x, int f) {
  if (x == T) return f;
  int r = 0;
  for (int i = head[x]; i; i = p[i].next) {
    if (!p[i].cap) continue;
    int y = p[i].to;
    if (st[y] != st[x] + 1) continue;
    int tmp = dfs(y, min(f - r, p[i].cap));
    p[i].cap -= tmp;
    p[i ^ 1].cap += tmp;
    r += tmp;
    if (r == f) break;
  }
  if (!r) st[x] = -2;
  return r;
}
int dinic() {
  int ans = 0, t;
  while (bfs())
    while (t = dfs(S, 0x3f3f3f)) ans += t;
  return ans;
}
inline void dfs(int x) {
  vis[x] = 1;
  for (int i = 0; i < g[x].size(); i++) {
    int y = g[x][i];
    if (vis[y]) continue;
    dep[y] = dep[x] + 1;
    dp[y][0] = x;
    fa[y] = f[x][i];
    dfs(y);
  }
}
inline void search(int x) {
  if (vis[x]) return;
  vis[x] = 1;
  for (int i = head[x]; i; i = p[i].next)
    if (p[i].cap) search(p[i].to);
}
void print(vector<int> a) {
  sort(a.begin(), a.end());
  printf("%d", (int)a.size());
  for (auto i : a) printf(" %d", i);
  puts("");
}
int main() {
  tot = 1;
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
    f[x].push_back(i);
    f[y].push_back(i);
  }
  dfs(1);
  for (int j = 1; j < 15; j++)
    for (int i = 1; i <= n; i++) dp[i][j] = dp[dp[i][j - 1]][j - 1];
  S = 0;
  T = n * 16 + m + 10000;
  cnt = m;
  for (int i = 1; i <= n; i++)
    if (dp[i][0]) num[i][0] = ++cnt, add(cnt, T, 1);
  for (int j = 1; j < 15; j++)
    for (int i = 1; i <= n; i++) {
      if (!dp[i][j]) continue;
      num[i][j] = ++cnt;
      add(cnt, num[i][j - 1], 0x3f3f3f);
      add(cnt, num[dp[i][j - 1]][j - 1], 0x3f3f3f);
    }
  for (int i = 1; i <= m; i++) {
    add(S, i, 1);
    int x, y, t;
    scanf("%d%d", &x, &y);
    if (dep[x] < dep[y]) swap(x, y);
    t = dep[x] - dep[y];
    for (int j = 0; j < 15; j++)
      if (t & (1 << j)) add(i, num[x][j], 0x3f3f3f), x = dp[x][j];
    if (x == y) continue;
    for (int j = 14; ~j; j--)
      if (dp[x][j] != dp[y][j])
        add(i, num[x][j], 0x3f3f3f), add(i, num[y][j], 0x3f3f3f), x = dp[x][j],
                                                                  y = dp[y][j];
    add(i, num[x][0], 0x3f3f3f), add(i, num[y][0], 0x3f3f3f);
  }
  printf("%d\n", dinic());
  memset(vis, 0, sizeof(vis));
  search(S);
  res.clear();
  for (int i = 1; i <= m; i++)
    if (!vis[i]) res.push_back(i);
  print(res);
  res.clear();
  for (int i = 1; i <= n; i++)
    if (dp[i][0] && vis[num[i][0]]) res.push_back(fa[i]);
  print(res);
  return 0;
}
