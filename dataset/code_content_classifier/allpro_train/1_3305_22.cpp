#include <bits/stdc++.h>
using namespace std;
using ll = long long;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  while (cin >> n >> m) {
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    int sz = ceil(sqrt(n) - 1e-9);
    vector<int> removed(n + 1);
    vector<int> cycle, independent;
    vector<int> degree(n + 1);
    set<pair<int, int>> que;
    for (int i = 1; i <= n; ++i) {
      degree[i] = g[i].size();
      que.emplace(degree[i], i);
    }
    for (int i = 0; i < sz; ++i) {
      auto [deg, v] = *que.begin();
      while (removed[v]) {
        que.erase(que.begin());
        deg = que.begin()->first;
        v = que.begin()->second;
      }
      if (deg >= sz - 1) {
        vector<int> cycle_position(n + 1, n + 1);
        cycle.push_back(v);
        cycle_position[v] = 0;
        removed[v] = true;
        while (true) {
          bool finish = true;
          for (auto to : g[cycle.back()]) {
            if (!removed[to]) {
              cycle_position[to] = cycle.size();
              cycle.push_back(to);
              removed[to] = true;
              finish = false;
              break;
            }
          }
          if (finish) {
            int pos = cycle.size();
            for (auto to : g[cycle.back()]) {
              pos = min(pos, cycle_position[to]);
            }
            cycle.erase(cycle.begin(), cycle.begin() + pos);
            break;
          }
        }
        break;
      }
      removed[v] = true;
      independent.push_back(v);
      for (auto to : g[v]) {
        if (removed[to]) continue;
        removed[to] = true;
        for (auto toto : g[to]) {
          if (toto != to && toto != v) {
            que.erase(make_pair(degree[toto], toto));
            degree[toto]--;
            que.emplace(degree[toto], toto);
          }
        }
      }
    }
    if (cycle.empty()) {
      assert(independent.size() == sz);
      cout << "1\n";
      for (int i = 0; i < sz; ++i) cout << independent[i] << " ";
    } else {
      assert(cycle.size() >= sz);
      cout << "2\n" << cycle.size() << "\n";
      for (auto e : cycle) cout << e << " ";
    }
    cout << "\n";
  }
}
