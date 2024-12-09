#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

struct Edge { int to, cost; };

template<class T, class Edge> V<T> dijkstra(const VV<Edge>& g, int s = 0) {
  V<T> dist(g.size(), numeric_limits<T>::max());
  using P = pair<T, int>;
  priority_queue< P, V<P>, greater<P> > pque;
  pque.emplace(dist[s] = 0, s);
  while (!pque.empty()) {
    T d; int v;
    tie(d, v) = pque.top(); pque.pop();
    if (d > dist[v]) continue;
    for (const auto& e : g[v]) if (dist[v] + e.cost < dist[e.to]) {
      pque.emplace(dist[e.to] = dist[v] + e.cost, e.to);
    } 
  }
  return dist;
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m, k; cin >> n >> m >> k;
  V<> p(n); for (auto&& e : p) cin >> e;
  V<> c(n); for (auto&& e : c) cin >> e, --e;
  V<> q(n); for (auto&& e : q) cin >> e;
  VV<Edge> g(2 * n);
  while (m--) {
    int u, v, c; cin >> u >> v >> c, --u, --v;
    g[u].push_back(Edge{v, c});
    g[v].push_back(Edge{u, c});
    g[n + u].push_back(Edge{n + v, c});
    g[n + v].push_back(Edge{n + u, c});
  }
  constexpr int o = 1e9;
  for (int v = 0; v < n; ++v) {
    g[v].push_back(Edge{n + v, o - p[v]});
  }
  auto d = dijkstra<lint>(g);
  V<lint> res(k, -9e18);
  for (int v = 0; v < n; ++v) {
    res[c[v]] = max(res[c[v]], o + q[v] - d[n + v] - d[v]);
  }
  for (lint e : res) cout << e << '\n';
}
