#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

struct UnionFind {
  const int n;
  V<> t; // root ? -sz : par
  UnionFind(int n) : n(n), t(n, -1) {}
  int find(int v) { return t[v] < 0 ? v : t[v] = find(t[v]); }
  void unite(int u, int v) {
    if ((u = find(u)) == (v = find(v))) return;
    if (-t[u] < -t[v]) swap(u, v);
    t[u] += t[v];
    t[v] = u;
  }
  bool same(int u, int v) { return find(u) == find(v); }
  int size(int v) { return -t[find(v)]; }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, k;
  while (cin >> n >> k, n) {
    VV<> a(n, V<>(n));
    for (int j = 0; j < n; ++j) for (int i = 0; i <= j; ++i) {
      cin >> a[i][j];
    }
    auto in = [&](int i, int j) -> bool { return 0 <= i and i <= j and j < n; };
    auto _ = [&](int i, int j) -> int { return i * n + j; };
    auto fn = [&]() -> int {
      UnionFind uf(101);
      auto chk = [](int x, int y) -> bool {
        if (!x or !y) return true;
        return x == y;
      };
      for (int j = 0; j < n; ++j) for (int i = 0; i <= j; ++i) {
        if (in(i, j + 1) and chk(a[i][j], a[i][j + 1])) uf.unite(_(i, j), _(i, j + 1));
        if (in(i + 1, j) and chk(a[i][j], a[i + 1][j])) uf.unite(_(i, j), _(i + 1, j));
        if (in(i + 1, j + 1) and chk(a[i][j], a[i + 1][j + 1])) uf.unite(_(i, j), _(i + 1, j + 1));
        if (!a[i][j]) uf.unite(_(i, j), 100);
      }
      int res = 0;
      for (int j = 0; j < n; ++j) for (int i = 0; i <= j; ++i) if (a[i][j] and uf.find(_(i, j)) == _(i, j)) {
        if (uf.same(_(i, j), 100)) continue;
        if (a[i][j] != k) res += uf.size(_(i, j));
        else res -= uf.size(_(i, j));
      }
      return res;
    };
    int res = -1e9;
    for (int j = 0; j < n; ++j) for (int i = 0; i <= j; ++i) if (!a[i][j]) {
      a[i][j] = k;
      res = max(res, fn());
      a[i][j] = 0;
    }
    cout << res << '\n';
  }
}
