#include <bits/stdc++.h>
const int MOD = (int)1e9 + 7;
const int kN = 100000 + 5;
std::vector<std::pair<int, int>> edges[kN];
int n;
bool vis[kN];
int parent[kN];
int sz[kN];
int que[kN];
int balance[kN];
int weight[kN], color[kN];
int result;
namespace solver {
int inv(int x) {
  return x == 1 ? 1 : (MOD - MOD / x) * 1ll * inv(MOD % x) % MOD;
}
std::vector<std::tuple<int, int, int>> vec;
struct Fenwick {
  int prod[kN];
  int count[kN];
  int n;
  void init(int _n) {
    n = _n;
    std::fill(prod, prod + n, 1);
    std::fill(count, count + n, 0);
  }
  void modify(int at, int p, int c) {
    for (int i = at; i >= 0; i -= ~i & i + 1) {
      prod[i] = prod[i] * 1ll * p % MOD;
      count[i] += c;
    }
  }
  std::pair<int, int> query(int at) {
    int p = 1, c = 0;
    for (int i = at; i < n; i += ~i & i + 1) {
      p = p * 1ll * prod[i] % MOD;
      c += count[i];
    }
    return std::make_pair(p, c);
  }
} bit;
void dfs(int u, int fa, int white, int black, int val) {
  vec.emplace_back(2 * white - black, 2 * black - white, val);
  for (auto e : edges[u]) {
    int v = e.first;
    int id = e.second;
    if (v == fa || vis[v]) continue;
    dfs(v, u, white + (color[id] == 0), black + (color[id] == 1),
        val * 1ll * weight[id] % MOD);
  }
}
void calc(int root, int fa, int white, int black, bool inverse, int slot) {
  vec.clear();
  dfs(root, fa, 0, 0, 1);
  std::sort(vec.begin(), vec.end());
  int tot = vec.size();
  std::vector<int> ss;
  for (int i = 0; i < tot; ++i) ss.emplace_back(std::get<1>(vec[i]));
  std::sort(ss.begin(), ss.end());
  ss.erase(std::unique(ss.begin(), ss.end()), ss.end());
  bit.init(ss.size());
  for (int i = 0, j = tot - 1; i < tot; ++i) {
    while (j > i &&
           std::get<0>(vec[i]) + std::get<0>(vec[j]) + 2 * white - black >= 0) {
      int at = std::lower_bound(ss.begin(), ss.end(), std::get<1>(vec[j])) -
               ss.begin();
      bit.modify(at, std::get<2>(vec[j]), 1);
      --j;
    }
    while (j < i) {
      ++j;
      int at = std::lower_bound(ss.begin(), ss.end(), std::get<1>(vec[j])) -
               ss.begin();
      bit.modify(at, inv(std::get<2>(vec[j])), -1);
    }
    int at = std::lower_bound(ss.begin(), ss.end(),
                              0 - (std::get<1>(vec[i]) + 2 * black - white)) -
             ss.begin();
    int p, c;
    std::tie(p, c) = bit.query(at);
    int v = std::get<2>(vec[i]) * 1ll * slot % MOD;
    int f = p;
    while (c) {
      if (c & 1) f = f * 1ll * v % MOD;
      v = v * 1ll * v % MOD;
      c >>= 1;
    }
    if (inverse) {
      f = inv(f);
    } else {
    }
    result = result * 1ll * f % MOD;
  }
}
void solve(int root) {
  calc(root, -1, 0, 0, false, 1);
  for (auto e : edges[root]) {
    int u = e.first;
    int id = e.second;
    if (vis[u]) continue;
    int w = weight[id] * 1ll * weight[id] % MOD;
    if (color[id] == 0)
      calc(u, root, 2, 0, true, w);
    else
      calc(u, root, 0, 2, true, w);
  }
}
}  // namespace solver
int bfs(int source, int fa = -1) {
  int qf = 0, qe = 0;
  que[qe++] = source;
  parent[source] = fa;
  while (qf != qe) {
    int u = que[qf++];
    sz[u] = 1;
    balance[u] = 0;
    for (auto e : edges[u]) {
      int v = e.first;
      if (!vis[v] && parent[u] != v) {
        parent[v] = u;
        que[qe++] = v;
      }
    }
  }
  for (int i = qe - 1; i >= 0; --i) {
    int u = que[i];
    if (i) {
      sz[parent[u]] += sz[u];
      balance[parent[u]] = std::max(balance[parent[u]], sz[u]);
    }
    balance[u] = std::max(balance[u], qe - sz[u]);
  }
  return qe;
}
void divide(int root) {
  int tot = bfs(root);
  for (int i = tot - 1; i > 0; --i) {
    int u = que[i];
    if (balance[u] < balance[root]) {
      root = u;
    }
  }
  bfs(root);
  solver::solve(root);
  vis[root] = true;
  for (auto e : edges[root]) {
    int u = e.first;
    if (!vis[u]) {
      divide(u);
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b, w, c;
    scanf("%d%d%d%d", &a, &b, &w, &c);
    --a;
    --b;
    weight[i] = w;
    color[i] = c;
    edges[a].emplace_back(b, i);
    edges[b].emplace_back(a, i);
  }
  result = 1;
  divide(0);
  printf("%d\n", result);
}
