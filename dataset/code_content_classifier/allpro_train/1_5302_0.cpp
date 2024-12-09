#include <bits/stdc++.h>
const int N = 2e5 + 10, M = 2e6 + 10;
template <typename T = int>
inline T read() {
  T x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f ? -x : x;
}
int tot, w[N], vis[N], d[N], u[M], v[M], fir[N], nex[M], got[M], tak[M];
inline void AddEdge(int u, int v) {
  nex[++tot] = fir[u], fir[u] = tot, got[tot] = v, tak[tot] = 1;
}
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= m; ++i) {
    int u = read(), v = read();
    ::u[i] = u, ::v[i] = v;
    AddEdge(std::max(u, v), std::min(u, v)), ++d[u], ++d[v];
  }
  for (int i = 1; i <= n; ++i) w[i] = 0;
  for (int u = 1; u <= n; ++u) {
    int res = 0;
    for (int i = fir[u]; i; i = nex[i])
      if (!w[got[i]]) w[got[i]]++, tak[i]--, --d[u];
    for (int i = fir[u]; i; i = nex[i]) vis[d[got[i]]] = true;
    for (int i = fir[u]; i; i = nex[i]) {
      if (!vis[d[u]]) break;
      w[got[i]]--, tak[i]++, ++d[u];
    }
    for (int i = fir[u]; i; i = nex[i]) vis[d[got[i]]] = false;
  }
  std::vector<int> ans;
  for (int i = 1; i <= n; ++i)
    if (w[i]) ans.push_back(i);
  printf("%d\n", ans.size());
  for (auto u : ans) printf("%d ", u);
  if (ans.size()) puts("");
  for (int i = 1; i <= m; ++i) printf("%d %d %d\n", u[i], v[i], tak[i]);
  return 0;
}
