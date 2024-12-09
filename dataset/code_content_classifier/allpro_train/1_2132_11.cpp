#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > g[20010], que[20010];
pair<int, int> p[20010];
int st[20010];
int n, q;
int ans[20010];
int dep[20010], ch[20010 << 1], comp[20010];
int vis[20010], now;
void dfs(int u, int fa) {
  for (pair<int, int> v : g[u])
    if (v.first != fa)
      p[v.first] = pair<int, int>(u, v.second), dfs(v.first, u);
}
int check(int u, int v) {
  now++;
  dep[v] = n;
  int cur = v, ret = -1;
  while (cur != u) {
    ch[dep[cur]] = p[cur].second;
    vis[cur] = now;
    comp[cur] = 1;
    dep[p[cur].first] = dep[cur] - 1;
    cur = p[cur].first;
    ret++;
  }
  vis[u] = now, comp[u] = 1;
  for (int i = 1; i <= n; i++)
    if (vis[i] != now) {
      int top = 0, cur = i;
      while (vis[cur] != now) st[top++] = cur, cur = p[cur].first;
      for (int j = top - 1; j >= 0; j--) {
        int w = st[j];
        dep[w] = dep[p[w].first] + 1;
        vis[w] = now;
        if (comp[p[w].first] != 1)
          comp[w] = comp[p[w].first];
        else if (p[w].second == ch[dep[w]])
          comp[w] = 1;
        else if (p[w].second < ch[dep[w]])
          comp[w] = 0;
        else
          comp[w] = 2;
        if (comp[w] == 0 || (comp[w] == 1 && dep[w] < dep[v])) ret++;
      }
    }
  return ret;
}
void solve(int u, int fa) {
  for (pair<int, int> v : que[u]) ans[v.second] = check(u, v.first);
  int tmp = p[u].second;
  for (pair<int, int> v : g[u])
    if (v.first != fa) {
      p[u] = v;
      solve(v.first, u);
    }
  p[u] = pair<int, int>(fa, tmp);
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i < n; i++) {
    int x, y;
    char c[2];
    scanf("%d%d%s", &x, &y, c);
    g[x].push_back(pair<int, int>(y, c[0])),
        g[y].push_back(pair<int, int>(x, c[0]));
  }
  dfs(1, 0);
  for (int i = 1; i <= q; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    que[x].push_back(pair<int, int>(y, i));
  }
  solve(1, 0);
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
  return 0;
}
