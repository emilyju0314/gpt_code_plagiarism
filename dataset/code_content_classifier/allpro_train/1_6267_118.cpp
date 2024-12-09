#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e2 + 10;
int n, m, match[maxn], ans, node;
bool mark[maxn], e[maxn][maxn];
vector<int> adj[maxn];
bool dfs(int v) {
  for (auto u : adj[v])
    if (u != node && (!match[u] || (!mark[u]++ && dfs(match[u]))))
      return match[u] = v, true;
  return false;
}
int main() {
  cin >> n >> m;
  for (int i = 0, v, u; i < m; ++i) {
    cin >> v >> u;
    adj[v].push_back(u);
    ++e[v][u];
  }
  ans = 4 * maxn;
  for (int i = 1; i <= n; ++i) {
    node = i;
    int k = n - 1 + !e[i][i];
    memset(match, 0, sizeof(match));
    for (int j = 1; j <= n; ++j)
      if (j != i) {
        memset(mark, 0, sizeof(mark));
        k -= dfs(j);
        k += !e[i][j];
        k += !e[j][i];
      }
    for (int j = 1; j <= n; ++j)
      if (j != i)
        for (auto v : adj[j])
          if (match[v] != j && v != i) ++k;
    ans = min(ans, k);
  }
  cout << ans << '\n';
  return 0;
}
