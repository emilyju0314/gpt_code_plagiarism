#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
struct Edge {
  int a, b;
  int id;
  void read(int i) {
    id = i;
    scanf("%d%d", &a, &b);
    --a;
    --b;
  }
  int to(int v) const {
    assert(v == a || v == b);
    return (a ^ b) ^ v;
  }
};
int n, m;
vector<int> c;
vector<Edge> g[MAXN];
bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return 0;
  }
  for (int i = 0; i < int(n); ++i) {
    g[i].clear();
  }
  c.resize(n);
  for (int i = 0; i < int(n); ++i) {
    scanf("%d", &c[i]);
  }
  for (int i = 0; i < int(m); ++i) {
    Edge e;
    e.read(i);
    g[e.a].push_back(e);
    g[e.b].push_back(e);
  }
  return 1;
}
vector<int> in_tree;
void dfs0(int v, int p, vector<int>& was, vector<int>& depth, int& root) {
  assert(!was[v]);
  was[v] = 1;
  for (const auto& e : g[v]) {
    const int to = e.to(v);
    if (to == p) {
      continue;
    }
    if (was[to]) {
      const int dist = abs(depth[v] - depth[to]);
      if (dist % 2 == 0) {
        root = v;
      }
      continue;
    }
    in_tree[e.id] = 1;
    depth[to] = depth[v] + 1;
    dfs0(to, v, was, depth, root);
  }
}
int getRoot() {
  vector<int> was(n, 0);
  vector<int> depth(n, 0);
  int root = -1;
  dfs0(0, -1, was, depth, root);
  return root;
}
void dfs1(int v, int p, vector<int>& was, vector<long long>& w,
          vector<Edge>& par, vector<int>& depth) {
  assert(!was[v]);
  was[v] = 1;
  long long sum = 0;
  for (const auto& e : g[v]) {
    const int to = e.to(v);
    if (to == p) {
      continue;
    }
    if (was[to]) {
      continue;
    }
    par[to] = e;
    depth[to] = depth[v] + 1;
    dfs1(to, v, was, w, par, depth);
    sum += w[e.id];
  }
  if (par[v].id == -1) {
    assert(p == -1);
    assert(depth[v] == 0);
    const long long diff = c[v] - sum;
    assert(diff % 2 == 0);
    const long long need = diff / 2;
    for (const auto& e : g[v]) {
      const int to = e.to(v);
      const int dist = depth[to];
      assert(dist > 0);
      if (dist % 2 == 1) {
        continue;
      }
      w[e.id] = need;
      int u = to;
      int parity = 1;
      while (u != v) {
        w[par[u].id] += (parity ? -1 : +1) * need;
        parity ^= 1;
        u = par[u].to(u);
      }
      assert(parity == 1);
      {
        for (int u = 0; u < int(n); ++u) {
          long long sum = 0;
          for (const auto& e : g[u]) {
            sum += w[e.id];
          }
          assert(sum == c[u]);
        }
      }
      break;
    }
  } else {
    w[par[v].id] = c[v] - sum;
  }
}
bool solve() {
  in_tree.assign(m, 0);
  int root = getRoot();
  for (int v = 0; v < int(n); ++v) {
    sort(begin(g[v]), end(g[v]), [&](const Edge& e1, const Edge& e2) {
      return in_tree[e1.id] > in_tree[e2.id];
    });
  }
  bool must_ok = 1;
  if (root == -1) {
    must_ok = 0;
    root = 0;
  }
  vector<int> was(n, 0);
  vector<long long> w(m, 0);
  vector<Edge> par(n, Edge{-1, -1, -1});
  vector<int> depth(n, 0);
  dfs1(root, -1, was, w, par, depth);
  for (int v = 0; v < int(n); ++v) {
    long long sum = 0;
    for (const auto& e : g[v]) {
      sum += w[e.id];
    }
    if (sum != c[v]) {
      assert(!must_ok);
      return 0;
    }
  }
  puts("YES");
  for (int i = 0; i < int(m); ++i) {
    printf("%lld\n", w[i]);
  }
  printf("\n");
  return 1;
}
int main() {
  while (read()) {
    if (!solve()) {
      puts("NO");
    }
  }
  return 0;
}
