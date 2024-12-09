#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
vector<int> sz, mx;
vector<vector<int> > gr;
void dfs(int v, int p = -1) {
  sz[v] = 1;
  for (auto to : gr[v])
    if (to != p) {
      dfs(to, v);
      sz[v] += sz[to];
      mx[v] = max(mx[v], sz[to]);
    }
}
int find_leaf(int v, int p = -1) {
  if (gr[v].size() == 1) return v;
  for (auto to : gr[v])
    if (to != p) return find_leaf(to, v);
}
void solve() {
  int n;
  cin >> n;
  sz.clear();
  mx.clear();
  gr.clear();
  sz.resize(n);
  gr.resize(n);
  mx.resize(n);
  for (int i = 1; i < n; ++i) {
    int v, u;
    cin >> v >> u;
    --v;
    --u;
    gr[v].push_back(u);
    gr[u].push_back(v);
  }
  vector<int> c;
  dfs(0);
  for (int i = 0; i < n; ++i) {
    mx[i] = max(mx[i], n - sz[i]);
  }
  for (int i = 0; i < n; ++i) {
    if (mx[i] <= n / 2) {
      c.push_back(i);
    }
  }
  debug() << " ["
          << "mx"
             ": "
          << (mx)
          << "] "
             " ["
          << "c"
             ": "
          << (c) << "] ";
  if (c.size() == 1) {
    cout << 1 << " " << gr[0][0] + 1 << '\n';
    cout << 1 << " " << gr[0][0] + 1 << '\n';
    return;
  }
  int v = c[0], u = c[1];
  int nleaf = find_leaf(v, u);
  cout << nleaf + 1 << " " << gr[nleaf][0] + 1 << '\n';
  cout << nleaf + 1 << " " << u + 1 << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int q = 1;
  cin >> q;
  while (q--) solve();
}
