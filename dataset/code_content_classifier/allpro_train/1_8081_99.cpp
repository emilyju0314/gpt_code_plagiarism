#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int hed[N], ed, d[N], cir, f[N][2], p[N], cnt, x, u, v, n, m, dfsc;
vector<int> G[N], ans;
bool vis[N];
struct edge {
  int to, nex;
  edge(int _ = 0, int __ = 0) : to(_), nex(__) {}
} e[N << 1];
inline void add(int u, int v) {
  e[++ed] = edge(v, hed[u]);
  hed[u] = ed;
}
void dfs(int u, int fa) {
  vis[u] = 1;
  for (int i = hed[u], v = e[i].to; i; i = e[i].nex, v = e[i].to)
    if (v ^ fa) {
      if (!vis[v])
        d[v] = d[u] + 1, G[u].push_back(v), p[v] = i + 1 >> 1, dfs(v, u);
      else if (d[u] > d[v]) {
        int t = d[u] % 2 == d[v] % 2;
        f[v][t]--, f[u][t]++;
        assert(abs(f[u][t]) <= 1e4 && abs(f[v][t]) <= 1e4);
        cir += t;
        if (t) x = i + 1 >> 1;
      }
    }
}
void DFS(int u, int fa) {
  for (int &v : G[u])
    if (v ^ fa) DFS(v, u), f[u][0] += f[v][0], f[u][1] += f[v][1];
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (m); ++i) {
    scanf("%d%d", &u, &v), add(u, v), add(v, u);
  }
  for (int i = (1); i <= (n); ++i)
    if (!vis[i]) dfs(i, 0), DFS(i, 0);
  for (int i = (2); i <= (n); ++i)
    if (f[i][0] && f[i][1]) ++cnt;
  if (!cir) {
    printf("%d\n", m);
    for (int i = (1); i <= (m); ++i) printf("%d ", i);
    return 0;
  }
  if (cir == 1) ans.push_back(x);
  if (!cnt && cir == 1) {
    for (int i = (2); i <= (n); ++i)
      if (f[i][1] == 1) ans.push_back(p[i]);
  } else
    for (int i = (2); i <= (n); ++i)
      if (f[i][1] == cir && !f[i][0]) ans.push_back(p[i]);
  printf("%lu\n", ans.size());
  sort(ans.begin(), ans.end());
  for (int &x : ans) printf("%d ", x);
  return 0;
}
