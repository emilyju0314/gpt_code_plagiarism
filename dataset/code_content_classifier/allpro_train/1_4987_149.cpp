#include <bits/stdc++.h>
using namespace std;
inline void err(istringstream *iss) {}
template <typename T, typename... Args>
void err(istringstream *iss, const T &$val, const Args &...args) {
  string $name;
  *iss >> $name;
  if ($name.back() == ',') $name.pop_back();
  cout << $name << " = " << $val << "; ", err(iss, args...);
}
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const ll llinf = (1ll << 61) - 1;
int n, m, K, T, Q, cn;
list<int> g[100005];
int lst[100005];
int lvl[100005], par[100005][25], cc[100005], cci, cnt[100005];
void dfs(const int &u, const int &p, int d) {
  lvl[u] = d, par[u][0] = p, cc[u] = p ? cc[p] : ++cci;
  cnt[u] = 1;
  for (auto &v : g[u])
    if (v != p) {
      dfs(v, u, d + 1);
      cnt[u] += cnt[v];
    }
}
void precalcSparseMatrix(int mnNode, int mxNode) {
  for (int i = 1; i < 25; i++) {
    for (int node = mnNode; node <= mxNode; node++) {
      if (par[node][i - 1] != -1) par[node][i] = par[par[node][i - 1]][i - 1];
    }
  }
}
int lca(int u, int v) {
  if (lvl[v] < lvl[u]) swap(u, v);
  int diff = lvl[v] - lvl[u];
  for (int i = 0; i < 25; i++)
    if ((diff >> i) & 1) v = par[v][i];
  if (u == v) return u;
  for (int i = 25 - 1; i >= 0; i--)
    if (par[u][i] != par[v][i]) u = par[u][i], v = par[v][i];
  return par[u][0];
}
int main() {
  cin.tie(NULL);
  scanf("%d%d%d%d", &n, &m, &K, &Q);
  for (int i = 0; i < K; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (lst[b]) par[a][0] = lst[b], g[lst[b]].push_back(a);
    lst[b] = a;
  }
  for (int i = 1; i <= n; i++) {
    if (!par[i][0]) dfs(i, 0, 0);
  }
  precalcSparseMatrix(1, n);
  while (Q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d\n", cc[x] == cc[lst[y]] and lca(x, lst[y]) == x ? cnt[x] : 0);
  }
  return 0;
}
