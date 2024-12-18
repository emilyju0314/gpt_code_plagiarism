#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int maxm = 2e5 + 5;
int n, m, x[maxm], y[maxm], k;
vector<int> v[maxn];
int dep[maxn];
int fa[maxn][21];
struct qlt {
  int n, num1;
  int b[maxn], next[maxm], a[maxm];
  int dfn[maxn], low[maxn];
  int stack[maxn], belong[maxn];
  bool instack[maxn];
  int num[maxn];
  int scc, top, index;
  void init(int nn) {
    n = nn;
    num1 = 0;
    memset(b, 0, sizeof(b));
  }
  void addedge(int x, int y) {
    ++num1;
    a[num1] = y;
    next[num1] = b[x];
    b[x] = num1;
  }
  void tarjan(int x, int fa) {
    int y;
    low[x] = dfn[x] = ++index;
    stack[top++] = x;
    instack[x] = true;
    for (int i = b[x]; i > 0; i = next[i]) {
      y = a[i];
      if (y == fa) continue;
      if (!dfn[y]) {
        tarjan(y, x);
        if (low[x] > low[y]) low[x] = low[y];
      } else if (instack[y] && low[x] > dfn[y])
        low[x] = dfn[y];
    }
    if (low[x] == dfn[x]) {
      scc++;
      do {
        y = stack[--top];
        instack[y] = false;
        belong[y] = scc;
        num[scc]++;
      } while (y != x);
    }
  }
  void solve() {
    memset(dfn, 0, sizeof(dfn));
    memset(instack, false, sizeof(instack));
    memset(num, 0, sizeof(num));
    index = scc = top = 0;
    for (int i = 1; i <= n; ++i)
      if (!dfn[i]) tarjan(i, -1);
  }
} mp;
void dfs(int x, int ga) {
  fa[x][0] = ga;
  dep[x] = dep[ga] + 1;
  for (int i = 1; i <= 20; ++i) fa[x][i] = fa[fa[x][i - 1]][i - 1];
  for (int i = 0; i < v[x].size(); ++i) {
    int y = v[x][i];
    if (y == ga) continue;
    dfs(y, x);
  }
}
int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  int d = dep[x] - dep[y];
  for (int i = 20; i >= 0; --i)
    if (d & (1 << i)) x = fa[x][i];
  if (x == y) return x;
  for (int i = 20; i >= 0; --i)
    if (fa[x][i] != fa[y][i]) {
      x = fa[x][i];
      y = fa[y][i];
    }
  return fa[x][0];
}
int main() {
  scanf("%d%d", &n, &m);
  mp.init(n);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &x[i], &y[i]);
    mp.addedge(x[i], y[i]);
    mp.addedge(y[i], x[i]);
  }
  mp.solve();
  for (int i = 1; i <= mp.scc; ++i) v[i].clear();
  for (int i = 0; i <= mp.scc; ++i) dep[i] = 0;
  for (int i = 1; i <= m; ++i) {
    if (mp.belong[x[i]] != mp.belong[y[i]]) {
      v[mp.belong[x[i]]].push_back(mp.belong[y[i]]);
      v[mp.belong[y[i]]].push_back(mp.belong[x[i]]);
    }
  }
  dfs(1, 0);
  scanf("%d", &k);
  while (k--) {
    int u, v, ans;
    scanf("%d%d", &u, &v);
    u = mp.belong[u];
    v = mp.belong[v];
    ans = dep[u] + dep[v] - 2 * dep[lca(u, v)];
    printf("%d\n", ans);
  }
  return 0;
}
