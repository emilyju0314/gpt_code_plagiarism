#include <bits/stdc++.h>
using namespace std;
void dfs(vector<bool> &visited, const vector<vector<int>> &graph, int u = 0) {
  visited[u] = 1;
  for (auto v : graph[u])
    if (!visited[v]) dfs(visited, graph, v);
}
void output(const vector<bool> &visited) {
  cout << "Yes\n";
  int j = 0, p = 0, n = static_cast<int>(visited.size());
  for (int u = 0; u < n; u++)
    if (visited[u])
      j++;
    else
      p++;
  cout << j << " " << p << "\n";
  for (int u = 0; u < n; u++)
    if (visited[u]) cout << u + 1 << " ";
  cout << "\n";
  for (int u = 0; u < n; u++)
    if (!visited[u]) cout << u + 1 << " ";
  cout << "\n";
}
void solve() {
  int n, m;
  cin >> n >> m;
  static vector<vector<int>> graph[2];
  static vector<bool> visited[2];
  for (int i = 0; i < 2; i++) {
    graph[i].clear();
    graph[i].resize(n);
    visited[i].clear();
    visited[i].resize(n, 0);
  }
  while (m--) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    graph[0][u].push_back(v);
    graph[1][v].push_back(u);
  }
  dfs(visited[0], graph[0]);
  for (int u = 0; u < n; u++)
    if (!visited[0][u]) {
      output(visited[0]);
      return;
    }
  dfs(visited[1], graph[1]);
  for (int u = 0; u < n; u++)
    if (!visited[1][u]) {
      visited[0].clear();
      visited[0].resize(n, 0);
      dfs(visited[0], graph[0], u);
      output(visited[0]);
      return;
    }
  cout << "No\n";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
