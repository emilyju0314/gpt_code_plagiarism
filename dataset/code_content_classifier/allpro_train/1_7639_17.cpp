#include <bits/stdc++.h>
using namespace std;
int s, n, m, t, x, y;
vector<int> ord;
vector<vector<int>> g;
bool vis[200010];
void dfs(int c) {
  vis[c] = true;
  for (auto &v : g[c]) {
    if (!vis[v]) dfs(v);
  }
  ord.push_back(c);
}
int main() {
  std::istream::sync_with_stdio(false);
  cin >> s;
  while (s--) {
    cin >> n >> m;
    vector<pair<int, int>> edges;
    g = vector<vector<int>>(n + 1);
    for (int i = 0; i < m; i++) {
      cin >> t >> x >> y;
      if (t == 1) {
        g[x].push_back(y);
      }
      edges.emplace_back(x, y);
    }
    ord.clear();
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) dfs(i);
    }
    vector<int> pos(n + 1);
    reverse(ord.begin(), ord.end());
    for (int i = 0; i < n; i++) {
      pos[ord[i]] = i;
    }
    bool flag = false;
    for (int i = 1; i <= n; i++) {
      for (auto &v : g[i]) {
        if (pos[i] > pos[v]) flag = true;
      }
    }
    if (flag) {
      cout << "NO" << endl;
      continue;
    } else {
      cout << "YES" << endl;
      for (auto &v : edges) {
        if (pos[v.first] < pos[v.second]) {
          cout << v.first << " " << v.second << endl;
        } else {
          cout << v.second << " " << v.first << endl;
        }
      }
    }
  }
}
