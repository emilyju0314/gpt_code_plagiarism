#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> G;
vector<int> max_h;
vector<int> ver;
int ans_len = 0, ans_a, ans_b, ans_c;
void dfs(int v, int p = -1) {
  max_h[v] = 0;
  ver[v] = v;
  for (auto &u : G[v]) {
    if (u != p) {
      dfs(u, v);
      if (max_h[v] < max_h[u] + 1) {
        max_h[v] = max_h[u] + 1, ver[v] = ver[u];
      }
    }
  }
}
void dfs_ans(int v, int p = -1, pair<int, int> go_up = {-1, -1}) {
  vector<pair<int, int>> go;
  for (auto &u : G[v]) {
    if (u != p) {
      go.emplace_back(max_h[u] + 1, ver[u]);
    } else {
      go.push_back(go_up);
    }
  }
  go.emplace_back(0, v);
  if (go.size() >= 3) {
    nth_element(go.begin(), go.end() - 3, go.end());
    int sz = go.size();
    if (ans_len < go[sz - 1].first + go[sz - 2].first + go[sz - 3].first) {
      ans_len = go[sz - 1].first + go[sz - 2].first + go[sz - 3].first;
      ans_a = go[sz - 1].second, ans_b = go[sz - 2].second,
      ans_c = go[sz - 3].second;
    }
    sort(go.end() - 3, go.end());
  } else {
    sort(go.begin(), go.end());
  }
  for (auto &u : G[v]) {
    if (u != p)
      if (go.back().second == ver[u])
        dfs_ans(u, v, {go[go.size() - 2].first + 1, go[go.size() - 2].second});
      else
        dfs_ans(u, v, {go.back().first + 1, go.back().second});
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  G.resize(n), max_h.resize(n), ver.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v, u--, v--;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  dfs(0);
  dfs_ans(0);
  cout << ans_len << '\n' << ans_a + 1 << ' ' << ans_b + 1 << ' ' << ans_c + 1;
}
