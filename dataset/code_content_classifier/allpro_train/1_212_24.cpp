#include <bits/stdc++.h>
using namespace std;
const int N = 100003;
int n, m;
vector<int> g[N], U, V;
int col[N];
bool vis[N];
bool dfs(int i, int c) {
  if (col[i] == c) return 0;
  if (c == 1) col[i] = 2, U.push_back(i);
  if (c == 2) col[i] = 1, V.push_back(i);
  vis[i] = 1;
  bool ans = 1;
  for (int j = 0; j < g[i].size(); ++j) {
    if (vis[g[i][j]])
      if (col[g[i][j]] == col[i])
        return 0;
      else
        continue;
    ans = dfs(g[i][j], col[i]);
    if (!ans) break;
  }
  return ans;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  memset(col, 0, sizeof(col));
  memset(vis, false, sizeof(vis));
  bool ok = 1;
  for (int i = 0; i < n; ++i) {
    if (vis[i + 1]) continue;
    if (!dfs(i + 1, 1)) {
      ok = 0;
      break;
    }
  }
  if (ok) {
    cout << V.size() << "\n";
    for (auto v : V) cout << v << " ";
    cout << "\n";
    cout << U.size() << "\n";
    for (auto u : U) cout << u << " ";
    cout << "\n";
  } else
    cout << "-1\n";
  return 0;
}
