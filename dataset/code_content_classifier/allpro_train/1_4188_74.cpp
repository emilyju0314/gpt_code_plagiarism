#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> ans;
vector<int> cap;
vector<bool> done;
vector<vector<int>> g;
vector<tuple<int, int, int>> edges;
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  edges.resize(m);
  ans.resize(m);
  cap.resize(n + 1);
  done.resize(m);
  for (int i = 0; i < m; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    edges[i] = make_tuple(u, v, c);
    g[u].emplace_back(i);
    g[v].emplace_back(i);
    cap[u] += c;
    cap[v] += c;
  }
  multiset<pair<int, int>> ms;
  ms.emplace(0, 1);
  while (ms.size()) {
    auto [_, u] = *ms.begin();
    ms.erase(ms.begin());
    if (_ != 0) continue;
    if (u == n) break;
    for (auto e : g[u]) {
      if (not done[e]) {
        done[e] = true;
        auto [x, y, c] = edges[e];
        int v = x + y - u;
        ans[e] = (u == y);
        cap[v] -= 2 * c;
        ms.emplace(cap[v], v);
      }
    }
  }
  for (auto x : ans) cout << x << '\n';
}
