#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int N = 200010;
int n;
vector<int> g[N];
int fa[N], d[N], tp[N], f[N];
bool ud[N];
inline void dfs(int u) {
  g[u].erase(remove(g[u].begin(), g[u].end(), fa[u]), g[u].end());
  for (int i = 0; i < g[u].size(); i++)
    d[g[u][i]] = d[u] + 1, fa[g[u][i]] = u, dfs(g[u][i]);
  tp[u] = g[u].size() == 1 ? tp[g[u][0]] : u;
}
inline int G(int, int);
inline int F(int u) {
  if (ud[u]) return f[u];
  ud[u] = 1;
  int v = tp[u], s = d[v] - d[u] + 1;
  if (!g[v].size()) return f[u] = (s & 1) ? 0 : s / 2;
  int a = g[v][0], b = g[v][1];
  for (int i = 0; i <= 1; i++, a ^= b ^= a ^= b) {
    int d1 = s;
    if (g[a].size() <= 1) {
      if (!g[tp[a]].size()) {
        int d2 = d[tp[a]] - d[a] + 1;
        if (!(d1 + d2 & 1)) {
          if (d2 <= d1) (f[u] += F(b)) %= MOD;
          if (d2 <= d1 - 2) (f[u] += F(b)) %= MOD;
        }
      }
      if ((d1 & 1) && g[a].size() == 1) (f[u] += G(b, g[a][0])) %= MOD;
    } else {
      if (!g[tp[g[a][0]]].size()) {
        int d2 = d[tp[g[a][0]]] - d[a] + 1;
        if (!(d1 + d2 & 1) && d2 <= d1) (f[u] += G(b, g[a][1])) %= MOD;
      }
      if (!g[tp[g[a][1]]].size()) {
        int d2 = d[tp[g[a][1]]] - d[a] + 1;
        if (!(d1 + d2 & 1) && d2 <= d1) (f[u] += G(b, g[a][0])) %= MOD;
      }
    }
  }
  return f[u];
}
inline int G(int u, int v) {
  if (g[u].size() == 1 && g[v].size() == 1)
    return G(g[u][0], g[v][0]);
  else if (g[u].size() == 1 && g[v].size() == 0)
    return F(g[u][0]);
  else if (g[u].size() == 0 && g[v].size() == 1)
    return F(g[v][0]);
  else if (g[u].size() == 0 && g[v].size() == 0)
    return 1;
  else
    return 0;
}
inline int calc(int a, int b, int c) {
  if (!g[a].size())
    return 1ll * F(b) * F(c) % MOD;
  else if (g[a].size() == 1)
    return (1ll * G(b, g[a][0]) * F(c) + 1ll * G(c, g[a][0]) * F(b)) % MOD;
  else
    return (1ll * G(b, g[a][0]) * G(c, g[a][1]) +
            1ll * G(b, g[a][1]) * G(c, g[a][0])) %
           MOD;
}
inline int O_O() {
  if (n == 1) return 2;
  int t = 0;
  for (int i = 1; i <= 2 * n; i++) {
    if (g[i].size() > 3) return 0;
    if (g[i].size() == 3) t = i;
  }
  if (!t) return (2ll * n * (n - 1) + 4) % MOD;
  d[t] = 1;
  dfs(t);
  bool flg = 1;
  int res = 0;
  for (sort(g[t].begin(), g[t].end()); flg;
       flg = next_permutation(g[t].begin(), g[t].end()))
    res = (res + calc(g[t][0], g[t][1], g[t][2])) % MOD;
  return res * 2ll % MOD;
}
int main() {
  scanf("%d", &n);
  for (int i = 1, u, v; i < 2 * n; i++)
    scanf("%d%d", &u, &v), g[u].push_back(v), g[v].push_back(u);
  printf("%d\n", O_O());
  return 0;
}
