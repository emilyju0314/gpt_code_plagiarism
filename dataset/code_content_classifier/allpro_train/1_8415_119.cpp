#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int n, fa[N], son[N], f[N], d[N], dfn[N], ans, cnt;
vector<int> g[N];
inline void ckMax(register int &p, const int q) { p = (p > q ? p : q); }
inline void DFS(const int x) {
  d[x] = d[fa[x]] + 1;
  for (const int &j : g[x])
    DFS(j), f[j] + 1 >= f[x] ? son[x] = j, f[x] = f[j] + 1 : 0;
}
inline void dfs(const int x) {
  dfn[++cnt] = x;
  if (!son[x]) return;
  for (const int &j : g[x])
    if (j ^ son[x]) dfs(j);
  dfs(son[x]);
}
int main() {
  scanf("%d", &n);
  register int i;
  for (i = 2; i <= n; ++i) scanf("%d", &fa[i]), ++fa[i], g[fa[i]].push_back(i);
  DFS(1), dfs(1);
  for (i = 1; i <= n; ++i) printf("%d ", dfn[i] - 1);
  puts("");
  for (i = 2; i <= n; ++i) ans += d[dfn[i - 1]] - d[fa[dfn[i]]];
  for (i = 2, printf("%d\n", ans); i <= n; ++i)
    for (register int j = d[dfn[i - 1]] - d[fa[dfn[i]]]; j; --j)
      printf("%d ", dfn[i] - 1);
  return 0;
}
