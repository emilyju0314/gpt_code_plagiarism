#include <bits/stdc++.h>
using namespace std;
namespace SCC {
const int N = 100050;
int dfn[N], low[N], id[N], st[N], _st, _, cc;
void dfs(int c, vector<int> g[]) {
  dfn[c] = low[c] = ++cc;
  st[_st++] = c;
  for (auto t : g[c])
    if (!dfn[t])
      dfs(t, g), low[c] = min(low[c], low[t]);
    else if (!id[t])
      low[c] = min(low[c], dfn[t]);
  if (low[c] == dfn[c]) {
    ++_;
    do {
      id[st[--_st]] = _;
    } while (st[_st] != c);
  }
}
vector<int> ng[N];
int solve(int n, vector<int> g[]) {
  fill_n(dfn, n, cc = 0);
  fill_n(low, n, _st = 0);
  fill_n(id, n, _ = 0);
  for (int i = (0); i < (n); i++)
    if (!dfn[i]) dfs(i, g);
  for (int i = (0); i < (n); i++) --id[i];
  fill_n(ng, _, vector<int>());
  for (int i = (0); i < (n); i++)
    for (auto j : g[i])
      if (id[i] != id[j]) ng[id[i]].push_back(id[j]);
  return _;
}
}  // namespace SCC
const int N = 2020;
int n;
vector<int> g[N];
int main() {
  while (~scanf("%d", &n)) {
    for (int i = (0); i < (n + 1); i++) g[i].clear();
    for (int i = (0); i < (n); i++)
      for (int j = (0); j < (n); j++) {
        int x;
        scanf("%d", &x);
        if (x) g[i].push_back(j);
      }
    int ans = SCC::solve(n, g);
    printf("%s\n", ans == 1 ? "YES" : "NO");
  }
  return 0;
}
