#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int n, m, from[MAXN], to[MAXN], h[MAXN];
vector<int> adj[MAXN];
bool vis[MAXN];
void fix(int e) {
  if (h[from[e]] > h[to[e]]) swap(from[e], to[e]);
}
bool better(int e1, int e2) {
  if (e2 == -1) return true;
  if (e1 == -1) return false;
  fix(e1), fix(e2);
  return h[from[e1]] < h[from[e2]];
}
void upd(pair<int, int> &a, int b) {
  if (better(b, a.second)) {
    a.second = b;
    if (better(a.second, a.first)) swap(a.first, a.second);
  }
}
pair<int, int> g[MAXN];
bool in[MAXN];
int c[MAXN];
pair<int, int> dfs(int v, int p) {
  vis[v] = true;
  pair<int, int> res(-1, -1);
  for (int e : adj[v])
    if (e ^ p) {
      int u = from[e] ^ to[e] ^ v;
      if (vis[u])
        upd(res, e);
      else {
        h[u] = h[v] + 1;
        auto x = dfs(u, e);
        upd(res, x.first);
        upd(res, x.second);
      }
    }
  fix(res.second);
  if (h[from[res.second]] >= h[v]) res.second = -1;
  fix(res.first);
  if (h[from[res.first]] >= h[v]) res.first = -1;
  g[v] = res;
  return res;
}
void dfs2(int v, int p) {
  vis[v] = true;
  c[v] += g[v].second != -1;
  for (int e : adj[v]) {
    int u = from[e] ^ to[e] ^ v;
    if (!vis[u]) {
      c[u] = c[v];
      dfs2(u, v);
    }
  }
}
void dfs3(int v, int p) {
  vis[v] = true;
  for (int e : adj[v]) {
    int u = from[e] ^ to[e] ^ v;
    if (!vis[u]) {
      in[e] = (g[u].first != -1 && in[g[u].first]);
      dfs3(u, v);
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &from[i], &to[i]);
    from[i]--, to[i]--;
    adj[from[i]].push_back(i);
    adj[to[i]].push_back(i);
  }
  for (int v = 0; v < n; v++)
    if (!vis[v]) dfs(v, -1);
  memset(vis, 0, sizeof(vis));
  for (int v = 0; v < n; v++)
    if (!vis[v]) dfs2(v, -1);
  for (int e = 0; e < m; e++) {
    fix(e);
    if (h[from[e]] + 1 != h[to[e]]) in[e] = (c[to[e]] - c[from[e]] == 0);
  }
  memset(vis, 0, sizeof(vis));
  for (int v = 0; v < n; v++)
    if (!vis[v]) dfs3(v, -1);
  int t = 0;
  for (int e = 0; e < m; e++)
    if (in[e]) t++;
  printf("%d\n", t);
  for (int e = 0; e < m; e++)
    if (in[e]) printf("%d ", e + 1);
  printf("\n");
  return 0;
}
